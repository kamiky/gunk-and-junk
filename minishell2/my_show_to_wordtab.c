/*
** my_show_to_wordtab.c for my_show_to_wordtab in /home/issouf_b//minishell
** 
** Made by benaly issouf-m-sa
** Login   <issouf_b@epitech.net>
** 
** Started on  Wed Nov 10 16:36:00 2010 benaly issouf-m-sa
** Last update Wed Nov 10 16:44:37 2010 benaly issouf-m-sa
*/

#include "mysh.h"

void	my_show_to_wordtab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
}
