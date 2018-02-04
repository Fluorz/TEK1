/*
** two_road.c for second_road.c in /home/lecherbonnier/Projet/CPE_2016_Lemin/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sun Apr 30 14:48:36 2017 Leo Lecherbonnier
** Last update Jan Apr 30 20:41:38 2017
*/

#include "open_file.h"

void	two_possibilities(int nb_ants, t_road *road1, t_road *road2, int i)
{
  t_road	*move;
  t_road	*move2;
  t_road	*end;
  t_road	*tmp;

  tmp = road1;
  while (tmp->next != NULL)
    tmp = tmp->next;
  move = tmp;
  tmp = road2;
  while (tmp->next != NULL)
    tmp = tmp->next;
  move2 = tmp;
  tmp = road1;
  while (tmp->next != NULL)
    tmp = tmp->next;
  end = tmp;
  while (end->oway->empty <= nb_ants)
    {
      move = first_step(road1);
      second_step(road1, move, end, nb_ants, &i);
      move2 = first_step(road2);
      third_step(move2, end, road2, nb_ants, &i);
    }
  my_printf("\n");
}

int	third_step(t_road *move2, t_road *end, t_road *road2, int nb_ants,
		    int	*i)
{
  road2->oway->empty = *i;
  while (move2 != NULL && end->oway->empty <= nb_ants)
    {
      if (move2->oway->empty == 0)
	move2 = move2->prev;
      else
	{
	  move2->next->oway->empty = move2->oway->empty;
	  if (move2->next->oway->empty <= nb_ants)
	    my_printf("P%d-%s", move2->next->oway->empty, move2->next->oway->name);
	  if (move2->oway->prev != NULL)
	    {
	      if (move2->oway->empty < nb_ants)
		my_printf(" ");
	      move2->oway->empty = 0;
	    }
	  else
	    {
	      move2->oway->empty = (*i)++;
	      my_printf("\n");
	    }
	  move2 = move2->prev;
	}
    }
  return (0);
}

int	second_step(t_road *road1, t_road *move, t_road *end, int nb_ants,
		    int	*i)
{
  road1->oway->empty = *i;
  while (move != NULL && end->oway->empty <= nb_ants)
    {
      if (move->oway->empty == 0)
	move = move->prev;
      else
	{
	  move->next->oway->empty = move->oway->empty;
  	  if (move->next->oway->empty <= nb_ants)
	    my_printf("P%d-%s", move->next->oway->empty, move->next->oway->name);
	  if (move->oway->prev != NULL)
	    {
	      if (move->oway->empty < nb_ants)
		my_printf(" ");
	      move->oway->empty = 0;
  	    }
	  else
	    {
	      move->oway->empty = (*i)++;
	      my_printf(" ");
	    }
	  move = move->prev;
	}
    }
  return (0);
}

t_road	*first_step(t_road *road)
{
  t_road	*tmp;

  tmp = road;
  while (tmp->next != NULL)
    tmp = tmp->next;
  road = tmp;
  road->oway->empty = 0;
  return (road);
}
