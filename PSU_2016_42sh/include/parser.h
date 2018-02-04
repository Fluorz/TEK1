/*
** parser.h for parser.h in /home/lecherbonnier/Projet/PSU_2016_42sh/include/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed May 31 16:59:53 2017 Leo Lecherbonnier
** Last update Thu Jun  8 17:36:42 2017 Sid Djilali Saiah
*/

#ifndef PARSER_H
#define PARSER_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHA_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUME_CHARS "0123456789<>|&-_~#$.:;*/ "

/* ls | cat -e*/

typedef struct	s_arg
{
  bool		start;
  bool		double_pipe;
  bool		double_and;
  bool		pipe_in; /* cat -e*/
  bool		pipe_out; /*ls*/
  bool		r_right; /*false*/
  bool		r_left; /*false*/
  bool		r_double_right; /*false*/
  bool		r_double_left; /*false*/
  char		*command; /*ls ou cat -e*/
  int		return_value; /*return value de la command*/
  int		fd_out; /*si ca ete pipe "ls"*/
  int		fd_in; /*si il y en a besoin "cat -e"*/
  char		*arg_redirection; /*arg exemple ls > tmp, arg : tmp*/
  struct s_arg		*next; /*argument organise*/
  struct s_arg		*prev;
}		t_arg;

typedef struct	s_alias
{
  char              *alias;
  char		        *command;
  struct s_alias	*next;
}		t_alias;

typedef struct	s_parser
{
  char		*user_command;
  char		*clean_command; /*epur_str*/
  char		**command_tab; /*str_to_word_tab sur ';' seulement*/
  t_arg		*list;
}		t_parser;

int         tablen(char **);
int		    pipe_exist(char *str);
int		    redirection_exist(char *str);
int     	double_pipe_exist(char *str);
int     	double_and_exist(char *str);
int     	double_right_exist(char *str);
int     	double_left_exist(char *str);
int 		redirection_right_exist(char *str);
int 		redirection_left_exist(char *str);
int		    pipe_exist(char *str);
int		    redirection_exist(char *str);
int         error_handling(char *str);
int         invalid_pipe(char **tab, int i);
int         invalid_double_pipe(char **tab, int i);
int         invalid_double_and(char **tab, int i);
int         invalid_redirect(char **tab, int i);
int         invalid_double_redirect(char **tab, int i);
int         check_empty_cmd(char *command);
int         check_invalid_operators(char *str);
int         check_other_operators(char **tab, int i);
int         check_operators_errors(char **tab, int i);
char		**special_wordtab(char *str, char *sep);
char		**create_command_tab(char *str, char c);
char		*epur_str(char *str);
char        **tabdup(char **from, char **dest);
char		**create_command_tab(char *str, char c);
char        *my_getenv(char **env, char *str);
void        freetab(char **tab);
t_arg		*init_arg(char *str);
t_arg		*create_pipe_node(t_arg *new_node, int index, char **tab);
t_arg		*init_arg(char *str);
t_parser	*init_parser(char *command);
t_parser	*my_parser(char	*command, int *return_parser);
t_parser	*add_node(t_parser *parser, t_arg *arg);
t_parser	*parser_pipe(t_parser *parser, char *str);
t_parser	*organise(char *str, t_parser *parser);
t_parser	*parser_redirection(t_parser *parser, char *str);
t_parser	*add_node(t_parser *parser, t_arg *arg);
t_parser	*init_parser(char *command);
t_parser	*double_pipe_handler(t_parser *parser, char *str);
t_parser	*double_and_handler(t_parser *parser, char *str);
t_parser	*create_cmd_list(t_parser *parser);
t_parser	*double_pipe_handler(t_parser *parser, char *str);
t_parser	*double_and_handler(t_parser *parser, char *str);
t_parser	*handler_double_redirection_right(t_parser *parser, char *str);
t_parser	*handler_double_redirection_left(t_parser *parser, char *str);
t_parser	*handler_redirection_right(t_parser *parser, char *str);
t_parser	*handler_redirection_left(t_parser *parser, char *str);
t_parser	*simple_command(t_parser *parser, char *str);

#endif /*!PARSER_H*/
