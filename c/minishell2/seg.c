/*
** seg.c for seg in /home/rabier_p/work/PROJ/C/MINISHELL1
** 
** Made by patrick rabier
** Login   <rabier_p@epitech.net>
** 
** Started on  Fri Jan  8 21:05:11 2010 patrick rabier
** Last update Mon Feb 22 18:27:10 2010 patrick rabier
*/

#include <unistd.h>
#include <paths.h>
#include <stdlib.h>
#include "else.h"

extern char	**environ;

int		ctrl(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\n')
    {
      if (str[i] < 32 || str[i] > 126)
	return (-1);
      i++;
    }
  return (1);
}

char		**path_rescue()
{
  char		*str;
  char		**tab;
  int		i;

  i = 0;
  str = malloc((my_strlen(_PATH_STDPATH) + 1) * sizeof(*str));
  if (str == NULL)
    exit(write(1, "Memory Allocation Fail ! :'(", 28));
  while (i <= my_strlen(_PATH_STDPATH))
    {
      str[i] = _PATH_STDPATH[i];
      i++;
    }
  str[i] = '\0';
  tab = my_path_to_wordtab(str);
  return (tab);
}

int		my_setenv(char *name, char *value)
{
  setenv(name, value, 1);
  return (1);
}

int		my_unsetenv(char *name)
{
  unsetenv(name);
  return (1);
}

int		gestion_erreur(char *cmd)
{
  int		i;

  i = 0;
  if (cmd == "\n")
    return (1);
  while (cmd[i] == ' ')
    i++;
  if (i == my_strlen(cmd))
    return (1);
  return (0);
}
