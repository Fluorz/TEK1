/*
** my_put_nbr.c for my put nbr in /home/monty.criel/Rendu/CPool_Day07/lib/my
**
** Made by Monty Monty
** Login   <monty.criel@epitech.net>
**
** Started on  Tue Oct 11 09:20:29 2016 Monty Monty
** Last update Sun Apr  2 12:32:31 2017 Monty Criel
*/

#include <stdlib.h>

void	my_putchar(char c);
int	my_putstr(char *str);

int	loop(int nb, int size)
{
  int	rest;
  char	*result;
  int	i;

  i = size - 1;
  result = malloc(sizeof (char) * (size + 1));
  result[size + 1] = '\0';
  while (i >= 0)
    {
      rest = (nb % 10);
      result[i] = rest + '0';
      nb = nb - rest;
      nb = nb / 10;
      i = i - 1;
    }
  my_putstr(result);
  return (0);
}

int     my_put_nbr(int nb)
{
  int	size;
  int	tmp;

  if (nb == 0)
    {
      my_putchar('0');
      return (0);
    }
  size = 0;
  if (nb < 0)
    {
      nb = nb * (-1);
      my_putchar('-');
    }
  tmp = nb;
  while (tmp >= 1)
    {
      tmp = tmp / 10;
      size = size + 1;
    }
  loop(nb, size);
  return (0);
}
