/*
** my_str_wordtab.c for my_str_to_wordtab in /home/issouf_b/
** 
** Made by benaly issouf-m-sa
** Login   <issouf_b@epitech.net>
** 
** Started on  Tue Nov  9 17:29:24 2010 benaly issouf-m-sa
** Last update Sun Dec  5 21:10:52 2010 benaly issouf-m-sa
*/

#include <stdlib.h>
#include "mysh.h"

int	cpt(char *str, char sep)
{
  int	i;
  int	c;

  c = 0;
  i = 0;
  while (str[i] != '\0')
    {
      while (str[i] == sep && str[i] != '\0')
	i = i + 1;
      while (str[i] != sep && str[i] != '\0')
	i = i + 1;
      c = c + 1;
    }
  return (c);
}

char	*my_strcpy(char *str, int pos, int first)
{
  char	*dest;
  int	i;

  pos = pos - first;
  dest = malloc(sizeof(*dest) * (pos + 1));
  i = 0;
  while (i < pos)
    {
      dest[i] = str[first];
      i = i + 1;
      first = first + 1;
    }
  dest[i] = '\0';
  return (dest);
}

char	**my_init(char **cmd, int size)
{
  cmd[size] = (char*)0;
  return (cmd);
}

char	**my_str_to_wordtab(char *str, int i, int j, int size)
{
  int	x;
  char	**cmd;

  cmd = malloc(sizeof(*cmd) * (cpt(str, ' ') + 1));
  while (str[i] != '\0')
    {
      while ((str[i] != '\0') && (str[i] == ' '))
        i = i + 1;
      if (str[i] == '\0')
	return (my_init(cmd, size));
      x = j;
      while (str[i + x] != '\0' && str[i + x] != ' ') 
        x = x + 1;
      cmd[size] = malloc(sizeof(**cmd) * (x + 1));
      while (str[i] != '\0' && str[i] != ' ')
        {
          cmd[size][j] = str[i];
          j = j + 1;
          i = i + 1;
        }
      cmd[size][j] = '\0';
      size = size + 1;
      j = 0;
    }
  return (my_init(cmd, size));
}
