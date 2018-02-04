/*
** disp_my_put_nbr.c for disp my put nbr in /home/monty/Documents/Projets/Système Unix/PSU_2016_my_printf/include/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Thu Nov 17 00:27:04 2016 Monty Criel
** Last update Thu Nov 17 00:31:27 2016 Monty Criel
*/

#include <stdarg.h>
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
}

int     my_put_nbr(int nb)
{
  char  *result;
  int	size;
  int	tmp;

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

void	disp_my_put_nbr(va_list list)
{
  my_put_nbr(va_arg(list, int));
}
