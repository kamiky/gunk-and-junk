/*
** change_rep.c for change_rep in /home/issouf_b//minishell1
** 
** Made by benaly issouf-m-sa
** Login   <issouf_b@epitech.net>
** 
** Started on  Fri Nov 12 20:08:55 2010 benaly issouf-m-sa
** Last update Sun Dec  5 21:12:11 2010 benaly issouf-m-sa
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"

static	char	*prev1;
static	char	*prev2;

int	check_pwd(char *cpwd, char **env)
{
  int	i;
  int	j;
  int	rep;
  char	*cmp;

  cmp = cpwd;
  i = 0;
  rep = 0;
  while (env[i] != 0 && rep != 1)
    {
      j = 0;
      while (env[i][j] == cmp[j] && env[i][j] != '\0')
	{
	  if (env[i][j] == cmp[3])
	    rep = 1;
	  j = j + 1;
	}
      i = i + 1;
    }
  return (i - 1);
}

void	get_prev(char **env)
{
  char	*my_pwd;
  int	i;
  int	j;
  int	x;
  int	size;

  j = 4;
  x = 0;
  i = check_pwd("PWD=", env);
  if (env[i] != 0)
    {
      size = my_strlen(env[i]);
      my_pwd = malloc(sizeof(*my_pwd) * (size - 4));
      while (j <= size)
        {
          my_pwd[x] = env[i][j];
          x = x + 1;
          j = j + 1;
        }
    }
  prev1 = my_pwd;
}

void	no_prev(char *ch)
{
  prev1 = prev2;
  prev2 = ch;
}

void	mk_prev()
{
  char	*tmp;

  tmp = prev1;
  prev1 = prev2;
  prev2 = tmp;
}

int	change_rep(char *ch, char *ch2, char **env)
{
  if (ch != 0 && ch2 != 0)
    {
      my_putstr("cd: Too many arguments.\n");
      return (0);
    }
  else if ((ch == 0) || (ch[0] == '~' && ch2 == 0))
    {
      no_prev(ch);
      prev2 = go_home(env);
      return (0);
    }
  else if (ch[0] == '-' && ch[1] == '\0' && ch2 == 0)
    {
      if (go_prev_rep(prev1, env))
	mk_prev();
    }
  else if (chdir(ch) == -1 && ch[0] != '*')
    {
      my_putstr(ch);
      my_putstr(": No such file or directory.\n");
    }
  if (ch[0] == '*' || (ch[0] == '-' && ch[1] != '\0'))
    error_ch(ch);
  return (0);
}

