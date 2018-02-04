/*
** pair_et_impair.c for pair.c in /home/lecherbonnier/Projet/dante/generator/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu May 11 20:04:52 2017 Leo Lecherbonnier
** Last update Jun May 12 12:27:33 2017
*/

#include "generator.h"

void	pair_line(t_args *args, int index)
{
  int	i = 0;

  while (args->map[index][i] != '\0')
    {
      if (i % 2 == 0)
	args->map[index][i] = '*';
      else
	args->map[index][i] = 'X';
      i++;
    }
}

void	impair_line(t_args *args, int index)
{
  int	i = 0;

  while (args->map[index][i] != '\0')
    {
      args->map[index][i] = 'X';
      i++;
    }
}
