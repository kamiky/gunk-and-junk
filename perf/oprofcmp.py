#!/usr/bin/python

# It's the midnight ride ! ;)
# CAREFUL the xml files are huge with opera...will hog lots of memory
# Designed to be used with oprofxml.sh results which generates xml files via oprofile
# Alternatively can be used without the script only if one binary is present
# in the xml (simply specify the binary to opcontrol and opreport), and exclude other modules from the results (rtfm)

from xml.dom.minidom import parse
from collections import defaultdict
import sys, string, re

# use -v option to activate verbose mode
VERBOSE = False
# use --no-callstack to deactivate the load
LOAD_CALLSTACK = True

# TEST, functions we want to ignore in a profile, their caller is usually the most interesting
base_functions = [ "memset", "memcpy" ]

###################################################################################
#
# Loading oprofile's results like a boss... or not
#
# @TODO better error handling
# @TODO load the symbols on demand...not in the constructor
###################################################################################

# Used as a struct
class OprofSymbol:

    def __init__(self):
        self.idref = 0
        self.name = "unamed"
        self.count = 0
        self.percent = 0
        self.stackcomment = ""
        self.callstack = []


    #In case the function is a base function such as malloc, we want the OprofSymbol to take the identity of it's caller
    def becomeCaller(self):
        if (len(self.callstack) > 0):
            if (self.stackcomment == ""):
                self.stackcomment = "Traced from callees "
                self.stackcomment += self.name + "(" + str(self.count) + ")"
            else:
                self.stackcomment += " < " + self.name + "(" + str(self.count) + ")"
            self.name = self.callstack[0].name
            self.count = self.callstack[0].count
            self.percent += self.callstack[0].percent
            self.idref = self.callstack[0].idref
            self.callstack.pop(0)
            return True
        return False



    def dump(self):
        if (VERBOSE == True) :
            print "Symbol " + str(self.idref) + " (" + str(self.count) + " samples / " + str(self.percent) + "%) " + bold(self.name) + " | " + cyan(self.stackcomment)


class OprofResults:


    def __init__(self, filename, max_symbols, sym_reg_exp = None):

        self.symbol_list = []
        self.last_id_ref = -1
        self.total_sample_count = 0
        self.symbols_loaded = 0
        self.symbols_to_load = 0
        if (sym_reg_exp != None):
            self.sym_pattern = re.compile(sym_reg_exp)
        else:
            self.sym_pattern = None

        puts("Loading " + filename)
        self.symbols_to_load = max_symbols

        try:
            dom = parse(filename)
        except Exception, e:
            error("Unable to parse " + filename)
            over_and_out(e)

        binary_node = dom.getElementsByTagName("binary")[0]
        puts("Binary : " + binary_node.getAttribute("name"))

        self.total_sample_count = self.__stripCount(binary_node.getElementsByTagName("count")[0])
        self.__loadSymbols(dom, binary_node)
        self. __checkForBaseFunction()



    # <symbol  idref="0">
    #     <callers>
    #     </callers>
    #     <callees>
    #       <symbol  idref="4">
    #         <count>
    #         6</count>
    #       </symbol>
    #     </callees>
    #     <count>
    #     76787</count>
    #
    #
    # <symboldata  id="0"
    # name="TOTO::Tata(int)"
    # startingaddr="00542b00"/>
    def __loadSymbols(self, dom, binary_node):

        if (dom == None or binary_node == None):
            error("Unable to load symbols")
            exit()
        symbol_nodes = binary_node.getElementsByTagName("symbol")

        #NAME SEARCH
        symboltable = dom.getElementsByTagName("symboltable")[0]
        symboldata_nodes = symboltable.getElementsByTagName("symboldata")

        # The dictionnary is not stored as a class member since it can become a very large object
        # TODO check gc's behavior for local variables
        names = defaultdict()

        for symbol_node in symbol_nodes:
            if (self.symbols_loaded >= self.symbols_to_load):
                break
            if (symbol_node.parentNode.nodeName == "binary"):
                #LOAD SYMBOL
                symbol = OprofSymbol()
                symbol.idref = int(symbol_node.getAttribute("idref"))
                symbol.count = self.__retrieveCorrectCount(symbol_node, symbol.idref)
                if (symbol.count == -1):
                    continue
                symbol.percent = float(float(symbol.count * 100)/float(self.total_sample_count))

                #LOOKUP NAME
                sym_name = self.__lookupName(names, symbol, symboldata_nodes);
                if (self.sym_pattern != None and not(self.sym_pattern.search(self.__getFunctionName(sym_name)))):
                    continue
                symbol.name = sym_name

                self.symbol_list.append(symbol)
                self.symbols_loaded += 1
                if (LOAD_CALLSTACK):
                    # LOAD CALLSTACK
                    caller_nodes = symbol_node.getElementsByTagName("callers")[0].getElementsByTagName("symbol")
                    for caller_node in caller_nodes:
                        if (caller_node.hasAttribute("self")):
                            continue
                        caller = OprofSymbol()
                        caller.idref = int(caller_node.getAttribute("idref"))
                        caller.count = self.__retrieveCorrectCount(caller_node, caller.idref)
                        caller.percent = float(float(caller.count * 100)/float(self.total_sample_count))
                        symbol.callstack.insert(0, caller)

        puts("Symbols Loaded : " + str(len(self.symbol_list)) + "/" + str(self.symbols_to_load))



    def __checkForBaseFunction(self):
        for symbol in self.symbol_list:
            while (LOAD_CALLSTACK and self.__isBaseFunction(symbol)):
                if (not(symbol.becomeCaller())) : break



    def __lookupName(self, names, symbol, symboldata_nodes):
        try :
            self.__name_offset
        except :
            self.__name_offset = 0

        try :
            return names[symbol.idref]
        except:
            while (self.__name_offset < len(symboldata_nodes)):
                # save name in dictionnary
                symboldata_node = symboldata_nodes[self.__name_offset]
                idref = int(symboldata_node.getAttribute("id"))
                names[idref] = symboldata_node.getAttribute("name")
                if (idref == symbol.idref):
                    self.__name_offset += 1
                    return symboldata_node.getAttribute("name")
                self.__name_offset += 1
        return "name missing"



    def __retrieveCorrectCount(self, symbol_node, idref):

        all_counts = symbol_node.getElementsByTagName("count")
        if (len(all_counts) == 1):
            return self.__stripCount(all_counts[0])

        for count_node in all_counts:
            parentNode = count_node.parentNode
            if (parentNode.nodeName != "symbol" or
                int(parentNode.getAttribute("idref")) != idref or parentNode.hasAttribute("self")):
                continue
            return self.__stripCount(count_node)

        return -1


    def __getFunctionName(self, sym_str):
        return string.split(sym_str, "(", 1)[0]



    def __isBaseFunction(self, symbol):
        for f in base_functions:
            if symbol.name == f:
                return True
        return False



    def __stripCount(self, node):
        return int(node.firstChild.data.strip())



    def dump(self):
        if (VERBOSE) :
            for symbol in self.symbol_list:
                symbol.dump()



    def getSymbolList(self):
        return self.symbol_list



    def getSymbol(self, name):
        res = filter(lambda sym: sym.name == name, self.symbol_list)
        if (len(res) == 0):
            return None
        return res[0]


###################################################################################
#
# Comparing oprofile's results like a princess
#
# @TODO improve comparison
###################################################################################

class OprofCmpCase:


    def __init__(self, sym1, sym2):
        self.symbol1 = sym1
        self.symbol2 = sym2
        self.difference = float(sym2.percent - sym1.percent)
        self.relative_difference = (self.difference * 100)/sym1.percent

        #print "DEBUG " + str(self.difference) + " " + str(sym1.percent) + " " + str(sym2.percent)



    def dump(self):
        if (self.relative_difference >= 0):
            rdiffstr = red("+" + str(self.relative_difference) + "%")
        else:
            rdiffstr = blue(str(self.relative_difference) + "%")
        print "Difference : " + bold(str(self.difference) + "%") + " (" +rdiffstr+") [Symbol : " + self.symbol1.name + "]"




class OprofComparator:


    def __init__(self, res1, res2):
        self.cmp_cases = []
        self.new_symbols = []
        self.absent_symbols = []

        if (res1 == None or res2 == None):
            over_and_out("Error : OprofComparator : Empty set")

        symbols1 = res1.getSymbolList()
        symbols2 = res2.getSymbolList()
        if (symbols1 == None or len(symbols1) == 0 or symbols2 == None or len(symbols2) == 0):
            over_and_out("Error : OprofComparator : Empty set")
        for sym2 in symbols2:
            sym1 = res1.getSymbol(sym2.name)
            if (sym1 == None):
                self.new_symbols.append(red("+ ") + str(sym2.percent) + "% " + sym2.name)
            else:
                new_cmp_case = OprofCmpCase(sym1, sym2)
                i = 0
                while (i < len(self.cmp_cases) and abs(self.cmp_cases[i].difference) > abs(new_cmp_case.difference)):
                    i += 1
                self.cmp_cases.insert(i, new_cmp_case)
        for sym1 in symbols1:
            sym2 = res2.getSymbol(sym1.name)
            if (sym2 == None):
                self.absent_symbols.append(blue("- ") + sym1.name)



    def dump(self):
        print "\n"
        print blue("--------------      Comparison    --------------\n")
        print cyan("--------------      [Changes]     --------------\n")
        for cmpcase in self.cmp_cases:
            cmpcase.dump()
        print cyan("\n--------------    [New Symbols]   --------------\n")
        for sym in self.new_symbols:
            print sym
        print cyan("\n--------------   [Absent Symbols]  --------------\n")
        for sym in self.absent_symbols:
            print sym
        print "\n"




# Display fun ;)
# @TODO some completely useless yet awesome ascii art

def color(t, c): return chr(0x1b)+"["+str(c)+"m"+t+chr(0x1b)+"[0m"
def bold(t): return color(t, 1)
def red(t): return color(t, 31)
def blue(t): return color(t, 34)
def cyan(t): return color(t, 36)
def yellow(t): return color(t, 33)
def debug(t): print red(bold(t))
def error(t): print red("Error : ") + t
def over_and_out(s): print(s);exit()
def puts(t):
    if (VERBOSE): print yellow("==") + t



# this is a main... obvious comment is obvious
if __name__ == "__main__":

    max_sym_defined = False
    max_symbols = 0
    reg_exp = None
    count = 0
    file1 = ""
    file2 = ""

    if (len(sys.argv) == 1):
        print "Usage : " + sys.argv[0] + " file1.xml [file2.xml] [-v] [--max-symbols nb] [--no-callstack] [--name exp]"
        print "Specifying 2 xml files will automatically launch a comparison of the two"
        print "Use -v for verbose"
        print "Use --name to specify a regular expression used on the symbol name"
        print "Use --max-symbols to specify the number of symbols you wish to display (ordered by time consumption)"
        print "Use --no-callstack if you do not wish to load the callstack (used for base functions, requires some more work)"
        print "Example :  ./oprofcmp.py -v oprofile.output.10520.xml oprofile.output.11397.xml --name \"VEGA|ES\""
        exit()

    i = 0
    while (i < len(sys.argv)):
        #Bloody argument detection
        if (i == 0):
            i += 1
            continue
        arg = sys.argv[i]
        if (arg[0] != '-'):
            if (count < 2):
                if (count == 0): file1 = arg
                else: file2 = arg
                count += 1
            else: over_and_out("error : too many arguments, 1 or 2 are expected")
        else:
            if (arg == "-v"):
                VERBOSE = True
            elif (arg == "--max-symbols"):
                if (max_symbols != 0) : over_and_out("error : maximum symbols already defined")
                if (i + 1 == len(sys.argv)) : over_and_out("error : missing max symbols value")
                max_symbols = int(sys.argv[i + 1])
                i += 1
            elif (arg == "--name"):
                if (reg_exp != None) :  over_and_out("error : name already defined")
                if (i + 1 == len(sys.argv)) : over_and_out("error : missing name value")
                reg_exp = sys.argv[i+1]
                i += 1
            elif (arg == "--no-callstack"): LOAD_CALLSTACK = False
            else:
                over_and_out("Unknown option " + arg)
        i += 1

    if (count == 0):
        over_and_out("Missing arguments. Usage : " + sys.argv[0] + " file1.xml [file2.xml] [-v] [--max-symbols nb] [--no-callstack] [--name exp]")
    if (max_symbols == 0) : max_symbols = 20
    if (count == 2):
        # COMPARISON
        res1 = OprofResults(file1, max_symbols, reg_exp)
        if (VERBOSE) : res1.dump()
        res2 = OprofResults(file2, max_symbols, reg_exp)
        if (VERBOSE) : res2.dump()
        cmpres = OprofComparator(res1, res2)
        cmpres.dump()
    elif (count == 1):
        # SIMPLE PROFILE
        res1 = OprofResults(file1, max_symbols, reg_exp)
        res1.dump()
