/*
** minishell.h for shell in /home/rabier_p/work/PROJ/C/MINISHELL1
** 
** Made by patrick rabier
** Login   <rabier_p@epitech.net>
** 
** Started on  Fri Jan  8 10:39:11 2010 patrick rabier
** Last update Fri Feb 26 16:15:38 2010 patrick rabier
*/

#ifndef MINISHELL_
# define MINISHELL_

int		my_strlen(char *str);
void		blob();
char		*prompt();
char		*space(char *str);
char		*my_strcat(char *s1, char *s2);
int		my_strcmp(char *s1,char *s2);
char		*my_getenv(char *name);
void		my_printf(char *str, ...);
char		**my_str_to_wordtab(char *str);
char		**my_path_to_wordtab(char *str);
int		cond(char **tab, char **path);
int		gestion_erreur(char *cmd);
char		**path_rescue();
void		gere_pipe(char **commandes, char **path);
char		**pipe_to_wordtab(char *str);
int		verif_pipe(char *cmd);
int		pipe_start(char *cmd, char **path);
int		gere_redir(char **path, char **cmd);
int		check_redir(char **tab);

#endif
