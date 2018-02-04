/*
** my_exec.h for my_exec.h in /home/lecherbonnier/Projet/PSU_2016_42sh/include/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Jun  1 14:43:28 2017 Leo Lecherbonnier
** Last update Mon Jun 12 10:13:39 2017 Sid Djilali Saiah
*/

#ifndef MY_EXEC_H
#define MY_EXEC_H

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "parser.h"
#include "transition.h"

int	check_bonus_builtins(char **cmd, char **env);
int	which(char **cmd, char **env);
int	where(char **cmd, char **env);
void my_echo(char **cmd);
void my_exit(char **cmd);
void chlid_process(char *str, char **arg, char **env);
pid_t create_process(void);
t_transitor	*execve_simple(t_transitor *transitor, t_arg_transitor *arg);
t_transitor *apply_pipe_in(t_transitor *transitor, t_arg_transitor *arg);
t_transitor *apply_pipe_out(t_transitor *transitor, t_arg_transitor *arg);
t_transitor *apply_double_pipe(t_transitor *, t_arg_transitor *);
t_transitor *execve_pipe(t_transitor *transitor, t_arg_transitor *arg);
t_transitor *builtins_simple(t_transitor *transitor, t_arg_transitor *tmp);
t_transitor *builtins_pipe(t_transitor *transitor, t_arg_transitor *tmp);
t_arg_transitor *my_else_status(int status, t_arg_transitor *arg);
t_arg_transitor *my_status(int status, t_arg_transitor *arg);
t_transitor	*apply_in_redirection(t_transitor *, t_arg_transitor *);
t_transitor	*apply_out_redirection(t_transitor *, t_arg_transitor *);
t_transitor	*apply_double_in_redirection(t_transitor *, t_arg_transitor *);
t_transitor	*apply_double_out_redirection(t_transitor *, t_arg_transitor *);
t_transitor	*apply_pipe_out_and_redir_left(t_transitor *,
										t_arg_transitor *);

#endif /*!MY_EXEC_H*/
