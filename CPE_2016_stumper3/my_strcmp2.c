/*
** my_strcmp2.c for quit in /home/ferlet_n/colle/CPE_2016_stumper3
** 
** Made by Nicolas Ferlet
** Login   <ferlet_n@epitech.net>
** 
** Started on  Tue May  2 09:53:50 2017 Nicolas Ferlet
** Last update Tue May  2 09:55:22 2017 Nicolas Ferlet
*/

#include "my.h"

int	my_strcmp2(char *str, char *needed)
{
  int	i;

  i = 0;
  if (needed == NULL)
    return (0);
  while (str[i] != '\0' && needed[i] != '\0')
    {
      if (str[i] != needed[i])
	return (0);
      i = i + 1;
    }
  if (needed[i] != '\0')
    return (0);
  return (1);
}
