/*
** getnextline.c for getnextline in /home/rabier_p/work/PROJ/C/GETNEXTLINE/NEW
** 
** Made by patrick rabier
** Login   <rabier_p@epitech.net>
** 
** Started on  Fri Jan  1 05:11:14 2010 patrick rabier
** Last update Thu Feb 25 13:27:02 2010 patrick rabier
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "else.h"

extern char		**environ;

static void		*xmalloc(size_t n)
{
  void		*p;

  p = malloc(n);
  if (p == 0)
    {
      write(1, "Virtual memory exhausted\n", 27);
      exit(1);
    }
  return (p);
}

char			*my_feinte()
{
  char			*str;

  str = xmalloc(2 * sizeof(*str));
  str[0] = ' ';
  str[1] = '\0';
  return (str);
}

int			prompt_feinte(int n, char *buffer)
{
  int			i;

  i = 0;
  while (buffer[i] != '\n' && i != 1024)
    {
      if (i == 1023)
	{
	  my_printf("Ceci est une mauvaise idee 0,0'\n");
	  exit(1);
	}
      n++;
      i++;
    }
  return (n);
}

void			aff_prompt()
{
  static int		p;
  char			*host;
  char			*user;

  host = my_getenv("HOSTTYPE");
  user = my_getenv("USER");
  my_printf("<%s@%s %i>", user, host, ++p);
  free(host);
  free(user);
}

char			*prompt()
{
  char			buffer[1024];
  int			i;
  int			n;
  char			*str;
  
  n = 0;
  i = 0;
  aff_prompt();
  read(0, buffer, 1024);
  if (buffer[0] == '\n' || ctrl(buffer) == -1)
    return (my_feinte());
  n = prompt_feinte(n, buffer);
  str = xmalloc(n * sizeof(*str));
  i = 0;
  while (i < n)
    {
      str[i] = buffer[i];
      i++;
    }
  str[i] = '\0';
  return (str);
}
