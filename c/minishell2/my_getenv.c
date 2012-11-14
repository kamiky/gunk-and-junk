/*
** my_env.c for env in /home/rabier_p/work/PROJ/C/MINISHELL1
** 
** Made by patrick rabier
** Login   <rabier_p@epitech.net>
** 
** Started on  Thu Jan  7 10:46:08 2010 patrick rabier
** Last update Sat Feb 20 14:05:48 2010 patrick rabier
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my_env.h"

extern char		**environ;

static void	*xmalloc(size_t n)
{
  void	*p;

  p = malloc(n);
  if (p == 0)
    {
      write(1, "Virtual memory exhausted\n", 27);
      exit(1);
    }
  return (p);
}

int			check_name(char *name1, char *name2)
{
  int			i;

  i = 0;
  while (name1[i] != '\0')
    {
      if (name1[i] != name2[i])
	return (0);
      i++;
    }
  return (1);
}

char			*my_getenv(char *name)
{
  int			i;
  int			p;
  int			n;
  int			size;
  char			*str;

  size = 1;
  n = 0;
  p = 0;
  i = 0;
  while (environ[i] != NULL && size == 1)
    {
      if (check_name(name, environ[i]))
	 size = 2;
      i++;
    }
  if (size != 2)
    return (" ");
  size = (my_strlen(environ[--i]) - (my_strlen(name) + 1)) + 1;
  str = xmalloc(size * sizeof(*str));
  while (environ[i][n++] != '=');
  while (p <= size)
    str[p++] = environ[i][n++];
  str[p] = '\0';
  return (str);
}

int			my_env()
{
  int			i;

  i = 0;
  while (environ[i] != NULL)
    my_printf("%s\n", environ[i++]);
  return (1);
}
