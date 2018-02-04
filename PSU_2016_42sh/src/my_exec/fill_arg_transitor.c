/*
** fill_arg_transitor.c for 42sh in /home/sid/PSU_2016_42sh/src/parser/tools/
**
** Made by Sid Djilali Saiah
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Thu Jun  1 16:25:39 2017 Sid Djilali Saiah
** Last update Jun Jun 2 15:20:47 2017
*/

#include <string.h>
#include "parser.h"
#include "transition.h"

char	*my_strdup(char *src)
{
  char	*dest;
  int	max;

  if (src == NULL)
    return (NULL);
  max = strlen(src) + 1;
  dest = malloc(sizeof (char) * max);
  strcpy(dest, src);
  return (dest);
}

t_arg_transitor     *fill_arg(t_arg *arg)
{
  t_arg_transitor	*new_node;

  if ((new_node = malloc(sizeof(t_arg_transitor))) == NULL)
    return (NULL);
  new_node->start = arg->start;
  new_node->double_pipe = arg->double_pipe;
  new_node->double_and = arg->double_and;
  new_node->pipe_in = arg->pipe_in;
  new_node->pipe_out = arg->pipe_out;
  new_node->r_right = arg->r_right;
  new_node->r_left = arg->r_left;
  new_node->r_double_right = arg->r_double_right;
  new_node->r_double_left = arg->r_double_left;
  new_node->builtins = false;
  new_node->return_value = 0;
  new_node->fd_out = 0;
  new_node->fd_in = 0;
  new_node->arg_redirection = my_strdup(arg->arg_redirection);
  if (!(new_node->argv_execve = create_command_tab(arg->command, ' ')))
    return (NULL);
  new_node->bin_path = NULL;
  new_node->next = NULL;
  new_node->prev = NULL;
  return (new_node);
}
