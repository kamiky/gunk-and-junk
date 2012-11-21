/*
** choice.c for choice in /home/issouf_b//minishell2
** 
** Made by benaly issouf-m-sa
** Login   <issouf_b@epitech.net>
** 
** Started on  Sat Nov 13 18:24:34 2010 benaly issouf-m-sa
** Last update Sun Nov 14 18:58:31 2010 benaly issouf-m-sa
*/

#include "mysh.h"

void	choice(char **cmd, char **env)
{
  if (cmd[0][0] == 'c')
    change_rep(cmd[1], cmd[2], env);
  else if (cmd[0][0] == 's')
    create_venv(cmd[1], cmd[2], cmd[3]);
  else if (cmd[0][0] == 'e')
    mk_exit(cmd);
  else
    del_venv(cmd);
}
