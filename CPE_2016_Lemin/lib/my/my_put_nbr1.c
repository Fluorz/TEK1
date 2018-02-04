/*
** my_put_nbr1.c for my_put_nbr in /root/PSU_2016_my_printf/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Wed Nov 16 18:18:56 2016 Leo Lecherbonnier
** Last update Wed Nov 16 19:47:01 2016 Leo Lecherbonnier
*/

#include <stdio.h>

void		my_putchar(char c);

static void	print_sign1(unsigned int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * - 1;
    }
}

static void	process_special1(unsigned int nb)
{
  unsigned int char_digit;

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

static unsigned int	set_divisor1(unsigned int divisor)
{
  if (divisor == 1)
    divisor = 0;
  divisor = divisor / 10;
  return (divisor);
}

void		my_put_nbr1(unsigned int nb)
{
  unsigned int		divisor;
  unsigned int		digit;
  unsigned int		rounded;
  char			char_digit;
  unsigned int		began;

  divisor = 1000000000;
  print_sign1(nb);
  process_special1(nb);
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
      divisor = set_divisor1(divisor);
    }
}
