/*
** parser_pipe.c for parser_pipe.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/parser/organise/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue May 30 16:26:01 2017 Leo Lecherbonnier
** Last update Thu Jun  8 16:52:09 2017 Sid Djilali Saiah
*/

#include "parser.h"

static void add_pipe_in_list(t_arg **arg, t_parser **parser, char **tab, int i)
{
    if (((*arg) = init_arg(tab[i])) == NULL)
      exit(84);
    if (((*arg) = create_pipe_node((*arg), i, tab)) == NULL)
      exit(84);
    if (((*parser) = add_node((*parser), (*arg))) == NULL)
      exit(84);
}

t_parser	*parser_pipe(t_parser *parser, char *str)
{
  t_arg	*arg;
  int	i = 0;
  char	**tab;

  if ((tab = create_command_tab(str, '|')) == NULL)
    return (NULL);
  while (tab[i])
    {
      if (redirection_exist(tab[i]) == 0)
	{
	  if ((parser = parser_redirection(parser, tab[i])) == NULL)
	    return (NULL);
	  if (!(parser->list->prev = create_pipe_node(parser->list->prev, i, tab)))
	    return (NULL);
	}
      else
        add_pipe_in_list(&arg, &parser, tab, i);
      i++;
    }
  return (parser);
}
