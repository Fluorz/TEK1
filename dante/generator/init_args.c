/*
** init_args.c for init_args in /home/hugo/cours/Code/Semestre 2/Initiation IA/dante/generator/src/
**
** Made by Hugo Bleuzen
** Login   <hugo.bleuzen@epitech.eu>
**
** Started on  Wed May  3 17:55:02 2017 Hugo Bleuzen
** Last update Jul May 13 12:52:17 2017
*/

#include <stdio.h>
#include "generator.h"

int	my_str_isnum(char *str)
{
  int	i = 0;

  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (1);
      i++;
    }
  return (0);
}

int	init_args(t_args *args, char *x, char *y, char *str)
{
  if (my_str_isnum(x) == 0 && my_str_isnum(y) == 0)
    {
      if (my_getnbr(x) >= 2 && my_getnbr(y) >= 2)
	{
	  args->x = my_getnbr(x);
	  args->y = my_getnbr(y);
	}
      else
	return (FAILURE);
    }
  else
    return (FAILURE);
  if (my_strcmp("perfect", str) == 0)
    args->type = str;
  else if (my_strcmp("imperfect", str) == 0)
    args->type = str;
  else
    return (FAILURE);
  return (0);
}
