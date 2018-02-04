/*
** my_strcmp.c for my_strcmp.c in /home/leo/CPool_Day07/lib/my
**
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
**
** Started on  Tue Oct 11 13:20:17 2016 leo lecherbonnier
** Last update May Apr 27 14:24:14 2017
*/

#include "unistd.h"

int		my_strcmp(char *arg, char *comp)
{
  int		i;

  i = 0;
  if (arg == NULL)
    return (1);
  while (arg[i] != '\0' && comp[i] != '\0')
    {
      if (arg[i] == comp[i])
        i++;
      else
        return (1);
    }
  if (arg[i] == '\0' && comp[i] == '\0')
    return (0);
  else
    return (1);
}
