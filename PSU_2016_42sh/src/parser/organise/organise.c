/*
** organise.c for organise.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/parser/organise/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue May 30 16:14:38 2017 Leo Lecherbonnier
** Last update Thu Jun  8 11:35:53 2017 Sid Djilali Saiah
*/

#include "parser.h"

t_parser	*create_cmd_list(t_parser *parser)
{
  int		i = 0;

  while (parser->command_tab[i])
    {
      if (double_pipe_exist(parser->command_tab[i]) == 0)
	{
	  if ((parser = double_pipe_handler(parser,
                                        parser->command_tab[i])) == NULL)
	    return (NULL);
	}
      else if (double_and_exist(parser->command_tab[i]) == 0)
	{
	  if ((parser = double_and_handler(parser,
                                        parser->command_tab[i])) == NULL)
	    return (NULL);
	}
      else
	{
	  if ((parser = organise(parser->command_tab[i], parser)) == NULL)
	    return (NULL);
	}
      i++;
    }
  return (parser);
}

t_parser	*organise(char *str, t_parser *parser)
{
  if (pipe_exist(str) == 0)
    {
      if ((parser = parser_pipe(parser, str)) == NULL)
	return (NULL);
    }
  else if (redirection_exist(str) == 0)
    {
      if ((parser = parser_redirection(parser, str)) == NULL)
	return (NULL);
    }
  else
    {
      if ((parser = simple_command(parser, str)) == NULL)
	return (NULL);
    }
  return (parser);
}
