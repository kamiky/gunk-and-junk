/*
** mk_pip_inf.c for mk_pip_inf in /home/issouf_b//msh2-3/minishell2-3/minishell2
** 
** Made by benaly issouf-m-sa
** Login   <issouf_b@epitech.net>
** 
** Started on  Sun Dec  5 17:34:21 2010 benaly issouf-m-sa
** Last update Sun Dec  5 21:20:10 2010 benaly issouf-m-sa
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "mysh.h"

static int      j = 0;
static int	i = 0;
static int	n;

void		mk_pip_inf(int pipe1[2], int pipe2[2], char **path_cmd, char **cmd)
{
  extern char	**environ;

  if (i != 0)
    dup2(pipe2[0], 0);
  if (i != n - 1)
    dup2(pipe1[1], 1);
  close(pipe1[1]);
  mk_ex(path_cmd, cmd, environ);
  free(cmd);
  free(path_cmd);
}

int	mk_procs1(int pipe1[2], int pipe2[2], char **path_cmd, char **cmd)
{
  int	pid;
  int	status;

  pipe(pipe1);
  pid = fork();
  if (pid > 0)
    {
      close(pipe1[1]);
      close(pipe2[0]);
      wait(&status);
    }
  else if (pid == 0)
    {
      mk_pip_inf(pipe1, pipe2, path_cmd, cmd);
      exit(status);
    }
  else
    return (-1);
  return (0);
}

int	mk_procs2(int pipe1[2], int pipe2[2], char **path_cmd, char **cmd)
{
  int	pid;
  int	status;

  pipe(pipe2);
  pid = fork();
  if (pid > 0)
    {
      close(pipe1[0]);
      close(pipe2[1]);
      wait(&status);
    }
  else if (pid == 0)
    {
      mk_pip_inf(pipe2, pipe1, path_cmd, cmd);
      exit(status);
    }
  else
    return (-1);
  return (0);
}


int	inf_pip(char **cmd, char **path_cmd, int nb)
{
  int	pipe1[2];
  int	pipe2[2];
  char	**my_cmd;

  n = nb;
  while (i < n)
    {
      while (cmd[j] != 0 && cmd[j][0] != '|')
	j = j + 1;
      if (cmd[j][0] == '|')
	my_cmd = mk_cmd(cmd, j + 1);
      if ((i % 2) == 0)
	mk_procs1(pipe1, pipe2, path_cmd, my_cmd);
      else
        mk_procs2(pipe1, pipe2, path_cmd, my_cmd);
      i = i + 1;
    }
  i = 0;
  j = 0;
  return (0);
}
