/*
** check_str.c for check_str.c in /home/lecherbonnier/Projet/PSU_2016_navy/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Feb  7 16:02:12 2017 Leo Lecherbonnier
** Last update Tue Feb  7 17:55:29 2017 Leo Lecherbonnier
*/

#include "navy.h"

int	check_str(char *str)
{
  if (my_strlen(str) >= 3)
    {
      my_printf("wrong position\n");
      return (1);
    }
  if (str[0] == '\0' || str[1] == '\0')
    {
      my_printf("wrong position\n");
      return (1);
    }
  if (str[0] != 'A' && str[0] != 'B' && str[0] != 'C'
      && str[0] != 'D' && str[0] != 'E' && str[0] != 'F'
      && str[0] != 'G' && str[0] != 'H')
    {
      my_printf("wrong position\n");
      return (1);
    }
  if (str[1] != '1' && str[1] != '2' && str[1] != '3'
      && str[1] != '4' && str[1] != '5' && str[1] != '6'
      && str[1] != '7' && str[1] != '8')
    {
      my_printf("wrong position\n");
      return (1);
    }
  return (0);
}
