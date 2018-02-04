/*
** soft_display.c for soft_display in /home/ferlet_n/colle/CPE_2016_stumper2/tools
** 
** Made by Nicolas Ferlet
** Login   <ferlet_n@epitech.net>
** 
** Started on  Tue Apr 25 07:07:30 2017 Nicolas Ferlet
** Last update Tue Apr 25 08:25:25 2017 Nicolas Ferlet
*/

#include "my.h"

int	my_putchar(char c)
{
  if (write(1, &c, 1) < 0)
    return (-1);
  return (0);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (-1);
  while (str[i] != '\0')
    {
      if (my_putchar(str[i]) == -1)
	return (-1);
      i = i + 1;
    }
  return (0);
}

int	my_putchar_error(char c)
{
  if (write(2, &c, 1) < 0)
    return (-1);
  return (0);
}

int	my_putstr_error(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (my_putchar_error(str[i]) == -1)
	return (-1);
      i = i + 1;
    }
  return (0);
}

int	my_error(char *str, int nb)
{
  if (my_putstr_error(str) == -1)
    return (nb);
  return (nb);
}
