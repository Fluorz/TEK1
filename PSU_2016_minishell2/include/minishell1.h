/*
** minishell1.h for minishell1.h in /root/PSU_2016_minishell1/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Mon Jan 16 13:03:44 2017 Leo Lecherbonnier
** Last update Thu Apr  6 12:33:42 2017 Leo Lecherbonnier
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "gnl.h"

# define ERROR_ACCES_DENIED	"Permission denied : "

extern int RETURN_VALUE;

typedef struct s_parse
{
  char	**scan;
  char	**path_env;
  char	*string;
  char	*good_path;
  char  **env;
  int		pid;
  int		status;
}								t_parse;

int	my_putchar(char c);
int	my_putstr(char *str);
int	my_strlen(char *str);
char	*my_strcat(char *dest, char *src);
int	my_strcmp(char *s1, char *s2);
char    *my_strcpy(char *dest, char *src);
char	*my_strdup(char *str);

char	**my_str_to_wordtab(char *str, char separe);
int	nbr_word(char *str);

char	*my_getenv(char **env, char *element);

char	**parse_before_checkaccess(char *str);
char	*cut_path_fromenv(char *env);
/*char	*check_acess(char **path, char **string, char **env);*/

pid_t	create_process(void);
void	chlid_process(char *str, char **arg, char **env);

int	check_env(char *str, char **env);
void	print_env(char **env);

void	no_directory(char *str);
char	**put_new_data(char **environement, int j, char *to_put);
char	**change_env(char **env, char *element, char *to_put);
int checkInternalCommand(char	**str, t_parse *p);
void changeDir(char **, char **env);
void clearScreen();
void	my_status(int status);
int	my_getnbr(char *str);
char **my_setenv(char **str, char **env);
int	check_other_command(char **str, t_parse *p);
char	**my_unsetenv(char **str, char **env);
char 	**struct_op(char **env, char *name, char *value);
t_parse *init_parse(char **env);
int	loop(t_parse *p);
char	*check_acess(char **path, char **string, t_parse *p);
int	find_line_before_delete(char *element, char **env);
char	**delete_line(int line, char **env);
void	my_error(const char *error, const char *var);
char	*delete_pwd_of_string(char *string, char *pwd);
