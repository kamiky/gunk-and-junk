/*
** redir.c for redir in /home/issouf_b//tp_pipe
** 
** Made by benaly issouf-m-sa
** Login   <issouf_b@epitech.net>
** 
** Started on  Thu Dec  2 10:14:49 2010 benaly issouf-m-sa
** Last update Sun Dec  5 21:19:28 2010 benaly issouf-m-sa
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

void	det_ent(int *pip)
{
  close(pip[0]);
  dup2(pip[1], 1);
}

void	mk_red(int fd, char *buff, int i, int *pip)
{
  close(pip[0]);
  close(pip[1]);
  dup2(pip[0], 0);
  write(fd, buff, i);
  close(fd);
}

void	mk_ex(char **path_cmd, char **cmd, char **env)
{
  int	val;
  int	j;
  char	*ch;

  j = 0;
  val = -1;
  while (path_cmd[j] != 0 && val == -1)
    {
      ch = build_ch(path_cmd[j], cmd[0]);
      val = execve(ch, cmd, env);
      j = j + 1;
    }
  free(cmd);
  free(path_cmd);
}

int	redir(char **cmd, char **path_cmd, char **env, int fd)
{
  int	pip[2];
  char	buff[10000];
  pid_t	pid;
  int	status;
  int	i;
  
  pipe(pip);
  pid = fork();
  if (pid > 0)
    {
      wait(&status);
      i = read(pip[0], buff, 10000);
      buff[i] = '\0';
      mk_red(fd, buff, i, pip);
    }
  else if (pid == 0)
    {
      det_ent(pip);
      mk_ex(path_cmd, cmd, env);
      exit(status);
    }
  else
    return (-1);
  return (0);
}
