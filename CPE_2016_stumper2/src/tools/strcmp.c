/*
** strcmp.c for strcmp in /home/ferlet_n/colle/CPE_2016_stumper2/tools
** 
** Made by Nicolas Ferlet
** Login   <ferlet_n@epitech.net>
** 
** Started on  Tue Apr 25 07:24:47 2017 Nicolas Ferlet
** Last update Tue Apr 25 07:26:08 2017 Nicolas Ferlet
*/

#include "my.h"

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  if (str1 == NULL || str2 == NULL)
    return (0);
  while (str1[i] != '\0' && str2[i] != '\0')
    {
      if (str1[i] != str2[i])
	return (0);
      i = i + 1;
    }
  if (str1[i] != str2[i])
    return (0);
  return (1);
}
