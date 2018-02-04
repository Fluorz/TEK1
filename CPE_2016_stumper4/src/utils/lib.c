/*
** lib.c for lib.c in /home/lecherbonnier/Projet/CPE_2016_stumper4/src/utils/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue May  9 11:16:11 2017 Leo Lecherbonnier
** Last update Tue May  9 11:16:14 2017 Leo Lecherbonnier
*/

#include "my.h"

void	my_putchar_error(char c)
{
  write (2, &c, 1);
}

void	my_putstr_error(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return ;
  while (str[i] != '\0')
    {
      my_putchar_error(str[i]);
      i++;
    }
}

int	my_error(char *str, int nb)
{
  my_putstr_error(str);
  return (nb);
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

char	*my_strcpy(char *str, char *dest)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      dest[i] = str[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
