/*
** sort_list.c for tetris in /home/monty/Documents/Rendu/tetris/PSU_2016_tetris/monty/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Fri Mar 10 17:50:43 2017 Monty Criel
** Last update Sun Mar 12 16:13:53 2017 Monty Criel
*/

#include "tetris.h"
#include "my.h"

int		check_list(t_list *list)
{
  t_node	*tmp;
  int		bol;

  tmp = list->head;
  bol = 0;
  while (tmp->next != NULL)
    {
      if (my_strcmp(tmp->name, tmp->next->name) > 0)
	bol = 1;
      tmp = tmp->next;
    }
  if (bol == 0)
    return (0);
  else
    return (-1);
}
void		swap(t_node *node1, t_node *node2)
{
  char		*name;
  char		**tetrimino;
  int		status;

  name = node1->name;
  tetrimino = node1->tetrimino;
  status = node1->status;
  node1->name = node2->name;
  node1->tetrimino = node2->tetrimino;
  node1->status = node2->status;
  node2->name = name;
  node2->tetrimino = tetrimino;
  node2->status = status;
}

void		sort_list(t_list *list)
{
  t_node	*tmp;

  while (check_list(list) != 0)
    {
      tmp = list->head;
      while (tmp->next != NULL)
	{
	  if (my_strcmp(tmp->name, tmp->next->name) > 0)
	    swap(tmp, tmp->next);
	  tmp = tmp->next;
	}
    }
}
