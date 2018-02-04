/*
** parser_pipe.c for parser_pipe.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/parser/organise/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue May 30 16:26:01 2017 Leo Lecherbonnier
** Last update Feb Jun 12 15:17:04 2017
*/

#include "parser.h"

t_parser	*parser_redirection(t_parser *parser, char *str)
{
  if (redirection_right_exist(str) == 0)
    parser = handler_redirection_right(parser, str);
  else if (redirection_left_exist(str) == 0)
    parser = handler_redirection_left(parser, str);
  else if (double_right_exist(str) == 0)
    parser = handler_double_redirection_right(parser, str);
  else if (double_left_exist(str) == 0)
    parser = handler_double_redirection_left(parser, str);
  else
    return (NULL);
  return (parser);
}
