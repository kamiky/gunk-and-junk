/*
** cmp_path.c for cmp_path in /home/issouf_b//minishell
** 
** Made by benaly issouf-m-sa
** Login   <issouf_b@epitech.net>
** 
** Started on  Wed Nov 10 13:37:32 2010 benaly issouf-m-sa
** Last update Sun Dec  5 21:11:44 2010 benaly issouf-m-sa
*/

#include <stdlib.h>
#include "mysh.h"

int     check_path(char *pth, char **env)
{
  int   i;
  int   j;
  int   rep;
  char  *cmp;

  cmp = pth;
  i = 0;
  rep = 0;
  while (env[i] != 0 && rep != 1)
    {
      j = 0;
      while (env[i][j] == cmp[j] && env[i][j] != '\0')
        {
          if (env[i][j] == cmp[4])
            rep = 1;
          j = j + 1;
        }
      i = i + 1;
    }
  return (i - 1);
}

char	**my_path(char *str)
{
  int	i;
  int	j;
  int	size;
  char	**cmd;
  int	a;
 
  size = cpt(str, ':') + 1;
  cmd = malloc(sizeof(*cmd) * size);
  i = 5;
  j = 5;
  a = 0;
  size = 0;
  while (str[i] != '\0')
    {
      while (str[i] != ':' && str[i] != '\0')
	i = i + 1;
      size = i - j + 1;
      cmd[a] = malloc(sizeof(**cmd) * size);
      cmd[a] = my_strcpy(str, i, j);
      j = i + 1;
      a = a + 1;
      if (str[i] != '\0')
	i = i + 1;
    }
  cmd[a] = 0;
  return (cmd);
}
