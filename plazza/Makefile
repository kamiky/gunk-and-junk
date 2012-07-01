##
## Makefile for d07 in /home/gatty_s//projets/cpp/d07/ex_0
##
## Made by sebastien gatty
## Login   <gatty_s@epitech.net>
##
## Started on  Mon Jan 10 10:06:53 2011 sebastien gatty
## Last update Thu Apr 14 18:40:29 2011 vincent hugues
## Last update Tue Apr 12 13:13:57 2011 sebastien gatty
##

CXX      = g++
CXXFLAGS += -W -Wall -Wextra -lpthread -I./include $(SFMLFLAGS)
LDFLAGS  +=
SFMLFLAGS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

NAME  = plazza
SRC   = main.cpp			\
	Menu.cpp			\
	Waiter.cpp			\
	Cook.cpp			\
	Recipe.cpp			\
	Kitchen.cpp			\
	Showcase.cpp			\
	Reception.cpp			\
	PlazzaException.cpp		\
	$(wildcard threads_util/*.cpp)

OBJ   = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
