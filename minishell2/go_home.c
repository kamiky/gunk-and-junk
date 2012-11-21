/*
** go_home.c for go_home in /home/issouf_b//minishell1
** 
** Made by benaly issouf-m-sa
** Login   <issouf_b@epitech.net>
** 
** Started on  Sat Nov 13 11:37:43 2010 benaly issouf-m-sa
** Last update Sun Dec  5 21:00:03 2010 benaly issouf-m-sa
*/

#include <stdlib.h>
#include <unistd.h>
#include "mysh.h"

int	check_user(char *use, char **env)
{
  int	i;
  int	j;
  int	rep;
  char	*cmp;

  cmp = use;
  i = 0;
  rep = 0;
  while (env[i] != 0 && rep != 1)
    {
      j = 0;
      while (env[i][j] == cmp[j] && env[i][j] != '\0')
	{
	  if (env[i][j] == cmp[3])
	    rep = 1;
	  j = j + 1;
	}
      i = i + 1;
    }
  return (i - 1);
}

char	*go_home(char **env)
{
  int	i;
  int	j;
  int	x;
  char	*ch;
  int	size;
  
  j = 5;
  x = 0;
  i = check_user("HOME=", env);
  if (env[i] != 0)
    {
      size = my_strlen(env[i]);
      ch = malloc(sizeof(*ch) * (size - 5));
      while (j <= size)
	{
	  ch[x] = env[i][j];
	  x = x + 1;
	  j = j + 1;
	}
      chdir(ch);
    }
  return (ch);
}
