/*
** pipe_redirection_exist.c for pipe_redirection_exist.c in /home/sid/PSU_2016_42sh/src/parser
**
** Made by Sid
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Thu Jun  1 14:32:26 2017 Sid
** Last update Feb Jun 12 15:37:55 2017
*/

#include "parser.h"

int	pipe_exist(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '|' && str[i + 1] != '|')
	return (0);
      i++;
    }
  return (1);
}

int	redirection_exist(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '>' || str[i] == '<')
	return (0);
      i++;
    }
  return (1);
}

int redirection_right_exist(char *str)
{
  int	boole = 0;
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '>' && str[i + 1] == '>')
	return (1);
      if (str[i] == '>' && str[i + 1] != '>')
	boole++;
      i++;
    }
  if (boole == 1)
    return (0);
  return (1);
}

int redirection_left_exist(char *str)
{
  int	boole = 0;
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '<' && str[i + 1] == '<')
	return (1);
      if (str[i] == '<' && str[i + 1] != '<')
	boole++;
      i++;
    }
  if (boole == 1)
    return (0);
  return (1);
}
