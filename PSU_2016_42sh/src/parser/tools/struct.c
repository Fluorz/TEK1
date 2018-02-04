/*
** struct.c for struct.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/parser/tools/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue May 30 16:49:49 2017 Leo Lecherbonnier
** Last update Thu Jun  1 16:50:39 2017 Sid Djilali Saiah
*/

#include "parser.h"

t_arg	*init_arg(char *str)
{
  t_arg	*new_node;

  if ((new_node = malloc(sizeof(t_arg))) == NULL)
    return (NULL);
  new_node->start = false;
  new_node->double_pipe = false;
  new_node->double_and = false;
  new_node->pipe_in = false;
  new_node->pipe_out = false;
  new_node->r_right = false;
  new_node->r_left = false;
  new_node->r_double_right = false;
  new_node->r_double_left = false;
  new_node->command = strdup(str);
  new_node->return_value = 0;
  new_node->arg_redirection = NULL;
  new_node->fd_out = 0;
  new_node->fd_in = 0;
  new_node->next = NULL;
  new_node->prev = NULL;
  return (new_node);
}

t_parser	*add_node(t_parser *parser, t_arg *arg)
{
  t_arg		*tmp;

  if (parser->list == NULL)
    {
      parser->list = arg;
      parser->list->start = true;
      parser->list->next = arg;
      parser->list->prev = arg;
      return (parser);
    }
  tmp = parser->list;
  while (tmp->next->start != true)
    tmp = tmp->next;
  tmp->next = arg;
  tmp->next->prev = tmp;
  tmp->next->next = parser->list;
  parser->list->prev = arg;
  return (parser);
}

t_arg	*create_pipe_node(t_arg *new_node, int index, char **tab)
{
  if (index == 0)
    {
      new_node->pipe_in = false;
      new_node->pipe_out = true;
    }
  else if (index - 1 != -1 && tab[index + 1] != NULL)
    {
      new_node->pipe_in = true;
      new_node->pipe_out = true;
    }
  else if (tab[index + 1] == NULL)
    {
      new_node->pipe_in = true;
      new_node->pipe_out = false;
    }
  return (new_node);
}
