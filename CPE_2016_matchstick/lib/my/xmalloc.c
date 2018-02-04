/*
** xmalloc.c for xmalloc.c in /home/lecherbonnier/Projet/CPE_2016_matchstick/lib/my/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Feb 13 13:44:57 2017 Leo Lecherbonnier
** Last update Mon Feb 13 13:45:15 2017 Leo Lecherbonnier
*/

#include "my.h"

void		*xmalloc(int size)
{
  void		*ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      write(2, "Impossible to allocate Memory\n", 30);
      return (NULL);
    }
  return (ptr);
}
