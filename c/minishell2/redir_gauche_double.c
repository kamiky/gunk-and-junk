/*
** getnextline.c for getnextline in /home/rabier_p/work/PROJ/C/GETNEXTLINE/NEW
** 
** Made by patrick rabier
** Login   <rabier_p@epitech.net>
** 
** Started on  Fri Jan  1 05:11:14 2010 patrick rabier
** Last update Fri Feb 26 16:50:19 2010 patrick rabier
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include "pipe.h"

extern char		**environ;

static void		*xmalloc(size_t n)
{
  void		*p;

  p = malloc(n);
  if (p == 0)
    {
      write(1, "Virtual memory exhausted\n", 27);
      exit(1);
    }
  return (p);
}

char			*double_feinte()
{
  char			*str;

  str = xmalloc(2 * sizeof(*str));
  str[0] = ' ';
  str[1] = '\0';
  return (str);
}


int			feinte_read(int n, char *buffer)
{
  int			i;

  i = 0;
  while (buffer[i] != '\n' && i != 1024)
    {
      if (i == 1023)
	{
	  printf("Ceci est une mauvaise idee 0,0' \n");
	  exit(1);
	}
      n++;
      i++;
    }
  return (n);
}

char			*my_redir_read()
{
  char			buffer[1024];
  int			i;
  int			n;
  char			*str;
  
  n = 0;
  i = 0;
  write(1, "? ", 2);
  read(0, buffer, 1024);
  if (buffer[0] == '\n')
    return (double_feinte());
  n = feinte_read(n, buffer);
  str = xmalloc(n * sizeof(*str));
  i = 0;
  while (i++ < n)
    str[i - 1] = buffer[i - 1];
  str[i] = '\0';
  return (str);
}

int		lecture(int *p, char *keyword)
{
  char		*str;

  str = my_redir_read();
  close(p[0]);
  while (my_strcmp(str, keyword) != 0)
    {
      write(p[1], str, my_strlen(str));
      write(p[1], "\n", 1);
      free(str);
      str = my_redir_read();
    }
  free(str);
  exit(0);
}

int		redir_gauche_double(char **path, char **cmd)
{
  int		p[2];
  int		pid;
  int		pos;
  int		status;

  pipe(p);
  pid = fork();
  pos = gere_redir_cmd(cmd);
  if (pid)
    {
      close(p[1]);
      dup2(p[0], 0);
      wait(&status);
      my_exec(path, cmd, 0);
      exit(0);
    }
  else
    {
      lecture(p, cmd[pos + 1]);
      exit(0);
    }
  return (0);
}
