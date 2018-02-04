/*
** lib.c for lib.c in /home/lecherbonnier/Projet/CPE_2016_stumper5/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri May 19 14:00:46 2017 Leo Lecherbonnier
** Last update Fri May 19 16:37:23 2017 Monty Criel
*/

#include "my.h"

int	my_strcmp(char *str, char *dest)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && dest[i] != '\0')
    {
      if (str[i] != dest[i])
	return (1);
      i++;
    }
  return (0);
}

int	my_str_is_num(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	i++;
      else
	return (1);
    }
  return (0);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i += 1;
  return (i);
}

char	*my_strcat(char *str, char *dest)
{
  int	tmp;
  int	i;
  char	*new;
  int	len;

  i = 0;
  len = my_strlen(str);
  if ((new = malloc(sizeof(char) * len + my_strlen(dest))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      new[i] = str[i];
      i++;
    }
  tmp = i;
  i = 0;
  while (dest[i] != '\0')
    {
      new[tmp] = dest[i];
      tmp++;
      i++;
    }
  return (new);
}

int	my_getnbr(char *str)
{
  int	i;
  int	len;
  int	result;

  i = 0;
  len = my_strlen(str);
  result = 0;
  if (str[i] == '-')
    i = i + 1;
  while (i < len)
    {
      result = result * 10 + (str[i] - '0');
      i = i + 1;
    }
  if (str[0] == '-')
    {
      result = result * (-1);
      return (result);
    }
  return (result);
}
