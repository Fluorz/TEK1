/*
** strlen.c for strlen.c in /home/ferlet_n/colle/CPE_2016_stumper2/tools
** 
** Made by Nicolas Ferlet
** Login   <ferlet_n@epitech.net>
** 
** Started on  Tue Apr 25 07:18:48 2017 Nicolas Ferlet
** Last update Tue Apr 25 07:19:49 2017 Nicolas Ferlet
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (-1);
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
