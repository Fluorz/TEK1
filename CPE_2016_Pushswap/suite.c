/*
** suite.c for suite.c in /root/Desktop/CPE_2016_Pushswap/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Sat Nov 26 11:10:52 2016 Leo Lecherbonnier
** Last update Sat Nov 26 11:11:34 2016 Leo Lecherbonnier
*/

#include "pushswap.h"

int		create_list(t_liste **list, int a)
{
  t_liste	*node;

  if (*list == NULL)
    {
      *list = malloc(sizeof(t_liste));
      (*list)->nbr = a;
      (*list)->next = *list;
      (*list)->prev = *list;
      return (0);
    }
  node = (*list)->prev;
  node->next = NULL;
  if ((node->next = malloc(sizeof(t_liste))) == NULL)
    return (-1);
  node->next->nbr = a;
  node->next->next = *list;
  node->next->prev = node;
  (*list)->prev = node->next;
  return (0);
}
