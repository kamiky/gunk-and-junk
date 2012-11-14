/*
** my_str_to_wordtab.c for str_to_wordtab in /home/rabier_p/work/PROJ/C/MINISHELL1
** 
** Made by patrick rabier
** Login   <rabier_p@epitech.net>
** 
** Started on  Thu Jan  7 13:46:29 2010 patrick rabier
** Last update Mon Feb 22 18:30:37 2010 patrick rabier
*/

#include <unistd.h>
#include <stdlib.h>

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

int		alpha(char c)
{
  if ((c >= 33 && c <= 39) || (c >= 42 && c <= 126))
    return (1);
  return (0);
}

int		alpha2(char c)
{
  if (((c >= 33 && c <= 39) || (c >= 42 && c <= 126)) && c != ':')
    return (1);
  return (0);
}

int		nbr_mots(char *str)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      if (alpha(str[i]) == 1 && (str[i + 1] == ' '))
	count++;
      i++;
    }
  return (count + 2);
}

char		**my_str_to_wordtab(char *str)
{
  char		**tab;
  int		i;
  int		j;

  i = 0;
  j = 0;
  tab = xmalloc(nbr_mots(str) * sizeof(*tab));
  while (str[i] != '\0')
    {
      if (alpha(str[i]) == 1)
	{
	  if (alpha(str[i - 1]) == 0) 
	    {
	      tab[j] = &str[i];
	      j = j + 1;
	    }
	}
      else if (alpha(str[i]) == 0)
	if (alpha(str[i - 1]) == 1)
	  str[i] = '\0';
      i = i + 1;
    }
  tab[j] = NULL;
  return (tab);
}

char		**my_path_to_wordtab(char *str)
{
  char		**tab;
  int		i;
  int		j;

  i = 0;
  j = 0;
  tab = xmalloc(15 * sizeof(*tab));
  while (str[i] != '\0')
    {
      if (alpha2(str[i]) == 1)
	{
	  if (alpha2(str[i - 1]) == 0) 
	    {
	      tab[j] = &str[i];
	      j = j + 1;
	    }
	}
      else if (alpha2(str[i]) == 0)
	if (alpha2(str[i - 1]) == 1)
	  str[i] = '\0';
      i = i + 1;
    }
  tab[j] = NULL;
  return (tab);
}
