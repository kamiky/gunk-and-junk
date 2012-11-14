##
## Makefile for make in /home/rabier_p/work/PROJ/C/MINISHELL1
## 
## Made by patrick rabier
## Login   <rabier_p@epitech.net>
## 
## Started on  Sun Jan 10 15:20:29 2010 patrick rabier
## Last update Fri Feb 26 15:34:38 2010 patrick rabier
##

NAME	= mysh

SRCS	= minishell.c else.c my_getenv.c seg.c \
	my_str_to_wordtab.c prompt.c cmd_tab.c \
	pipe.c pipe_more.c redir.c redir_gauche_double.c

OBJS	= $(SRCS:.c=.o)

CC	= gcc
LFLAGS	= -L. -lmy_printf_i386-FreeBSD
CFLAGS	= -W -Wall -ansi -pedantic -std=c89
RM	= rm -f

all		: $(NAME)

$(NAME)		: $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LFLAGS)

clean		: 
	$(RM) $(OBJS)

fclean		: clean
	$(RM) $(NAME)

re		: fclean all

.PHONY		: re fclean clean