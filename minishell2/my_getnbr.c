/*
** my_getnbr.c for my_getnbr in /afs/epitech.net/users/epitech_2014/issouf_b/rendu/lib/my
** 
** Made by benaly issouf-m-sa
** Login   <issouf_b@epitech.net>
** 
** Started on  Wed Oct 13 17:15:38 2010 benaly issouf-m-sa
** Last update Mon Nov 15 00:07:32 2010 benaly issouf-m-sa
*/

#include "mysh.h"

int	my_getnbr(char *str)
{
  int	pos;
  int	signe;
  int	nbr;

  signe = 1;
  pos = 0;
  while (str[pos] != '\0' && (str[pos] == '+' || str[pos] == '-'))
    {
      if (str[pos] == '-')
	signe = signe * -1;
      pos = pos + 1;
    }
  str = str + pos;
  pos = 0;
  nbr = 0;
  while (str[pos] >= '0' && str[pos] <= '9')
    {
      nbr = nbr * 10;
      nbr = nbr - (str[pos] - '0');
      pos = pos + 1;
    }
  return (nbr * signe * -1);
}
