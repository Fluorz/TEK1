/*
** lib.c for lib.c in /home/lecherbonnier/Projet/CPE_2016_stumper1/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri Apr 21 09:07:49 2017 Leo Lecherbonnier
** Last update Jun Apr 21 09:36:53 2017
*/

#include "my.h"

int	my_getnbr(char *str)
{
  int	result;
  int	i;

  i= 0;
  result = 0;
  while (str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')

    }
  return (result);
}

int	my_putchar(char c)
{
  write (1, &c, 1);
  return (0);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}
