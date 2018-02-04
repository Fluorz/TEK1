/*
** one_road.c for lem_in in /home/seth/Desktop/Lem INNNNN
**
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
**
** Started on  Sun Apr 22 21:57:41 2012 kevin lansel
** Last update Jan Apr 30 21:50:23 2017
*/

#include "open_file.h"

t_road		*rd_ch(t_road *road)
{
  t_road	*temporaire;

  if (road != NULL)
    {
      temporaire = road;
      while (temporaire->next != NULL)
	temporaire = temporaire->next;
      if (temporaire->oway->temps == 0)
	return (road);
      else
	return (NULL);
    }
  else
    return (NULL);
}

t_road	*find_init(t_elem *room, t_road *road1, t_link *temporaire1,
		   int *temps)
{
  road1 = init_road(road1, room);
  room->view = 0;
  temporaire1 = room->link;
  *temps = room->temps;
  road(road1, *temps, temporaire1, 1);
  return (road1);
}

t_road	*room_next(t_road *road2, t_elem *room, t_link *temporaire2,
		   int *temps)
{
  if (room->link->next != NULL)
    {
      road2 = init_road(road2, room);
      temporaire2 = room->link;
      *temps = room->temps;
      road(road2, *temps, temporaire2, 2);
    }
  return (road2);
}

void		transform_rd(t_road *move, t_road *end, int nbr_ants, int *i)
{
  while (move != NULL && end->oway->empty <= nbr_ants)
    {
      if (move->oway->empty == 0)
	move = move->prev;
      else
	{
	  move->next->oway->empty = move->oway->empty;
	  if (move->next->oway->empty <= nbr_ants)
	    my_printf("P%d-%s", move->next->oway->empty, move->next->oway->name);
	  if (move->oway->prev != NULL && move->oway->empty < nbr_ants)
	    my_printf(" ");
	  if (move->oway->prev != NULL && move->oway->empty != 0)
	      move->oway->empty = 0;
	  else
	    {
	      move->oway->empty = (*i)++;
	      my_printf("\n");
	    }
	  move = move->prev;
	}
    }
}

void	only_one_possibility(int nbr_ants, t_road *road, int i, t_road *end)
{
  t_road	*move;
  t_road	*end_else;

  while (end->oway->empty <= nbr_ants)
    {
      end_else = road;
      while (end_else->next != NULL)
        end_else = end_else->next;
      move = end_else;
      move->oway->empty = 0;
      road->oway->empty = i;
      transform_rd(move, end, nbr_ants, &i);
    }
}
