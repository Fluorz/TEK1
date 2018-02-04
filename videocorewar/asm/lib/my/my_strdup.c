/*
** my_strdup.c for my str dup in /home/monty.criel/Exercices piscines beta/CPool_day08/task01
**
** Made by Monty Monty
** Login   <monty.criel@epitech.net>
**
** Started on  Wed Oct 12 09:00:58 2016 Monty Monty
** Last update Sun Apr  2 22:29:34 2017 Monty Criel
*/

#include <stdlib.h>

int	my_strlen(char *str);
int	my_strcpy(char *dest, char *src);

char	*my_strdup(char *src)
{
  char	*dest;
  int	max;

  if (src == NULL)
    return (NULL);
  max = 0;
  while (src[max] != '\0')
    max += 1;
  dest = malloc(sizeof (char) * (max + 1));
  dest[max] = '\0';
  if (dest == NULL)
    return (NULL);
  my_strcpy(dest, src);
  return (dest);
}
