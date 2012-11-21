/*
** my_env.c for my_env in /home/issouf_b//minishell2
** 
** Made by benaly issouf-m-sa
** Login   <issouf_b@epitech.net>
** 
** Started on  Sat Nov 13 18:39:00 2010 benaly issouf-m-sa
** Last update Sun Dec  5 21:03:28 2010 benaly issouf-m-sa
*/

#include <stdlib.h>
#include "mysh.h"

int	create_venv(char *cmd1, char *cmd2, char *cmd3)
{
  if (cmd3 != 0)
    my_putstr("setenv: Too many arguments.\n");
  else
    setenv(cmd1, cmd2, 1);
  return (0);
}

int	del_venv(char **cmd)
{
  int	i;

  i = 1;
  if (cmd[i] == 0)
    my_putstr("unsetenv: Too few arguments.\n");
  else
    {
      while (cmd[i] != 0)
	{
	  unsetenv(cmd[i]);
	  i = i + 1;
	}
    }
  return (0);
}
