/*
** new_algo.c for new_algo.c in /home/lecherbonnier/Projet/dante/astar/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu May 11 13:18:41 2017 Leo Lecherbonnier
** Last update Jul May 13 19:20:30 2017
*/

#include "profondeur.h"

void		add(t_stack **list, int index)
{
  t_stack	*tmp;

  if ((tmp = malloc(sizeof(t_stack))) == NULL)
    exit (0);
  if (tmp != NULL)
    {
      tmp->index = index;
      tmp->prev = (*list);
      (*list)  = tmp;
    }
}

void		up(t_stack **list)
{
  t_stack	*tmp;

  if (list != NULL)
    {
      tmp = (*list)->prev;
      free(*list);
      (*list) = NULL;
      (*list) = tmp;
    }
}

int	check_neighbour(int *index, char *map, int len, int len_line)
{
  if (*index + len_line < len && map[*index + len_line] == UNVISITED)
    {
      *index = *index + len_line;
    }
  else if (*index + 1 <= len && map[*index + 1] == UNVISITED)
    {
      *index = *index + 1;
    }
  else if (*index - len_line >= 0 && map[*index - len_line] == UNVISITED)
    *index = *index - len_line;
  else if (*index - 1 >= 0 && map[*index - 1] == UNVISITED)
    *index = *index - 1;
  else
    return (0);
  return (1);
}

char	*before_neighbour(t_solver *maze, int *index,
			  t_stack **list, char *map)
{
  if (check_neighbour(index, map, maze->len, maze->line_len) == 0)
    {
      map[*index] = VISITED;
      maze->good_one[*index] = '*';
      up(list);
      *index = (*list)->index;
      while ((*list)->prev != NULL &&
	     check_neighbour(index, map, maze->len, maze->line_len) == 0)
	{
	  map[*index] = VISITED;
	  maze->good_one[*index] = '*';
	  up(list);
	  if ((*list)->index < 0 || (*list)->index > maze->len)
	    my_error("no solution found", 84);
	  if ((*list)->prev != NULL)
	    *index = (*list)->index;
	}
      if (*index <= 0 || *index >= maze->len)
	my_error("no solution found", 84);
    }
  return (map);
}

char	*algorithm(t_stack *list, t_solver *maze, char *map)
{
  int	index;

  index = 0;
  add(&list, 0);
  if ((maze->good_one = malloc(sizeof(char) * maze->len + 2)) == NULL)
    return (NULL);
  maze->good_one = strcpy(maze->good_one, map);
  map[0] = PATH;
  maze->good_one[0] = PATH;
  while (list != NULL)
    {
      before_neighbour(maze, &index, &list, map);
      map[index] = PATH;
      maze->good_one[index] = PATH;
      add(&list, index);
      if (index == maze->len - 2)
	return (maze->good_one);
    }
  return (NULL);
}
