/*
** link_list.h for rush1 in /home/monty/Documents/rush/rush1/my_unarchive/include/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sun Mar  5 11:40:17 2017 Monty Criel
** Last update Sun Mar 12 15:33:52 2017 Monty Criel
*/

#ifndef LINKED_LIST_H

#define LINKED_LIST_H

#include <stdlib.h>
#include <dirent.h>

typedef struct	s_node
{
  char			*name;
  char			**tetrimino;
  int			status;
  struct s_node	*next;
}			t_node;

typedef struct	s_list
{
  t_node		*head;
}			t_list;

#endif /*LINKED_LIST_H*/
