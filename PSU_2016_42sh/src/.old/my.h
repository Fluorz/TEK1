/*
** my.h for my.h in /home/abdel/42SH/PSU_2016_42sh/include
**
** Made by abdel cherkaoui
** Login   <abdel@epitech.net>
**
** Started on  Tue May 30 12:53:34 2017 abdel cherkaoui
** Last update May Jun 1 14:47:50 2017
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

int	init_shell(t_shell *shell, char **env);
char	*get_env_var(char **env, char *str);
char	**my_str_to_wordtab(char *str);
int	my_builtin(t_shell *shell);
char	*copy_env_var(char *str);
void	print_env(char **env);
void	free_tab(char **tab);

#endif /* !MY_H_ */
