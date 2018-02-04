/*
** my_get_nbr.c for my_get_nbr.c in /home/lecherbonnier/Projet/CPE_2016_stumper3/utils/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue May  2 09:14:30 2017 Leo Lecherbonnier
** Last update Mar May 2 09:48:33 2017
*/

#include "my.h"

int	my_get_nbr(char *str)
{
  int	result;
  int	i;

  i = 0;
  result = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (-1);
      result = result * 10;
      result = result + str[i] - 48;
      i++;
    }
  return (result);
}
