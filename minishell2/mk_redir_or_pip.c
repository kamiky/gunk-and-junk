/*
** mk_redir_or_pip.c for mk_redir_or_pip in /afs/epitech.net/users/epitech_2014/issouf_b/rendu/c/minishell2
** 
** Made by benaly issouf-m-sa
** Login   <issouf_b@epitech.net>
** 
** Started on  Sat Dec  4 15:20:36 2010 benaly issouf-m-sa
** Last update Sun Dec  5 21:13:38 2010 benaly issouf-m-sa
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

static int pos = 0;

int	nb_pipe(char **str)
{
  int	i;
  int	c;

  i = 0;
  c = 0;
  while (str[i] != 0)
    {
      if (str[i][0] == '|' && str[i][1] == '\0')
	c = c + 1;
      i = i + 1;
    }
  return (c);
}

char	**mk_cmd(char **str, int size)
{
  char	**cmd;
  int	i;

  i = 0;
  cmd = malloc(sizeof(*cmd) * size);
  while (i < size - 1 && str[pos][0] != '|' && str[pos][0] != ';')
    {
      cmd[i] = malloc(sizeof(**cmd) * my_strlen(str[pos]));
      cmd[i] = str[pos];
      pos = pos + 1;
      i = i + 1;
    }
  pos = pos + 1;
  cmd[i] = 0;
  return (cmd);
}

int	mk_sign(char **str, char **path_env, int s, char **env)
{
  char	**cmd;
  int	fd;
  
  if (str[s - 1] && str[s + 1])
    {
      if ((str[s][0] == '>' && str[s][1] == '>') || str[s][1] == '\0')
	{
	  cmd = mk_cmd(str, s + 1);
	  fd = open(str[s + 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
	  redir(cmd, path_env, env, fd);
	}
      else if (str[s + 1][0] == ';' && str[s + 1][1] == '\0')
	{
	  cmd = mk_cmd(str, s + 2);
	  mysh(cmd, env, path_env);
	}
    }
  return (0);
}

int	mk_redir_or_pip(char **str, char **path_env, char **env)
{
  int	i;

  i = 1;
  if (nb_pipe(str) > 0)
    inf_pip(str, path_env, nb_pipe(str) + 1);
  else
    {
      while (str[i] != 0)
	{
	  mk_sign(str, path_env, i, env);
	  i = i + 1;
	}
    }
  pos = 0;
  return (0);
}
