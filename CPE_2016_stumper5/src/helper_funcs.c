/*
** helper_funcs.c for stumper5 in /home/monty/Documents/colle/CPE_2016_stumper5/include/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Fri May 19 13:37:04 2017 Monty Criel
** Last update Jun May 19 15:39:29 2017
*/

#include "my.h"

char	*copy(char *string)
{
  char	*str;
  int	i;

  i = 0;
  while (string[i] != '\0')
    i += 1;
  if ((str = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (string[i] != '\0')
    {
      str[i] = string[i];
      i += 1;
    }
  str[i] = '\0';
  return (str);
}

int	insert_swag(char *str, char c)
{
  int	i = 0;

  while (str[i] != '\0')
    {
      if (str[i] == '0')
	str[i] = c;
      i++;
    }
  return (0);
}
