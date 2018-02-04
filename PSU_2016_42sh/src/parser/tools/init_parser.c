/*
** init_parser.c for init_parser.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/parser/tools/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue May 30 16:00:05 2017 Leo Lecherbonnier
** Last update Sat Jun  3 14:44:42 2017 Sid Djilali Saiah
*/

#include "parser.h"

t_parser	*init_parser(char *command)
{
  t_parser	*parser;

  if ((parser = malloc(sizeof(t_parser))) == NULL)
    return (NULL);
  parser->clean_command = NULL;
  parser->command_tab = NULL;
  parser->user_command = strdup(command);
  parser->list = NULL;
  return (parser);
}
