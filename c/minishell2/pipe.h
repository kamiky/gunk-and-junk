/*
** pipe.h for pipe in /home/rabier_p/work/PROJ/C/minishell2
** 
** Made by patrick rabier
** Login   <rabier_p@epitech.net>
** 
** Started on  Wed Feb 24 12:20:30 2010 patrick rabier
** Last update Fri Feb 26 16:46:05 2010 patrick rabier
*/

#ifndef PIPE_
# define PIPE_

char			*space(char *str);
char			**my_str_to_wordtab(char *str);
char			*my_strcat(char *s1, char *s2);
char			**pipe_to_wordtab(char *str);
void			gere_pipe(char **commandes, char **path);
int			pipe_engine(char **commandes, char **path, int *p, int nb);
int			my_strlen(char *str);
char			*gere_space(char *str);
int			gere_redir_cmd(char **cmd);
int			my_exec(char **path, char **tab, int a);
int			redir_gauche_double(char **path, char **cmd);
int			my_strcmp(char *s1, char *s2);

#endif
