/*
** new_main.c for new_main.c in /home/lecherbonnier/Projet/dante/astar/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu May 11 13:09:29 2017 Leo Lecherbonnier
** Last update Jul May 13 20:01:29 2017
*/

#include "profondeur.h"

static int	display(char *map, int len)
{
  if ((write(1, map, len)) < 0)
    return (0);
  return (0);
}

int		get_len_line(char *map)
{
  int	i;

  i = 0;
  while (map[i] != '\n' && map[i] != '\0')
    i++;
  return (i);
}

int	my_error(char *str, int erreur)
{
  printf("%s\n", str);
  exit (erreur);
}

int		main(int ac, char **av)
{
  t_solver	maze;
  t_stack	list;
  char 		*map;
  char		*new_map;
  int		len;

  if (ac != 2)
    my_error("Need a file", 84);
  if ((map = fs_open_file(av[1])) == NULL)
    return (84);
  len = strlen(map);
  if (map[len - 1] == '\n')
    maze.len = len;
  else
    maze.len = len + 1;
  maze.line_len = get_len_line(map) + 1;
  if ((new_map = algorithm(&list, &maze, map)) == NULL)
    my_error("no solution found", 84);
  display(new_map, maze.len);
  return (0);
}
