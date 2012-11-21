/*
** my_exit.c for my_exit in /home/issouf_b//minishell2
** 
** Made by benaly issouf-m-sa
** Login   <issouf_b@epitech.net>
** 
** Started on  Sat Nov 13 21:05:23 2010 benaly issouf-m-sa
** Last update Sun Dec  5 21:13:00 2010 benaly issouf-m-sa
*/

#include <stdlib.h>
#include "mysh.h"

void	exit_mult_arg(char **cmd)
{
  int	i;

  i = 1;
  if (cmd[1][0] >= 48 && cmd[1][0] <= 57)
    {
      while (cmd[1][i] >= 48 && cmd[1][i] <= 57 && cmd[1][i] != '\0')
	i = i + 1;
      if (cmd[1][i] != '\0')
	my_putstr("exit: Badly formed number.\n");
      else
	my_putstr("exit: Expression Syntax.\n");
    }
  else
    my_putstr("exit: Expression Syntax.\n");
}

void	exit_one_arg(char **cmd)
{
  int	i;

  i = 1;
  if (cmd[1][0] >= 48 && cmd[1][0] <= 57)
    {
      while (cmd[1][i] >= 48 && cmd[1][i] <= 57 && cmd[1][i] != '\0')
	i = i + 1;
      if (cmd[1][i] != '\0')
	my_putstr("exit: Badly formed number.\n");
      else
	{
	  i = my_getnbr(cmd[1]);
	  free(cmd);
	  exit(i);
	}
    }
  else
    my_putstr("exit: Expression Syntax.\n");
}

void	mk_exit(char **cmd)
{
  if (cmd[1] == 0)
    {
      free(cmd);
      exit(0);
    }
  else if (cmd[2] != 0)
    exit_mult_arg(cmd);
  else if (cmd[1] != 0)
    exit_one_arg(cmd); 
}
