/*
** else.h for else in /home/rabier_p/work/PROJ/C/MINISHELL1
** 
** Made by patrick rabier
** Login   <rabier_p@epitech.net>
** 
** Started on  Sun Jan 10 14:56:16 2010 patrick rabier
** Last update Sat Feb 20 11:32:15 2010 patrick rabier
*/

#ifndef ELSE
#define ELSE

void		my_printf(char *str, ...);
int		my_env();
int		my_setenv(char *name, char *value);
int		my_unsetenv(char *name);
int		my_strlen(char *str);
char		**my_path_to_wordtab(char *str);
char		*my_getenv(char *name);
int		ctrl(char *str);

#endif
