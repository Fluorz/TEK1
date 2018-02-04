/*
** lib.c for lib.c in /root/PSU_2016_minishell1/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Mon Jan 16 15:10:17 2017 Leo Lecherbonnier
** Last update Wed Jan 18 08:15:33 2017 Leo Lecherbonnier
*/

#include "minishell1.h"

int	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
      i++;
    }
  return (s1[i] - s2[i]);
}
