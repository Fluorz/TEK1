/*
** lib.c for lib.c in /home/lecherbonnier/Projet/CPE_2016_stumper3/utils/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue May  2 09:53:15 2017 Leo Lecherbonnier
** Last update Tue May  2 10:57:27 2017 Leo Lecherbonnier
*/

#include "my.h"

void	my_putchar(char c)
{
  write (1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

int	my_strcmp(char *str, char *other)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && other[i] != '\0')
    {
      if (str[i] != other[i])
	return (0);
      i++;
    }
  if (str[i] != other[i])
    return (0);
  return (1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i++;
  return (i);
}

int	my_error(char *str, int nb)
{
  int	i;

  i = 0;
  while (str != NULL && str[i] != '\0')
    {
      write(2, &(str[i]), 1);
      i = i + 1;
    }
  return (nb);
}
