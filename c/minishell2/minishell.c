/*
** minishell.c for minishell in /home/rabier_p/work/PROJ/C/MINISHELL1
** 
** Made by patrick rabier
** Login   <rabier_p@epitech.net>
** 
** Started on  Fri Jan  1 05:51:29 2010 patrick rabier
** Last update Fri Feb 26 16:51:05 2010 patrick rabier
*/

#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <paths.h>
#include "minishell.h"

char		**environ;

int		my_else(char **tab, int a, char **path)
{
  char		*home;

  if (a == 1)
    return (1);
  if (my_strcmp(tab[0], "cd") == 0)
    {    
      if (tab[1] != NULL)
	{
	  if (access(tab[1], F_OK) != -1)
	    chdir(tab[1]);
	}
      else
	{
	  if ((home = my_getenv("HOME")))
	    {	    
	      chdir(home);
	      free(home);
	    }
	}
      return (1);
    }
  return (cond(tab, path));
}

int		execution(char **path, char **tab, int a)
{
  int		i;
  int		pid;
  char		*s;
  int		status;

  i = 0;
  if (check_redir(tab))
    {
      gere_redir(path, tab);
      return (1);
    }
  while (path[i++] != NULL && a == 0)
    {
      s = my_strcat(path[i - 1], tab[0]);
      if (access(s, F_OK) == 0)
	{
	  a = 1;
	  pid = fork();
	  if (pid)
	    wait(&status);
	  else
	    {
	      execve(s, tab, environ);
	      exit(0);
	    }
	}
      free(s);
    }
  return (a);
}

void		sh(char **path)
{
  char		*cmd;
  char		**tab;
  int		a;

  signal(2, SIG_IGN);
  while ((cmd = prompt()))
    {
      a = gestion_erreur(cmd);
      cmd = space(cmd);
      if (a != 1 && verif_pipe(cmd) == 0)
	{
	  tab = my_str_to_wordtab(cmd);
	  a = my_else(tab, a, path);
	  a = execution(path, tab, a);
	  if (a == 0)
	    my_printf("%s: Command not found.\n", tab[0]);
	  free(tab);
	}
      else if (verif_pipe(cmd) == 1)
	pipe_start(cmd, path);
      free(cmd);
    }
}
  
int		main()
{
  char		**path;
  char		*str;

  write(1, "\n", 1);
  str = my_getenv("PATH");
  if (str[0] != ' ')
    path = my_path_to_wordtab(str);
  else
    path = path_rescue();
  sh(path);
  return (EXIT_SUCCESS);
}
