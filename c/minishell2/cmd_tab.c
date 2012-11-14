/*
** pipe.c for pipe in /home/rabier_p/work/PROJ/C/minishell2
** 
** Made by patrick rabier
** Login   <rabier_p@epitech.net>
** 
** Started on  Mon Feb 22 15:41:29 2010 patrick rabier
** Last update Fri Feb 26 13:55:30 2010 patrick rabier
*/

#include <stdlib.h>
#include <unistd.h>

int		verif_pipe(char *cmd)
{
  int		i;

  i = 0;
  while (cmd[i] != '\0')
    {
      if (cmd[i] == '|')
	return (1);
      i++;
    }
  return (0);
}

int		char_pipe(char c)
{
  if (c != '|' && c != '\0')
    return (1);
  return (0);
}

int		pipe_count(char *str)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '|')
	count++;
      else if (str[i] == '>')
	{
	  count++;
	  if (str[i + 1] == '>')
	    i++;
	}
      else if (str[i] == '<')
	{
	  count++;
	  if (str[i + 1] == '<')
	    i++;
	}
      i++;
    }
  return (count + 1);
}

char		**pipe_to_wordtab(char *str)
{
  char		**tab;
  int		i;
  int		j;

  i = 0;
  j = 0;
  tab = malloc((pipe_count(str) + 2) * sizeof(*tab));
  while (str[i] != '\0')
    {
      if (char_pipe(str[i]) == 1)
	{
	  if (char_pipe(str[i - 1]) == 0) 
	    tab[j++] = &str[i];
	}
      else if (char_pipe(str[i]) == 0)
	if (char_pipe(str[i - 1]) == 1)
	  str[i] = '\0';
      i++;
    }
  tab[j] = NULL;
  return (tab);
}
