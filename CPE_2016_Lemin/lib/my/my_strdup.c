/*
** my_strdup.c for my_strdup.c in /home/lecherbonnier/Projet/CPE_2016_Lemin/lib/my/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Apr 24 12:40:38 2017 Leo Lecherbonnier
** Last update Feb Apr 24 12:42:44 2017
*/

#include "my.h"

char	*my_strdup(char *src)
{
  char	*ret;

  if (!(ret = xmalloc((my_strlen(src) + 1) * sizeof(*ret))))
    return (NULL);
  my_strcpy(ret, src);
  return (ret);
}
