/*
** disp_my_putstr_S.c for my put str S in /home/monty/Documents/Projets/Système Unix/PSU_2016_my_printf/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Sat Nov 19 22:43:04 2016 Monty Criel
** Last update Sun Nov 20 17:48:03 2016 Monty Criel
*/

#include <stdarg.h>
#include <unistd.h>

void	my_putchar(char c);
int	my_putstr(char *str);
int	my_strlen(char *str);
int     my_put_nbr(int nb);

void	my_put_nbr_base_S(int nb, char *base)
{
  int	max;
  int	rest;
  int	i;
  char	result[3];

  max = my_strlen(base);
  i = 2;
  result[0] = '0';
  result[1] = '0';
  result[2] = '0';
  while (nb > 0)
    {
      rest = nb % max;
      nb = nb / max;
      result[i] = base[rest];
      i = i - 1;
    }
  i = 0;
  while (i <= 2)
    {
      my_putchar(result[i]);
      i = i + 1;
    }
}

int	my_putstr_S(char *str)
{
  int	letter;

  if (str == NULL)
    {
      my_putstr("(null)");
      return (0);
    }
  letter = 0;
  while (str[letter] != '\0')
    {
      if (str[letter] >= 127 || str[letter] < 32)
	{
	  my_putchar(92);
	  my_put_nbr_base_S((str[letter]), "01234567");
	}
      else
	my_putchar(str[letter]);
      letter = letter + 1;
    }
  return (letter);
}

void	disp_my_putstr_S(va_list list)
{
  my_putstr_S(va_arg(list, char*));
}
