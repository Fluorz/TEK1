/*
** parse_list.c for parse_list.c in /home/lecherbonnier/Projet/PSU_2016_tetris/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sun Feb 26 16:10:11 2017 Leo Lecherbonnier
** Last update Mon Feb 27 09:27:56 2017 Leo Lecherbonnier
*/

#include "tetris.h"

t_debug	parse_list(char **list, int ac, t_debug debug)
{
  int	len = ac;
  int	x = 0;
  int	j = 1;

  debug.list = malloc(sizeof(char) * ac);
  while (j != len)
    {
      debug.list[x] = malloc(sizeof(char) *  my_strlen(list[j]) + 1);
      if (list[j][0] == '-' && list[j][1] == '-'
	  && (my_strcmp(list[j], "--debug")
	  != 0) && (my_strcmp(list[j], "--without-next") != 0)
	  && (my_strcmp(list[j], "--help") != 0))
	{
    debug.list = convert_arg(list[j], debug, x);
	  x++;
	}
    else
	debug.list[x] = list[j];
      j++;
      x++;
    }
  debug.len_list = x;
  return (debug);
}

char	*convert_argument_minus(char *str)
{
  if (my_strcmp(str, "--level") == 0)
    return ("-l");
  if (my_strcmp(str, "--key-left") == 0)
    return ("-kl");
  if (my_strcmp(str, "--key-right") == 0)
      return ("-kr");
  if (my_strcmp(str, "--key-turn") == 0)
    return ("-kt");
  if (my_strcmp(str, "--key-drop") == 0)
    return ("-kd");
  if (my_strcmp(str, "--key-quit") == 0)
    return ("-kq");
  if (my_strcmp(str, "--key-pause") == 0)
    return ("-kp");
  if (my_strcmp(str, "--map-size") == 0)
    return ("--map-size");
  if (my_strcmp(str, "--without-next") == 0)
    return ("-w");
  if (my_strcmp(str, "--debug") == 0)
    return ("-d");
  return (NULL);
}

char	**convert_arg(char *str, t_debug debug, int j)
{
  char	*string;
  int	i = 0;
  int	index = 0;

  string = malloc(sizeof(char) * my_strlen(str));
  while (str[i] != '=')
    {
      string[i] = str[i];
      i++;
    }
  string[i] = '\0';
  if (!(string = convert_argument_minus(string)))
    exit (0);
  debug.list[j] = string;
  debug.list[j + 1] = malloc(sizeof(char) * my_strlen(str));
  i++;
  if (str[i] == '{')
      i++;
  while (str[i] != '\0' && str[i] != '}')
    {
      debug.list[j + 1][index] = str[i];
      index++;
      i++;
    }
  return (debug.list);
}
