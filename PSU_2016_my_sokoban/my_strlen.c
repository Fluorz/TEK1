/*
** my_strelen.c for my_strlen.C in /root/PSU_2016_my_sokoban/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Tue Dec 20 17:47:10 2016 Leo Lecherbonnier
** Last update Tue Dec 20 17:48:16 2016 Leo Lecherbonnier
*/

#include "sokoban.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
      i++;
  return (i);
}
