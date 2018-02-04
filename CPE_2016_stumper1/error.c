/*
** error.c for error.c in /home/lecherbonnier/Projet/CPE_2016_stumper1/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri Apr 21 09:11:38 2017 Leo Lecherbonnier
** Last update Jun Apr 21 09:13:07 2017
*/

#include "my.h"

int	putchar_error(char c)
{
  write (2, &c, 1);
  return (0);
}

int	putstr_error(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      putchar_error(str[i]);
      i++;
    }
}
