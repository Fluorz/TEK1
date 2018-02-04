/*
** sid.h for corewar in /home/sid/Corewar
**
** Made by Sid
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Mon Mar 27 15:14:56 2017 Sid
** Last update Mon Apr  3 00:05:56 2017 Sid
*/

#ifndef ERROR_H
#define ERROR_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "op.h"
#include "my.h"

typedef struct s_error
{
  char	**av;
  char	*file_name;
  char	**file;
  char	**labels;
  char	**instruction;
}		t_error;

int     my_opener(char *av);
char	*check_label(char *str, char *file);
void   	display_help(char *name);
int     nb_lines(char *file_name);
char    **my_reader(char *file_name);
char    **str_to_wordtab(char *str, char c);
int     check_name(char *str, char *av);
int     check_comment(char *str, char *av);
int     find_label(char *str);
char    *my_str_dup(char *dest, char *src);
char    **labels_tab(char **tab, char *file);
char	   **find_instruction(char *line);
int	check_instruct(char **instruct, char **labels,
		       char *line, char *file_name);
int check_args_types(char **instruction, char **labels, char *line, int i);
int	check_nbr_arg(char **instruction, char *line, char *file_name, int i);
t_error	error_handling(t_error error, char **av);
char    *my_parse_str(int s, int e, char *str);
int	check_instruct(char **instruction, char **labels,
		       char *line, char *file_name);

#endif /*ERROR_H*/
