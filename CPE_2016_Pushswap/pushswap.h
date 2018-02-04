/*
** pushswap.h for pushswap in /home/lecherbonnier/Bureau/CPE_2016_Pushswap/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed Nov 23 18:10:28 2016 Leo Lecherbonnier
** Last update Thu Nov 24 23:01:15 2016 Leo Lecherbonnier
*/

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "my.h"

#ifndef MY_H_
# define MY_H_

typedef struct s_liste
{
  int			nbr;
  struct s_liste	*next;
  struct s_liste	*prev;
}		t_liste;


void		swap_elem(t_liste **list, int *special_case);
int		checkout(t_liste *list);
void		buble_sort(t_liste **list, int size);
int		create_list(t_liste **list, int a);
void		print_list(t_liste *list, int ac);

#endif
