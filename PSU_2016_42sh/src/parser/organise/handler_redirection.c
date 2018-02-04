/*
** handler_redirection.c for handler_redirection.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/parser/organise/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed May 31 16:05:02 2017 Leo Lecherbonnier
** Last update Fri Jun  2 16:18:23 2017 Sid Djilali Saiah
*/

#include "parser.h"

t_parser	*handler_double_redirection_right(t_parser *parser, char *str)
{
  t_arg		*arg;
  char		**tab = NULL;

  if ((arg = init_arg(str)) == NULL)
    return (NULL);
  arg->r_double_right = true;
  if (!(tab = special_wordtab(str, ">>")))
    return (NULL);
  arg->command = strdup(tab[0]);
  arg->arg_redirection = strdup(tab[1]);
  if ((parser = add_node(parser, arg)) == NULL)
    return (NULL);
  return (parser);
}

t_parser	*handler_double_redirection_left(t_parser *parser, char *str)
{
  t_arg		*arg;
  char		**tab = NULL;

  if ((arg = init_arg(str)) == NULL)
    return (NULL);
  arg->r_double_left = true;
  if (!(tab = special_wordtab(str, "<<")))
    return (NULL);
  arg->command = strdup(tab[0]);
  arg->arg_redirection = strdup(tab[1]);
  if ((parser = add_node(parser, arg)) == NULL)
    return (NULL);
  return (parser);
}

t_parser	*handler_redirection_right(t_parser *parser, char *str)
{
  t_arg		*arg;
  char		**tab = NULL;

  if ((arg = init_arg(str)) == NULL)
    return (NULL);
  arg->r_right = true;
  if ((tab = create_command_tab(str, '>')) == NULL)
    return (NULL);
  arg->command = strdup(tab[0]);
  arg->arg_redirection = strdup(tab[1]);
  if ((parser = add_node(parser, arg)) == NULL)
    return (NULL);
  return (parser);
}

t_parser	*handler_redirection_left(t_parser *parser, char *str)
{
  t_arg		*arg;
  char		**tab = NULL;

  if ((arg = init_arg(str)) == NULL)
    return (NULL);
  arg->r_left = true;
  if ((tab = create_command_tab(str, '<')) == NULL)
    return (NULL);
  arg->command = strdup(tab[0]);
  arg->arg_redirection = strdup(tab[1]);
  if ((parser = add_node(parser, arg)) == NULL)
    return (NULL);
  return (parser);
}
