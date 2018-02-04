/*
** struct_transitor.c for struct_transitor.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Jun  1 17:01:38 2017 Leo Lecherbonnier
** Last update Fri Jun  2 14:34:05 2017 Sid Djilali Saiah
*/

#include "transition.h"

t_transitor	*add_node_transitor(t_transitor *transitor,
				    t_arg_transitor *new_arg)
{
  t_arg_transitor	*tmp;

  if (transitor->list == NULL)
    {
      transitor->list = new_arg;
      transitor->list->start = true;
      transitor->list->next = new_arg;
      transitor->list->prev = new_arg;
      return (transitor);
    }
  tmp = transitor->list;
  while (tmp->next->start != true)
    tmp = tmp->next;
  tmp->next = new_arg;
  tmp->next->prev = tmp;
  tmp->next->next = transitor->list;
  transitor->list->prev = new_arg;
  return (transitor);
}
