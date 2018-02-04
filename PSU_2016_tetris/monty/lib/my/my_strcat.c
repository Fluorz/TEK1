/*
** my_strcat.c for my str cat in /home/monty.criel/Rendu/CPool_Day07/lib/my
**
** Made by Monty Monty
** Login   <monty.criel@epitech.net>
**
** Started on  Tue Oct 11 10:00:49 2016 Monty Monty
** Last update Fri Mar 10 15:22:30 2017 Monty Criel
*/

#include <stdlib.h>

int	my_strlen(char *str);

char	*my_strcat(char *dest, char *src)
{
  int	x;
  int	i;
  int	len;
  char	*new_str;

  x = 0;
  i = 0;
  len = my_strlen(dest) + my_strlen(src);
  new_str = malloc(sizeof(char) * (len + 1));
  while (dest[x] != '\0')
    {
      new_str[i] = dest[x];
      x = x + 1;
      i = i + 1;
    }
  x = 0;
  while (src[x] != '\0')
    {
      new_str[i] = src[x];
      x = x + 1;
      i = i + 1;
    }
  new_str[i] = '\0';
  return (new_str);
}
