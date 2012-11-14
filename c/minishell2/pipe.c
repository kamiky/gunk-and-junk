/*
** pipe.c for pipe O,O' in /home/rabier_p/work/PROJ/C/minishell2
** 
** Made by patrick rabier
** Login   <rabier_p@epitech.net>
** 
** Started on  Tue Feb 23 09:58:39 2010 patrick rabier
** Last update Fri Feb 26 21:03:42 2010 patrick rabier
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

extern char	**environ;

int		my_exec(char **path, char **tab, int a)
{
  int		i;
  char		*s;

  i = 0;
  while (path[i] != NULL && a == 0)
    {
      s = my_strcat(path[i], tab[0]);
      if (access(s, F_OK) == 0)
	{
	  a = 1;
	  execve(s, tab, environ);
	  exit(0);
	}
      i++;
      free(s);
    }
  return (a);
}

void		last_command(char **commandes, char **path, int *p, int nb)
{
  char		**tab;

  dup2(p[1], 1);
  close(p[0]);
  tab = my_str_to_wordtab(commandes[nb]);
  if (my_exec(path, tab, 0) == 0)
    {
      write(1, tab[0], my_strlen(tab[0]));
      exit(write(1, " : Command not found.\n", 22));
    }
  free(tab);
  exit(0);
}

int		my_tablen(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

void		gere_pipe(char **commandes, char **path)
{
  int		p[2];
  int		pid;
  int		nb;
  char		**tab;
  char		*stock;

  nb = my_tablen(commandes) - 1; 
  pipe(p);
  pid = fork();
  if (pid)
    {
      stock = gere_space(commandes[nb]);
      tab = my_str_to_wordtab(stock);
      dup2(p[0], 0);
      close(p[1]);
      if (my_exec(path, tab, 0) == 0)
	{
	  write(1, tab[0], my_strlen(tab[0]));
	  exit(write(1, " : Command not found.\n", 22));
	}
      free(tab);
      free(stock);
    }
  else
    {
      pipe_engine(commandes, path, p, nb - 1);
      exit(0);
    }
}

int		pipe_engine(char **commandes, char **path, int *p, int nb)
{
  int		p2[2];
  int		pid;
  char		**tab;
  char		*stock;

  if (nb == 0)
    last_command(commandes, path, p, nb);
  pipe(p2);
  pid = fork();
  if (pid)
    {
      dup2(p[1], 1);
      close(p[0]);
      dup2(p2[0], 0);
      close(p2[1]);
      stock = gere_space(commandes[nb]);
      tab = my_str_to_wordtab(stock);
      if (my_exec(path, tab, 0) == 0)
	{
	  write(1, tab[0], my_strlen(tab[0]));
	  exit(write(1, " : Command not found.\n", 22));
	}
      free(tab);
      free(stock);
    }
  else
    {
      pipe_engine(commandes, path, p2, nb - 1);
      exit(0);
    }
  return (0);
}
