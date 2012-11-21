/*
** mysh.c for mysh in /home/issouf_b//minishell
** 
** Made by benaly issouf-m-sa
** Login   <issouf_b@epitech.net>
** 
** Started on  Tue Nov  9 21:10:38 2010 benaly issouf-m-sa
** Last update Sun Dec  5 20:58:37 2010 benaly issouf-m-sa
*/

#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include "mysh.h"

void	no_cmd(char *str)
{
  my_putstr(str);
  my_putstr(": Command not found.\n");
}

int	mysh(char **cmd, char **env, char **path_cmd)
{
  int	status;
  int	i;
  int	val;
  char	*ch;
  pid_t pid;

  pid = fork();
  i = 0;
  val = -1;
  if (pid > 0)
    wait(&status);
  else if (pid == 0)
    {
      while (path_cmd[i] != 0 && val == -1)
	{
	  ch = build_ch(path_cmd[i], cmd[0]);
	  val = execve(ch, cmd, env);
	  i = i + 1;
	}
      if (val == -1)
	no_cmd(cmd[0]);
      free(path_cmd);
      exit(status);
    }
  else
    return (-1);
  return (0);
}

char	*get_next_line(const int fd)
{
  char	*buffer;
  int	oct;

  buffer = malloc(sizeof(char *) * 1024);
  oct = read(fd, buffer, 1024);
  buffer[oct - 1] = '\0';
  return (buffer);
}

int		main()
{
  char		**arg;
  char		*s;
  int		i;
  extern char	**environ;
  char		**path_cmd;

  my_putstr("$>");
  while ((s = get_next_line(0)))
    {
      arg = my_str_to_wordtab(s, 0, 0, 0);
      free(s);
      i = check_path("PATH=", environ);
      path_cmd = my_path(environ[i]);
      if (check_cd(arg[0]) || set(arg[0]) || unset(arg[0]) || my_exit(arg[0]))
	choice(arg, environ);
      else if (sign(arg))
	mk_redir_or_pip(arg, path_cmd, environ);
      else
	mysh(arg, environ, path_cmd);
      free(arg);
      free(path_cmd);
      my_putstr("$>");
    }
  free(environ);
  return (0);
}
