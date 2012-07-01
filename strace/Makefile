NAME=test
ASM=nasm
LD=gcc
SRC=test.s
OBJ=$(SRC:.s=.o)
LDFLAGS=-fno-builtin
CFLAGS=-f elf

.s.o	:
	$(ASM) $(CFLAGS) $< -o $@

$(NAME)	: $(OBJ)
	$(LD) $(OBJ) -o $(NAME) $(LDFLAGS)

all	: $(NAME)

clean	:
	rm -f $(OBJ)

fclean	: clean
	rm -f $(NAME)