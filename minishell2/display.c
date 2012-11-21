/*
** display.c for display in /home/issouf_b//minishell2
** 
** Made by benaly issouf-m-sa
** Login   <issouf_b@epitech.net>
** 
** Started on  Sun Nov 14 21:18:29 2010 benaly issouf-m-sa
** Last update Sun Dec  5 21:14:39 2010 benaly issouf-m-sa
*/

#include <unistd.h>
#include "mysh.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
