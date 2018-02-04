/*
** lib_leo.c for lib_leo.c in /home/lecherbonnier/Projet/raytracer2/include/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sun May 28 20:49:30 2017 Leo Lecherbonnier
** Last update Jan May 28 22:09:38 2017
*/

#include "open_file.h"

int	my_strlen(char *str)
{
  int	i = 0;

  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      i++;
    }
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

char	*my_strdup(char *src)
{
  char	*dest;
  int	max;

  max = my_strlen(src) + 1;
  dest = malloc(sizeof (char) * max);
  dest = my_strcpy(src, dest);
  return (dest);
}
