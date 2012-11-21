/*
** check_signe.c for check_signe in /home/issouf_b//tp_pipe
** 
** Made by benaly issouf-m-sa
** Login   <issouf_b@epitech.net>
** 
** Started on  Fri Dec  3 17:14:18 2010 benaly issouf-m-sa
** Last update Sun Dec  5 21:07:21 2010 benaly issouf-m-sa
*/

#include "mysh.h"

int     check_sign(char *s1, char *str, char *s2)
{
  if (s1 && s2)
    {
      if (s2[0] == ';' ||str[0] == '|' || str[0] == '<' || str[0] == '>')
	return (1);
      else if ((str[0] == '<' && str[1] == '<') 
	       || (str[0] == '>' && str[1] == '>'))
	return (1);
    }
  return (0);
}

int     sign(char **str)
{
  int   i;
  int   c;

  i = 1;
  c = 0;
  while (str[i] != 0)
    {
      if (check_sign(str[i - 1], str[i], str[i + 1]) == 1)
        c = c + 1;
      i = i + 1;
    }
  if (c == 0)
    return (0);
  else
    return (1);
}
