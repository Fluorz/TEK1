/*
** my.h for my.h in /home/abdel/42SH/PSU_2016_42sh/include
**
** Made by abdel cherkaoui
** Login   <abdel@epitech.net>
**
** Started on  Tue May 30 12:53:34 2017 abdel cherkaoui
** Last update Mon Jun 12 11:44:36 2017 Monty Criel
*/

#ifndef MY_H_
# define MY_H_

typedef struct	s_shell
{
  int		return_value;
  char		*cmd;
  char		**env;
  char		**bin_paths;
}		t_shell;

typedef struct	s_func
{
  char**		(*ptrfunc)(char **cmd, char **env, int *status);
  char 		key;
}			t_func;

char	*get_env_var(char **env, char *str);
char	**my_str_to_wordtab(char *str);
char	**change_env(char **cmd, char **env, int *status);
char	**set_env(char **env, char **cmd_name, int *status);
char	*copy_env_var(char *str);
void	print_env(char **env);
void	free_tab(char **tab);
int	print_tab(char **tab);
char	*get_env_var(char **env, char *str);
char	*my_copy(char *string);
void	free_tab(char **tab);
char	**change_dir_special(char **cmd, char **env, int *status);
char	**update_cwd(char **env, char *new_pwd, char *old_pwd);
char	**tab_append_tail(char **tab, char *str);
int	find_str_tab(char **tab, char *str);
char	**tab_pop(char **tab, int pos);
char	**change_directory(char **cmd_name, char **env, int *status);
char	**change_dir(char **env, char *dir_name);
char	**wordtab(char *str);
char	**my_builtins(char **env, char **cmd, int *status);
char	*my_strcat(char *dest, char *src);
char	*my_copy(char *string);
int	check_arg_setenv(char **cmd);
char	**leo_change_env(char **env, char *element, char *to_put);
char	**put_new_data(char **env, int j, char *to_put);
char	*leo_getenv(char **env, char *element);
char	*cut_path_fromenv(char *env);
#endif /* !MY_H_ */
