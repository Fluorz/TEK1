/*
** my_charcat.c for my char cat in /home/monty/Documents/Rendu/my_ls/PSU_2016_my_ls/lib/my/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Fri Dec  2 17:15:43 2016 Monty Criel
** Last update Fri Dec  2 19:12:18 2016 Monty Criel
*/

#include <stdlib.h>

int	my_strlen(char *str);

char	*my_charcat(char *dest, char src)
{
  int	x;
  int	i;
  int	len;
  char	*new_str;

  x = 0;
  i = 0;
  len = my_strlen(dest) + 1;
  new_str = malloc(sizeof(char) * (len + 1));
  while (dest[x] != '\0')
    {
      new_str[i] = dest[x];
      x = x + 1;
      i = i + 1;
    }
  x = 0;
  new_str[i] = src;
  i = i + 1;
  new_str[i] = '\0';
  return (new_str);
}
