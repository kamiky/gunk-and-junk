/*
** redir.c for redir in /home/rabier_p/work/PROJ/C/minishell2
** 
** Made by patrick rabier
** Login   <rabier_p@epitech.net>
** 
** Started on  Fri Feb 26 11:51:16 2010 patrick rabier
** Last update Fri Feb 26 16:46:24 2010 patrick rabier
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "pipe.h"

int		check_redir(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (tab[i][0] == '>')
	{
	  if (tab[i][1] == '>')
	    return (2);
	  else
	    return (1);
	}
      if (tab[i][0] == '<')
	{
	  if (tab[i][1] == '<')
	    return (4);
	  else
	    return (3);
	}
      i++;
    }
  return (0);
}

int		redir_droite(char **path, char **cmd)
{
  int		fd;
  int		pos;
  int		pid;
  int		status;

  pid = fork();
  if (pid)
    wait(&status);
  else
    {
      pos = gere_redir_cmd(cmd);
      fd = open(cmd[pos + 1], O_CREAT | O_RDWR | O_TRUNC);
      dup2(fd, 1);
      if (my_exec(path, cmd, 0) == 0)
	{
	  write(1, cmd[0], my_strlen(cmd[0]));
	  exit(write(1, " : Command not found.\n", 22));
	}
      close(fd);
      exit(0);
    }
  return (0);
}

int		redir_droite_double(char **path, char **cmd)
{
  int		fd;
  int		pos;
  int		pid;
  int		status;

  pid = fork();
  if (pid)
    wait(&status);
  else
    {
      pos = gere_redir_cmd(cmd);
      fd = open(cmd[pos + 1], O_CREAT | O_RDWR);
      lseek(fd, 0, SEEK_END);
      dup2(fd, 1);
      if (my_exec(path, cmd, 0) == 0)
	{
	  write(1, cmd[0], my_strlen(cmd[0]));
	  exit(write(1, " : Command not found.\n", 22));
	}
      close(fd);
      exit(0);
    }
  return (0);
}

int		redir_gauche(char **path, char **cmd)
{
  int		fd;
  int		pos;
  int		pid;
  int		status;

  pid = fork();
  if (pid)
    wait(&status);
  else
    {
      pos = gere_redir_cmd(cmd);
      fd = open(cmd[pos + 1], O_RDONLY);
      dup2(fd, 0);
      if (my_exec(path, cmd, 0) == 0)
	{
	  write(1, cmd[0], my_strlen(cmd[0]));
	  exit(write(1, " : Command not found.\n", 22));
	}
      close(fd);
      exit(0);
    }
  return (0);
}

int		gere_redir(char **path, char **cmd)
{
  int		red;

  red = check_redir(cmd);
  if (red == 1)
    return (redir_droite(path, cmd));
  if (red == 2)
    return (redir_droite_double(path, cmd));
  if (red == 3)
    return (redir_gauche(path, cmd));
  if (red == 4)
    return (redir_gauche_double(path, cmd));
  return (0);
}
