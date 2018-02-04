/*
** double_pipe_&&.c for &&.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/parser/organise/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed May 31 14:51:45 2017 Leo Lecherbonnier
** Last update Jan Jun 4 22:28:36 2017
*/

#include "parser.h"

t_parser	*double_pipe_handler(t_parser *parser, char *str)
{
  int		i = 0;
  char		**tab = NULL;

  if ((tab = special_wordtab(str, "||")) == NULL)
    return (NULL);
  if (tab[0] == NULL || tab[1] == NULL)
    return (NULL);
  while (tab[i])
    {
      parser = organise(tab[i], parser);
      if (tab[i + 1] != NULL)
	parser->list->prev->double_pipe = true;
      i++;
    }
  return (parser);
}

t_parser	*double_and_handler(t_parser *parser, char *str)
{
  int		i = 0;
  char		**tab = NULL;

  if ((tab = special_wordtab(str, "&&")) == NULL)
    return (NULL);
  if (tab[0] == NULL || tab[1] == NULL)
    return (NULL);
  while (tab[i])
    {
      parser = organise(tab[i], parser);
      if (tab[i + 1] != NULL)
	parser->list->prev->double_and = true;
      i++;
    }
  return (parser);
}
