/*
** my_strcmp.c for my_strcmp.c in /home/B_chikho/rendu/CPool_Day06
** 
** Made by Chikhoune Benjamin
** Login   <B_chikho@epitech.net>
** 
** Started on  Mon Oct 10 12:27:06 2016 Chikhoune Benjamin
** Last update Mon Oct 24 12:57:24 2016 Benjamin
*/

#include <stdlib.h>

int		my_strncmp(char *s1, char *s2, int n)
{
  int		i;

  i = 0;
  if ((s1 == NULL) || (s2 == NULL))
    return (-1);
  while (((s1[i] == s2[i]) && (s1[i] != '\0')) && i < (n - 1))
    i = i + 1;
  return ((s1[i] - s2[i]));
}
