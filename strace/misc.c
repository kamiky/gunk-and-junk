/*
** misc.c for misc.c in /home/krik/work/strace_unix/
**
** Made by patrick rabier
** Login   <rabier_p@epitech.net>
**
** Started on  Wed May 25 20:08:12 2011 patrick rabier
** Last update Wed May 25 20:08:17 2011 Patrick Rabier
*/

#include "my.h"

int		is_numeric(const char *s)
{
  int		i;

  i = 0;
  while (s[i])
    {
      if (s[i] < '0' || s[i] > '9')
	return (0);
      i++;
    }
  return (1);
}
