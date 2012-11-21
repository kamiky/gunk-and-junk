/*
** mysh.h for mysh in /home/issouf_b//minishell
** 
** Made by benaly issouf-m-sa
** Login   <issouf_b@epitech.net>
** 
** Started on  Wed Nov 10 10:15:20 2010 benaly issouf-m-sa
** Last update Sun Dec  5 21:18:15 2010 benaly issouf-m-sa
*/

#ifndef __MYSH_H__
#define __MYSH_H__

void	mk_ex(char **path_cmd, char **cmd, char **env);
int     nb_pipe(char **str);
void	mk_pip_inf(int pipe1[2], int pipe2[2], char **path_cmd, char **cmd);
int	mk_procs1(int pipe1[2], int pipe2[2], char **path_cmd, char **cmd);
int	mk_procs2(int pipe1[2], int pipe2[2], char **path_cmd, char **cmd);
int	inf_pip(char **cmd, char **path_cmd, int nb);
char    **mk_cmd(char **str, int size);
int     mk_sign(char **str, char **path_env, int s, char **env);
int     mk_redir_or_pip(char **str, char **path_env, char **env);
int     redir(char **cmd, char **path_cmd, char **env, int fd);
void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
char	*build_ch(char *path_c, char *cmd);
int	cpt(char *str, char sep);
char	*my_strcpy(char *str, int pos, int first);
char	**my_str_to_wordtab(char *str, int i, int j, int size);
char	**my_path(char *str);
char	*get_next_line(const int fd);
void	my_show_to_wordtab(char **tab);
int	str_cmp(char *str);
int	check_cd(char *str);
int	change_rep(char *ch, char *ch2, char **env);
int	check_user(char *use, char **env);
char	*go_home(char **env);
int	set(char *str);
int	unset(char *str);
void	choice(char **cmd, char **env);
int	create_venv(char *cmd1, char *cmd2, char *cmd3);
int	del_venv(char **cmd);
int	my_exit(char *str);
void	mk_exit(char **cmd);
int	my_getnbr(char *str);
void	exit_mult_arg(char **cmd);
void	exit_one_arg(char **cmd);
int	check_pwd(char *cpwd, char **env);       
int	go_prev_rep(char *ch, char **env);
void	no_prev(char *ch);
void	mk_prev();
void	error_ch(char *ch);
char	**my_init(char **cmd, int size);
int	mysh(char **cmd, char **env, char **path_cmd);
int	check_path(char *pth, char **env);
int     check_sign(char *s1, char *str, char *s2);
int	sign(char **str);
void	get_prev(char **env);
 
#endif
