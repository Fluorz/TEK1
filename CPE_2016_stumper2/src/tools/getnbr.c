/*
** getnbr.c for getnbr in /home/ferlet_n/colle/CPE_2016_stumper2/tools
** 
** Made by Nicolas Ferlet
** Login   <ferlet_n@epitech.net>
** 
** Started on  Tue Apr 25 07:21:07 2017 Nicolas Ferlet
** Last update Tue Apr 25 07:22:10 2017 Nicolas Ferlet
*/

#include "my.h"

int	my_getnbr(char *str)
{
  int	i;
  int	nb;

  nb = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (-1);
      nb = nb * 10 + str[i] - 48;
      i = i + 1;
    }
  return (nb);
}
