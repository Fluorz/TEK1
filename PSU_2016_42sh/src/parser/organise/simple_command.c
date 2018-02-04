/*
** simple_command.c for simple_command.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/parser/organise/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed May 31 15:33:08 2017 Leo Lecherbonnier
** Last update May Jun 1 10:08:19 2017
*/

#include "parser.h"

t_parser	*simple_command(t_parser *parser, char *str)
{
  t_arg		*arg;

  if ((arg = init_arg(str)) == NULL)
    return (NULL);
  if ((parser = add_node(parser, arg)) == NULL)
    return (NULL);
  return (parser);
}
