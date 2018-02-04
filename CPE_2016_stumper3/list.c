/*
** list.c for list in /home/ferlet_n/colle/CPE_2016_stumper3
** 
** Made by Nicolas Ferlet
** Login   <ferlet_n@epitech.net>
** 
** Started on  Tue May  2 07:55:51 2017 Nicolas Ferlet
** Last update Tue May  2 09:18:08 2017 Nicolas Ferlet
*/

#include "my.h"

t_word		*create_node(char *str)
{
  t_word	*new;

  if (!(new = malloc(sizeof(t_word))))
    return (NULL);
  new->str = str;
  new->next = NULL;
  return (new);
}

void		add_node(t_word **list, char *str)
{
  t_word	*beg;

  beg = *list;
  if (*list == NULL)
    {
      *list = create_node(str);
      return ;
    }
  while ((*list)->next != NULL)
    *list = (*list)->next;
  (*list)->next = create_node(str);
  *list = beg;
}

void		remove_one(t_word **list, t_word **to_delete)
{
  t_word	*keep;
  t_word	*begin;

  if (*to_delete == NULL)
    return ;
  if (*to_delete == *list)
    {
      keep = *to_delete;
      *list = (*list)->next;
      free(keep->str);
      free(keep);
      return ;
    }
  begin = *list;
  while ((*list)->next != *to_delete)
    *list = (*list)->next;
  keep = (*list)->next;
  (*list)->next = (*list)->next->next;
  free(keep->str);
  free(keep);
  *list = begin;
}
