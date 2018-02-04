/*
** my_get_nbr.c for my_get_nbr.c in /home/lecherbonnier/Projet/CPE_2016_stumper4/utils/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue May  9 09:09:52 2017 Leo Lecherbonnier
** Last update Tue May  9 07:30:45 2017 Nicolas Ferlet
*/

#include "my.h"

int	my_get_nbr(char *str)
{
  int	nb;
  int	i;

  nb = 0;
  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (-1);
      nb = nb * 10 + str[i] - 48;
      i = i + 1;
    }
  return (nb);
}
