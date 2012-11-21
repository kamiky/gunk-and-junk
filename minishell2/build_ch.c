/*
** build_ch.c for build_ch in /home/issouf_b//minishell
** 
** Made by benaly issouf-m-sa
** Login   <issouf_b@epitech.net>
** 
** Started on  Wed Nov 10 14:49:20 2010 benaly issouf-m-sa
** Last update Sun Dec  5 21:11:20 2010 benaly issouf-m-sa
*/

#include <stdlib.h>
#include "mysh.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}

char	*build_ch(char *path_c, char *cmd)
{
  char	*dest;
  int	i;
  int	j;
  int	size;
  
  size = my_strlen(path_c) + 1;
  size = size + my_strlen(cmd) + 1;
  dest = malloc(sizeof(*dest) * size);
  i = 0;
  while (path_c[i] != '\0')
    {
      dest[i] = path_c[i];
      i = i + 1;
    }
  dest[i] = '/';
  i = i + 1;
  j = 0;
  while (cmd[j] != '\0')
    {
      dest[i] = cmd[j];
      j = j + 1;
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
