/*
** my_strcpy.c for my_strcpy.c in /home/lecherbonnier/Projet/CPE_2016_stumper3/utils/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue May  2 10:46:45 2017 Leo Lecherbonnier
** Last update Tue May  2 09:02:16 2017 Nicolas Ferlet
*/

#include "my.h"

int     my_strcpy(char *str, char *dest)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      dest[i] = str[i];
      i++;
    }
  dest[i] = '\0';
  return (0);
}
