/*
** disp_my_put_nbr_u.c for disp my put nbr unsigned in /home/monty/Documents/Projets/Système Unix/PSU_2016_my_printf/include/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Sat Nov 19 20:55:25 2016 Monty Criel
** Last update Mon Jan 23 10:25:40 2017 Monty Criel
*/

#include <stdarg.h>
#include <stdlib.h>

void	my_putchar(char c);
int	my_putstr(char *str);

int	loop_u(unsigned int nb, int size)
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

int		my_put_nbr_u(unsigned int nb)
{
  char		*result;
  int		size;
  unsigned int	tmp;

  if (nb == 0)
    {
      my_putchar('0');
      return (0);
    }
  size = 0;
  tmp = nb;
  while (tmp >= 1)
    {
      tmp = tmp / 10;
      size = size + 1;
    }
  loop_u(nb, size);
  return (0);
}

void	disp_my_put_nbr_u(va_list list)
{
  my_put_nbr_u(va_arg(list, unsigned int));
}
