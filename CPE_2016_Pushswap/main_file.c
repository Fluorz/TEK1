/*
** main_file.c for main_file.c in /home/lecherbonnier/Bureau/CPE_2016_Pushswap/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed Nov 23 18:13:28 2016 Leo Lecherbonnier
** Last update Sat Nov 26 11:16:44 2016 Leo Lecherbonnier
*/

#include "pushswap.h"

void		swap_elem(t_liste **list, int *special_case)
{
  int		tmp;

  tmp = (*list)->nbr;
  (*list)->nbr = (*list)->next->nbr;
  (*list)->next->nbr = tmp;
  if (*special_case == 0)
    write(1, "sa", 2);
  if (*special_case == 1)
    write(1, " sa", 3);
  *special_case = 1;
}

int		checkout(t_liste *list)
{
  t_liste			*tmp;

  tmp = list;
  if (!(list->next))
    return (0);
  if (list->nbr > list->next->nbr)
    {
      return (1);
    }
  list = list->next;
  while (list->next != tmp)
    {
      if (list->nbr > list->next->nbr)
	{
	  return (1);
	}
      list = list->next;
    }
	return (0);
}

void		ra(t_liste **list, int *i)
{
  (*list) = (*list)->next;
  write(1, " ra", 3);
  *i = *i + 1;
}

void		buble_sort(t_liste **list, int size)
{
  int		i;
  int		special_case;

  special_case = 0;
  while (checkout(*list) == 1)
    {
      i = 0;
      while (i < size - 1)
	{
	  if (i < size - 2 && (*list)->nbr > (*list)->next->nbr)
	      swap_elem(list, &special_case);
	  ra(list, &i);
	}
    }
  my_putchar('\n');
}

int		main(int argc, char **argv)
{
  t_liste	*list;
  int		i;

  i = 1;
  list = NULL;
  if (argc == 1)
    return(84);
  while (i != argc)
    {
      create_list(&list, my_getnbr(argv[i]));
      i++;
    }
  buble_sort(&list, argc);
  return (0);
}
