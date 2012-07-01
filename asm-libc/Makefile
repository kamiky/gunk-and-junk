NAME = libasm.so

SRCS =	rindex.s	\
	memcpy.s	\
	memmove.s	\
	memset.s	\
	strchr.s	\
	strcmp.s	\
	strlen.s	\
	write.s		\
	read.s		\
	strncmp.s	\
	strcasecmp.s	\
	strcspn.s	\
	strstr.s

OBJS = $(SRCS:.s=.o)

CC = gcc
CFLAGS = -shared -fPIC -W -Wall
AS = ./nasm -f elf
RM = rm -f

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all	: $(NAME)

clean	: 
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all