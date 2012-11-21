/*
** check.c for check in /home/issouf_b//minishell1
** 
** Made by benaly issouf-m-sa
** Login   <issouf_b@epitech.net>
** 
** Started on  Sat Nov 13 17:16:40 2010 benaly issouf-m-sa
** Last update Sun Dec  5 21:00:55 2010 benaly issouf-m-sa
*/

#include "mysh.h"

int	check_cd(char *str)
{
  int	i;
  char	cmp[3];

  cmp[0] = 'c';
  cmp[1] = 'd';
  i = 0;
  while (str[i] != '\0' && cmp[i] != '\0')
    {
      if (str[i] != cmp[i])
        return (0);
      i = i + 1;
    }
  if (i == 2 && str[i] == '\0')
    return (1);
  else
    return (0);
}

int	set(char *str)
{
  int	i;
  char	cmp[7] = {'s', 'e', 't', 'e', 'n', 'v'};

  i = 0;
  while (str[i] != '\0' && cmp[i] != '\0')
    {
      if (str[i] != cmp[i])
        return (0);
      i = i + 1;
    }
  if (i == 6 && str[i] == '\0')
    return (1);
  else
    return (0);
}

int	unset(char *str)
{
  int	i;
  char	cmp[9] = {'u', 'n', 's', 'e', 't', 'e', 'n', 'v'};

  i = 0;
  while (str[i] != '\0' && cmp[i] != '\0')
    {
      if (str[i] != cmp[i])
        return (0);
      i = i + 1;
    }
  if (i == 8 && str[i] == '\0')
    return (1);
  else
    return (0);
}

int	my_exit(char *str)
{
  int	i;
  char	cmp[5] = {'e', 'x', 'i', 't'};

  i = 0;
  while (str[i] != '\0' && cmp[i] != '\0')
    {
      if (str[i] != cmp[i])
        return (0);
      i = i + 1;
    }
  if (i == 4 && str[i] == '\0')
    return (1);
  else
    return (0);
}
