/*
** error_ch.c for error_ch in /home/issouf_b//minishell2
** 
** Made by benaly issouf-m-sa
** Login   <issouf_b@epitech.net>
** 
** Started on  Sun Nov 14 20:07:08 2010 benaly issouf-m-sa
** Last update Sun Dec  5 21:18:50 2010 benaly issouf-m-sa
*/

#include <unistd.h>
#include "mysh.h"

int	go_prev_rep(char *ch, char **env)
{
  if (!ch)
    {
      get_prev(env);
      my_putstr(": No such file or directory.\n");
    }
  else
    {
      chdir(ch);
      return (1);
    }
  return (0);
}

void	error_ch(char *ch)
{
  if (ch[0] == '-' && ch[1] != '\0')
    my_putstr("Usage: cd [-plvn][-|<dir>].\n");
  else if (ch[0] == '*')
    {
      my_putstr(ch);
      my_putstr(": Ambiguous.\n");
    }
}
