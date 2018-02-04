/*
** transition.h for transition.c in /home/lecherbonnier/Projet/PSU_2016_42sh/include/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Jun  1 14:42:40 2017 Leo Lecherbonnier
** Last update Fri Jun 16 14:54:30 2017 Sid Djilali Saiah
*/

#ifndef TRANSITION_H
#define TRANSITION_H

#include "parser.h"
#include <string.h>

extern int g_return_value;

typedef struct	s_arg_transitor
{
  bool		start;
  bool		builtins;
  bool		double_pipe;
  bool		double_and;
  bool		pipe_in; /* cat -e*/
  bool		pipe_out; /*ls*/
  bool		r_right; /*false*/
  bool		r_left; /*false*/
  bool		r_double_right; /*false*/
  bool		r_double_left; /*false*/
  int		return_value; /*return value de la command*/
  int		fd_out; /*si ca ete pipe "ls"*/
  int		fd_in; /*si il y en a besoin "cat -e"*/
  char		*arg_redirection; /*arg exemple ls > tmp, arg : tmp*/
  char		**argv_execve;
  char		*bin_path;
  struct s_arg_transitor	*next; /*argument organise*/
  struct s_arg_transitor	*prev;
}		t_arg_transitor;

typedef struct	s_transitor
{
  int			prev_read;
  int			pipefd[2];
  char			**env;
  t_arg_transitor	*list;
}		t_transitor;

int             check_if_builtin(t_arg_transitor *arg);
int             can_execve_simple(t_arg_transitor *tmp);
int             check_or_and_after(t_arg_transitor *tmp);
int             can_execve_pipe(t_arg_transitor *tmp);
int             can_builtins_pipe(t_arg_transitor *tmp);
int             can_builtins_simple(t_arg_transitor *tmp);
char	        *fill_bin_path(t_arg_transitor *, t_transitor *);
char   	        **parse_before_checkaccess(char *str);
char	        *check_acess(char **path, char **string, char **env);
void            command_not_found(t_arg_transitor *arg);
void		    launch_command(t_transitor *transitor);
t_transitor     *add_node_transitor(t_transitor *, t_arg_transitor *);
t_transitor     *my_transitor(t_parser *parser, char **env);
t_transitor    	*transit_arg(t_arg *arg, t_transitor *transitor);
t_transitor     *init_transitor(char **env);
t_transitor    	*what_we_do_with_arg(t_transitor *, t_arg_transitor *);
t_arg_transitor     *fill_arg(t_arg *arg);

/*Builtin Alias*/

char            *alias_command(char **command);
char            **replace_alias_in_cmd(t_alias *list, char **command);
bool            change_alias(t_alias **list, char **command);
void            builtin_alias(t_arg **arg, t_alias **list);
void            free_alias(t_alias *node);
void            print_alias_list(t_alias *list);
t_alias         *add_in_alias_list(t_alias *liste, char **command);
t_alias         *create_alias(t_alias *node, char **command);
t_alias         *remove_alias(t_alias *list, char *to_remove);

/*globbing_function*/
char	**globbing_function(char **tab);

#endif /*!TRANSITION_H*/
