/*
** algo.c for algo.c in /home/lecherbonnier/Projet/dante/generator/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu May 11 19:46:53 2017 Leo Lecherbonnier
** Last update Jun May 12 14:16:54 2017
*/

#include "generator.h"

t_my_bool my_check_case(t_args *args, int i, int j)
{
  t_my_bool check;

  if (i - 1 != -1 && args->map[i - 1][j] == 'X')
    check.UP = true;
  else
    check.UP = false;
  if (j - 1 != -1 && args->map[i][j - 1] == 'X')
    check.LEFT = true;
  else
    check.LEFT = false;
  return (check);
}

void	where_break(t_args *args, int i, int j, t_my_bool check)
{
  if (check.UP == true && check.LEFT == false)
    args->map[i - 1][j] = '*';
  else if (check.UP == false && check.LEFT == true)
    args->map[i][j - 1] = '*';
  else if (check.UP == false && check.LEFT == false)
    rien_faire();
  else if (check.UP == true && check.LEFT == true)
    {
      if (rand() % 2 == 0)
	args->map[i - 1][j] = '*';
      else
	args->map[i][j - 1] = '*';
    }
}

void	break_wall(t_args *args)
{
  t_my_bool	check;
  int	j = 0;
  int	i = 0;

  while (args->map[i])
    {
      j = 0;
      while (args->map[i][j] != '\0')
	{
	  check = my_check_case(args, i, j);
	  where_break(args, i, j, check);
	  j = j + 2;
	}
      i = i + 2;
    }
}

void	make_finish(t_args *args)
{
  if (args->map[args->y - 1][args->x - 1] == 'X')
    args->map[args->y - 1][args->x - 1] = '*';
  if (args->map[args->y - 1][args->x - 2] == 'X')
    args->map[args->y - 1][args->x - 2] = '*';
  else if (args->map[args->y - 2][args->x - 1] == 'X')
    args->map[args->y - 2][args->x - 1] = '*';
  else if (args->map[args->y - 2][args->x - 2] == 'X')
    args->map[args->y - 2][args->x - 2] = '*';
}
