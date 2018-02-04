/*
** minishell1.h for minishell1.h in /root/PSU_2016_minishell1/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Mon Jan 16 13:03:44 2017 Leo Lecherbonnier
** Last update Wed Mar  1 08:56:05 2017 Leo Lecherbonnier
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "gnl.h"

int	my_putchar(char c);
int	my_putstr(char *str);
int	my_strlen(char *str);
char	*my_strcat(char *dest, char *src);
int	my_strcmp(char *s1, char *s2);

char	**my_str_to_wordtab(char *str, char separe);
int	nbr_word(char *str);

char	*my_getenv(char **env, char *element);

char	**parse_before_checkaccess(char *str);
char	*cut_path_fromenv(char *env);
char	*check_acess(char **path, char **string, char **env);

pid_t	create_process(void);
void	chlid_process(char *str, char **arg, char **env);

int	check_env(char *str, char **env);
void	print_env(char **env);

int checkInternalCommand(char	**str, char **env);
void changeDir(char **, char **env);
void clearScreen();
void	my_status(int status);
int	my_getnbr(char *str);
