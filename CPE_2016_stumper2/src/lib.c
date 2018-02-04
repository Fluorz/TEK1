/*
** lib.c for lib.c in /home/lecherbonnier/Projet/CPE_2016_stumper2/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Apr 25 09:01:25 2017 Leo Lecherbonnier
** Last update Tue Apr 25 08:45:07 2017 Nicolas Ferlet
*/

#include "my.h"

char	*my_strcpy(char *dest, char *str, int len)
{
  int	i;

  i = 0;
  while (i != len)
    {
      dest[i] = str[i];
      i++;
    }
  return (dest);
}
