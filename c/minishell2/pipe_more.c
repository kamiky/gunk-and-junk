/*
** pipe_more.c for more in /home/rabier_p/work/PROJ/C/minishell2
** 
** Made by patrick rabier
** Login   <rabier_p@epitech.net>
** 
** Started on  Wed Feb 24 11:42:29 2010 patrick rabier
** Last update Fri Feb 26 21:03:43 2010 patrick rabier
*/

#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "pipe.h"

void		pipe_start(char *cmd, char **path)
{
  int		pid;
  char		**tab;
  int		status;
  int		i;

  i = 0;
  pid = fork();
  if (pid)
    wait(&status);
  else
    {
      tab = pipe_to_wordtab(cmd);
      gere_pipe(tab, path);
      free(tab);
    }
}

char			*gere_space(char *str)
{
  int			i;
  int			n;
  int			size;
  char			*cmd;

  i = 0;
  n = 0;
  if (str == NULL)
    return ("\n");
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  size = (my_strlen(str) - i + 1);
  cmd = malloc(size * sizeof(*cmd));
  if (cmd == NULL)
    exit(write(1, "Memory Allocation FAIL !", 24));
  while (n <= size)
    cmd[n++] = str[i++];
  cmd[n] = '\0';
  return (cmd);
}

int		gere_redir_cmd(char **cmd)
{
  int		i;

  i = 0;
  while (cmd[i][0] != '>' && cmd[i][0] != '<')
    i++;
  cmd[i] = NULL;
  return (i);
}
