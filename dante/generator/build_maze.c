/*
** build_maze.c for bluid_maze.c in /home/hugo/cours/Code/Semestre 2/Initiation IA/dante/generator/src/
**
** Made by Hugo Bleuzen
** Login   <hugo.bleuzen@epitech.eu>
**
** Started on  Wed May  3 17:54:26 2017 Hugo Bleuzen
** Last update Jul May 13 16:54:48 2017
*/

#include <unistd.h>
#include "generator.h"

void	print_maze(t_args *args)
{
  int	len;
  int x;

  x = 0;
  len = my_strlen(args->map[0]);
  while (args->map[x])
    {
      if ((write(1, args->map[x], len)) < 0)
	exit (84);
      free (args->map[x]);
      if (args->map[x + 1] != NULL)
	my_putchar('\n');
      x++;
    }
  free(args->map);
}

void	build_maze(t_args *args)
{
  int	i = 0;

  if (!(args->map = malloc(sizeof(char *) * (args->y + 1))))
      exit (84);
  while (i != args->y)
    {
      if ((args->map[i] = malloc(sizeof(char *) * args->x + 2)) == NULL)
	exit (84);
      memset(args->map[i], 'X', args->x);
      args->map[i][args->x] = '\0';
      args->map[i][args->x + 1] = '\0';
      i++;
    }
  args->map[i] = NULL;
}

void	build_pre_maze(t_args *args)
{
  int	i = 0;

  while (args->map[i])
    {
      if (i % 2 == 0)
	pair_line(args, i);
      else
	impair_line(args, i);
      i++;
    }
}

int	create_maze(t_args *args)
{
  if (my_strcmp("perfect", args->type) == 0)
    {
      build_maze(args);
      build_pre_maze(args);
      break_wall(args);
      make_finish(args);
    }
  else if (my_strcmp("imperfect", args->type) == 0)
    {
      build_maze(args);
      build_pre_maze(args);
      break_wall(args);
      make_finish(args);
      make_imperfect(args);
      make_finish(args);
    }
  else
    return (1);
  return (0);
}
