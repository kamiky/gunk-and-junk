##
## Makefile for Makefile in /home/krik/work/philosophes_unix/trunk/
##
## Made by patrick rabier
## Login   <rabier_p@epitech.net>
##
## Started on  Wed May  4 10:07:58 2011 patrick rabier
## Last update Sat May 14 11:01:57 2011 Patrick Rabier
##

NAME 	= libclist.a


SRCS	= 	construction.c \
		destruction.c \
		foreach.c \
		append.c

CFLAGS  = -W -Wall
LFLAGS	=
OBJS 	= $(SRCS:.c=.o)


all	: $(NAME)


$(NAME)	: $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean	:
	$(RM) $(OBJS) *~


fclean	: clean
	$(RM) $(NAME)


re	: fclean all

.PHONY	: all clean fclean re
