JSON_TEST =
{
    "Number1" : 422,
    "Number2" : 32.24,
    "Str1" : "Blob",
    "Str2" : "World",
    "branch1" : {
	"Number3" : 42132,
	"Number4" : 332.21234,
	"Str3" : "nuuu",
	"Str4" : "plop",
	"branch2": {
	    "yolo":"branching like a boss"
	}
    }
};


//------------------
// Branch
//------------------
var Branch = function(title)
{

    this.branches = new Array();
    this.nodes = new Array();

    // Dom element
    this.root = document.createElement("ul");
    this.title = title;
}

Branch.prototype.AddSubbranch = function(branch)
{
    if (branch)
	this.branches.push(branch);
}

Branch.prototype.AddNode = function(element)
{
    var node = new Node(element);
    if (node.data)
    {
	this.nodes.push(node);
    }
}

Branch.prototype.FromJSON = function(json)
{
    for(var key in json)
    {
	var value = json[key];

	console.log(value);

	if (typeof value == "object")
	{
	    if (isElement(value))
		this.AddNode(value);
	    else
	    {
		var subbranch = new Branch(key);
		subbranch.FromJSON(value);
		this.AddSubbranch(subbranch);
	    }
	    continue;
	}
	else
	    this.AddNode(value);
   }
}


Branch.prototype.Update = function()
{
    while (this.root.hasChildNodes())
	this.root.removeChild(this.root.firstChild);

    for(var node_key in this.nodes)
    {
	var node = this.nodes[node_key];

	if (!node.data) continue;

	var li = document.createElement("li");
	li.appendChild(node.data);
	console.log(li);
	this.root.appendChild(li);
    }

}

Branch.prototype.AppendToElement = function(element)
{
    if (!element)
	return;

    if (this.root.parentNode)
	this.root.parentNode.removeChild(this.root);
    element.appendChild(this.root);

}

//----------------
// Nodes
//----------------

var Node = function(data)
{
    this.data = null;

    if (!data)
	return;

    if (isElement(data))
	this.data = data;
    else if (typeof data == "string")
	this.data = document.createTextNode(data);
    else if (typeof data == "number")
	this.data = document.createTextNode(data.toString());
}


//-------------
// TreeView
//--------------

var TreeView = Branch;


///////////////

function isElement(o){
    return (
	typeof HTMLElement === "object" ? o instanceof HTMLElement : //DOM2
	o && typeof o === "object" && o.nodeType === 1 && typeof o.nodeName==="string"
    );
}

window.onload = function()
{
    var tv = new TreeView("Test");

    tv.AppendToElement(document.body);
    tv.FromJSON(JSON_TEST);

    var elem = document.createElement("div");
    elem.style.background = "red";
    elem.style.width = "100px";
    elem.style.height = "10px";

    tv.AddNode(elem);

    tv.Update();

}
