/*
** misc.c for need4stek in /home/monty/Documents/Rendu/need4stek/CPE_2016_n4s/src/tools/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sat Jun  3 18:12:39 2017 Monty Criel
** Last update Sun Jun  4 16:49:02 2017 Monty Criel
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nfs.h"

void	print_lidar(float *lidar)
{
  int	i;

  i = 0;
  while (lidar[i] != -1)
    {
      dprintf(2, "%f\n", lidar[i]);
      i += 1;
    }
}

float		get_lidar_avg(float *lidar)
{
  float	avg;
  int		i;

  i = 0;
  avg = 0.0;
  while (lidar[i] != -1)
    {
      avg += lidar[i];
      i += 1;
    }
  avg = avg / 32;
  return (avg);
}

char	*copy(char *string)
{
  char	*str;
  int	i;

  i = 0;
  str = malloc(sizeof(char) * (strlen(string) + 1));
  if (str == NULL)
    exit(84);
  while (string[i] != '\0')
    {
      str[i] = string[i];
      i += 1;
    }
  return (str);
}

char	*my_strcat(char *dest, char *src)
{
  int	x;
  int	i;
  int	len;
  char	*new_str;

  x = 0;
  i = 0;
  len = strlen(dest) + strlen(src);
  new_str = malloc(sizeof(char) * (len + 1));
  if (new_str == NULL)
    exit(84);
  while (dest[x] != '\0')
    new_str[i++] = dest[x++];
  x = 0;
  while (src[x] != '\0')
    {
      new_str[i] = src[x];
      x = x + 1;
      i = i + 1;
    }
  new_str[i] = '\0';
  return (new_str);
}
