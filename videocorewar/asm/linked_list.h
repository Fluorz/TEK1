/*
** linked_list.h for corewar in /home/monty/Documents/Rendu/corewar/CPE_2016_corewar/ASM/monty/include/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Wed Mar 29 13:12:25 2017 Monty Criel
** Last update Sun Apr  2 03:25:27 2017 Monty Criel
*/

#ifndef LINKED_LIST_H

#define LINKED_LIST_H

typedef struct	s_node
{
  char			*name;
  int			size;
  struct s_node	*next;
}			t_node;

typedef struct	s_list
{
  t_node		*head;
}			t_list;

#endif /*LINKED_LIST_H*/
