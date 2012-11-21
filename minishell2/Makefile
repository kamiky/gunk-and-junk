##
## Makefile for Makefile in /home/issouf_b//minishell
## 
## Made by benaly issouf-m-sa
## Login   <issouf_b@epitech.net>
## 
## Started on  Fri Nov 12 14:45:35 2010 benaly issouf-m-sa
## Last update Sun Dec  5 21:09:15 2010 benaly issouf-m-sa
##

NAME=	mysh

SRC=	my_str_to_wordtab.c \
	mysh.c \
	build_ch.c \
	cmp_path.c \
	my_show_to_wordtab.c \
	change_rep.c \
	go_home.c \
	choice.c \
	check.c \
	my_env.c \
	mk_exit.c \
	my_getnbr.c \
	error_ch.c \
	display.c \
	check_signe.c \
	mk_redir_or_pip.c \
	redir.c \
	mk_pip_inf.c

OBJ=	$(SRC:.c=.o)

CFLAGS = -W -Wall -ansi -pedantic

LDFLAGS = 

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ)

all:	$(NAME) clean

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean $(NAME)

.PHONY : $(NAME) all clean fclean re