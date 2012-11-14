/*
** else.c for else in /home/rabier_p/work/PROJ/C/MINISHELL1
** 
** Made by patrick rabier
** Login   <rabier_p@epitech.net>
** 
** Started on  Thu Jan  7 10:33:32 2010 patrick rabier
** Last update Fri Feb 26 11:57:59 2010 patrick rabier
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "else.h"

extern char		**environ;

int			my_strlen(char *str)
{
  int			i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int	my_strcmp(char *s1,char *s2)
{
  int	i;
  int	t;

  i = 0;
  if (my_strlen(s1) > my_strlen(s2))
      t = my_strlen(s1);
  else
      t = my_strlen(s2);
  while (i != t + 1)
    {
      if (s1[i] > s2[i])
	  return (1);
      else if (s1[i] < s2[i])
	  return (-1);
      i = i + 1;
    }
  return (0);
}

int			cond(char **tab, char **path)
{
  int			i;

  i = 0;
  if (my_strcmp(tab[0], "env") == 0)
    {
      my_env();
      return (1);
    }
  if (my_strcmp(tab[0], "setenv") == 0)
    {
      if (tab[1] == NULL)
	return (my_env());
      else if (tab[2] != NULL)
	return (my_setenv(tab[1], tab[2]));
    }
  if (my_strcmp(tab[0], "unsetenv") == 0 && tab[1] != NULL)
    return (my_unsetenv(tab[1]));
  if (my_strcmp(tab[0], "exit") == 0)
    {
      free(path);
      exit(EXIT_SUCCESS);
    }
  return (0);
}

char			*space(char *str)
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
  free(str);
  return (cmd);
}

char			*my_strcat(char *s1, char *s2)
{
  char			*str;
  int			i;
  int			j;

  i = 0;
  j = 0;
  str = malloc((my_strlen(s1) + my_strlen(s2) + 2) * sizeof(*str));
  if (str == NULL)
    exit(write(1, "Memory Allocation FAIL !!!", 25));
  while (s1[i] != '\0')
    {    
      str[i] = s1[i];
      i++;
    }
  str[i++] = '/'; 
  while (s2[j] != '\0')
    str[i++] = s2[j++];
  str[i] = '\0';
  return (str);
}
