/*
** new_game_else.c for new_game_else.c in /home/lecherbonnier/Projet/CPE_2016_Lemin/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri Apr 28 16:56:50 2017 Leo Lecherbonnier
** Last update Jan Apr 30 16:47:18 2017
*/

#include "open_file.h"

t_elem		*init_new_elem(char *line)
{
  char		**tab;
  t_elem	*new_elem;

  if ((new_elem = malloc(sizeof(t_elem))) == NULL)
    return (NULL);
  tab = my_str_to_wordtab(line, ' ');
  if ((new_elem->name = malloc(sizeof(char) * my_strlen(line))) == NULL)
    return (NULL);
  my_strcpy(new_elem->name, tab[0]);
  new_elem->x = my_getnbr(tab[1]);
  new_elem->y = my_getnbr(tab[2]);
  new_elem->temps = -1;
  new_elem->view = 0;
  new_elem->view = 0;
  new_elem->next = NULL;
  new_elem->prev = NULL;
  new_elem->link = NULL;
  return (new_elem);
}

int	graph_init(t_elem **elem, char *line)
{
  t_elem	*new_elem;
  t_elem	*pointeur = *elem;

  if ((new_elem = init_new_elem(line)) == NULL)
    return (FAILURE);
  if (*elem == NULL)
    *elem = new_elem;
  else
    {
      while (pointeur->next != NULL)
	pointeur = pointeur->next;
      new_elem->prev = pointeur;
      pointeur->next = new_elem;
    }
  return (SUCCESS);
}

int		init_link(t_elem *elem, t_elem *pointeur)
{
  t_link	*new_pointeur;
  t_link	*new_elem;

  if ((new_elem = malloc(sizeof(t_link))) == NULL)
    return (FAILURE);
  new_elem->way = pointeur;
  new_elem->next = NULL;
  new_elem->prev = NULL;
  new_pointeur = elem->link;
  if (elem->link == NULL)
    elem->link = new_elem;
  else
    {
      while (new_pointeur->next != NULL)
	new_pointeur = new_pointeur->next;
      new_elem->prev = new_pointeur;
      new_pointeur->next = new_elem;
    }
  return (SUCCESS);
}

int		node_linker(t_elem **elem, t_elem *nod1, t_elem *nod2)
{
  t_elem		*pointeur;

  pointeur = *elem;
  if (nod1 == NULL || nod2 == NULL)
    return (FAILURE);
  while (pointeur != NULL && my_strcmp(pointeur->name, nod1->name) == 1)
    pointeur = pointeur->next;
  if (pointeur == NULL)
    return (FAILURE);
  if (my_strcmp(pointeur->name, nod1->name) == 0)
    init_link(pointeur, nod2);
  pointeur = *elem;
  while (pointeur != NULL && my_strcmp(pointeur->name, nod2->name) == 1)
    pointeur = pointeur->next;
  if (pointeur == NULL)
   return (FAILURE);
  if (my_strcmp(pointeur->name, nod2->name) == 0)
    init_link(pointeur, nod1);
  return (SUCCESS);
}

t_elem		*my_node_create(char *name, t_elem **elem)
{
  t_elem		*pointeur;

  pointeur = *elem;
  while (pointeur != NULL)
    {
      if (my_strcmp(name, pointeur->name) == 0)
	return (pointeur);
      pointeur = pointeur->next;
    }
  return (NULL);
}
