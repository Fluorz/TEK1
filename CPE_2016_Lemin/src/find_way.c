/*
** way.c for lem_in in /home/seth/afs_local/Rendu/Prog_elem/lem-in
**
** Made by kevin lansel
** Login   <lansel_k@epitech.net>
**
** Started on  Tue Apr 17 08:23:54 2012 kevin lansel
** Last update Jan Apr 30 21:43:17 2017
*/

#include "open_file.h"

int		path_finding(int temps, t_elem *room)
{
  t_link	*temporaire;

  if (room->view == 0 || temps < room->temps)
    {
      room->view = 1;
      room->temps = temps;
      temporaire = room->link;
      while (temporaire != NULL)
	{
	  path_finding(temps + 1, temporaire->way);
	  temporaire = temporaire->next;
	}
    }
  return (0);
}

int		find_road(t_elem *room, int nbr_ants)
{
  t_road	*road1 = NULL;
  t_road	*road2 = NULL;
  t_link	*temporaire1 = NULL;
  t_link	*temporaire2 = NULL;
  int		temps;

  road1 = find_init(room, road1, temporaire1, &temps);
  road2 = room_next(road2, room, temporaire2, &temps);
  if (before_return(road1, road2, nbr_ants) != SUCCESS)
    return (FAILURE);
  return (SUCCESS);
}

int	before_return(t_road	*road1, t_road	*road2, int nbr_ants)
{
  road1 = rd_ch(road1);
  road2 = rd_ch(road2);
  return (move_nbr_ants(nbr_ants, road1, road2));
}

int	move_nbr_ants(int nbr_ants, t_road *road1, t_road *road2)
{
  t_road	*end;
  t_road	*tmp;

  if (road1 == NULL || road2 == NULL)
    {
      tmp = road1;
      while (tmp->next != NULL)
	tmp = tmp->next;
      end = tmp;
    }
  if (road1 != NULL && road2 == NULL)
    only_one_possibility(nbr_ants, road1, 1, end);
  else if (road1 == NULL && road2 != NULL)
    only_one_possibility(nbr_ants, road2, 1, end);
  else if (road1 != NULL && road2 != NULL)
    two_possibilities(nbr_ants, road1, road2, 1);
  else
    return (FAILURE);
  return (SUCCESS);
}

t_road		*init_road(t_road *road, t_elem *pointeur)
{
  t_road	*elem;
  t_road	*pointeur_1;

  if ((elem = malloc(sizeof(t_road))) == NULL)
    return (NULL);
  elem->oway = pointeur;
  elem->next = NULL;
  elem->prev = NULL;
  pointeur_1 = road;
  if (road == NULL)
    road = elem;
  else
    {
      while (pointeur_1->next != NULL)
	pointeur_1 = pointeur_1->next;
      elem->prev = pointeur_1;
      pointeur_1->next = elem;
    }
  return (road);
}
