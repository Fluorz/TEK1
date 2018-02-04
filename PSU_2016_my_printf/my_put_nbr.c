/*
** my_put_nbr.c for my_put_nbr.c in /home/leo/CPool_Day07/lib/my
**
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
**
** Started on  Tue Oct 11 12:40:56 2016 leo lecherbonnier
** Last update Wed Nov 16 19:46:48 2016 Leo Lecherbonnier
*/

#include <stdio.h>

void		my_putchar(char c);

static void	print_sign(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * - 1;
    }
}

static void	process_special(int nb)
{
  int char_digit;

  if (nb == 0)
    {
      char_digit = nb + 48;
      my_putchar(char_digit);
    }
  if (nb == -2147483648)
    {
      my_putchar('2');
      my_putchar('1');
      my_putchar('4');
      my_putchar('7');
      my_putchar('4');
      my_putchar('8');
      my_putchar('3');
      my_putchar('6');
      my_putchar('4');
      my_putchar('8');
    }
}

static int	set_divisor(int divisor)
{
  if (divisor == 1)
    divisor = 0;
  divisor = divisor / 10;
  return (divisor);
}

void		my_put_nbr(int nb)
{
  int		divisor;
  int		digit;
  int		rounded;
  char		char_digit;
  int		began;

  divisor = 1000000000;
  print_sign(nb);
  process_special(nb);
  began = 0;
  if (nb < 0)
    nb = nb * -1;
  while (divisor != 0)
    {
       if (divisor <= nb || began)
	{
	  digit = nb / divisor;
	  rounded = digit * divisor;
	  nb = nb - rounded;
	  char_digit = digit + 48;
	  my_putchar(char_digit);
	  began = 1;
	}
      divisor = set_divisor(divisor);
    }
}
