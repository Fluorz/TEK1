/*
** parser.c for parser.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/parser/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue May 30 15:49:52 2017 Leo Lecherbonnier
** Last update May Jun 15 16:03:23 2017
*/

#include "parser.h"

void	print_chain(t_parser *parser)
{
  t_arg	*tmp;

  if (!parser->list)
    return;
  tmp = parser->list;
  tmp = tmp->next;
  while (tmp->start != true)
    tmp = tmp->next;
}

t_parser	*my_parser(char	*command, int *return_parser)
{
  t_parser	*parser;

  if (check_empty_cmd(command) == 0)
    return (NULL);
  (void)return_parser;
  if (error_handling(command) != 0)
  {
    *return_parser = 1;
    return (NULL);
  }
  if (!(parser = init_parser(command)))
    return (NULL);
  if ((parser->command_tab = create_command_tab(command, ';')) == NULL)
      return (NULL);
  if (parser->command_tab[0] == NULL)
    parser->command_tab[0] = strdup(";");
  if ((parser = create_cmd_list(parser)) == NULL)
    return (NULL);
  print_chain(parser);
  return (parser);
}
