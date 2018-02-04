/*
** my_road.c for road.c in /home/lecherbonnier/Projet/CPE_2016_Lemin/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sun Apr 30 14:48:05 2017 Leo Lecherbonnier
** Last update Jan Apr 30 21:50:43 2017
*/

#include "open_file.h"

t_elem		*road_link(t_link *tmp, int *temps, int boole)
{
  t_elem		*ptr;

  ptr = NULL;
  while (tmp != NULL)
    {
      if (tmp->way->view == 1 && (*temps) != 0 && boole == 2)
	{
	  tmp->way->view = 0;
	  (*temps) = tmp->way->temps;
	  ptr = tmp->way;
	}
      if (tmp->way->view == 1 && (*temps) > tmp->way->temps && boole == 1)
	{
	  tmp->way->view = 0;
	  (*temps) = tmp->way->temps;
	  ptr = tmp->way;
	}
      tmp = tmp->next;
    }
  if (ptr == NULL)
    (*temps) = 0;
  return (ptr);
}

t_link	*road_else(t_elem *pointeur, t_link *temporaire, t_road *road,
		   int boole)
{
  if (pointeur != NULL)
    {
      temporaire->way->view = 0;
      temporaire = pointeur->link;
      init_road(road, pointeur);
      if (pointeur->temps == 0 && boole == 1)
	pointeur->view = 1;
    }
  else
    temporaire = NULL;
  return (temporaire);
}

void		road(t_road *road, int temps, t_link *temporaire, int boole)
{
  t_elem		*pointeur;

  while (temps >= 0 && temporaire != NULL)
    {
      pointeur = road_link(temporaire, &temps, boole);
      temporaire = road_else(pointeur, temporaire, road, boole);
    }
}
