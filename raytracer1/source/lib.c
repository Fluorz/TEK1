/*
** lib.c for lib.c in /home/lecherbonnier/Projet/raytracer1/source/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Mar 16 12:30:37 2017 Leo Lecherbonnier
** Last update Thu Mar 16 12:32:23 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

int	my_putchar(char	c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i = 0;

  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}
