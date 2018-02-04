/*
** linked_list_misc.c for tetris in /home/monty/Documents/Rendu/tetris/PSU_2016_tetris/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sat Mar 18 13:54:01 2017 Monty Criel
** Last update Sat Mar 18 14:01:41 2017 Monty Criel
*/

#include "linked_list.h"
#include "tetris.h"

void	add_node(t_list *list, t_node *node, char *file, char *name)
{
  init_node(node, file, name);
  append_tail(list, node);
  free(file);
}

t_list	*empty_list(t_list *list)
{
  if (list == NULL)
    return (NULL);
  else
    return (list);
}
