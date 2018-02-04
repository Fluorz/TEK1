/*
** int_to_str.c for PSU_2016_navy in /home/sid/Navy
** 
** Made by Sid
** Login   <sid.djilali-saiah@epitech.eu>
** 
** Started on  Sun Feb 12 03:42:41 2017 Sid
** Last update Thu Apr 20 12:41:38 2017 abdel cherkaoui
*/

#include "../my.h"

int	countint(int nbr)
{
  int	i;

  i = 1;
  if (nbr < 0)
    {
      nbr = -nbr;
      i = i + 1;
    }
  if (nbr >= 10)
    {
      while (nbr >= 10)
	{
	  nbr = nbr / 10;
	  i = i + 1;
	}
    }
  return (i);
}

char	*int_to_str(int nbr)
{
  int	len_nbr;
  char	*str;
  int	i;

  len_nbr = countint(nbr);
  i = len_nbr - 1;
  if ((str = malloc(sizeof(char) * (len_nbr + 1))) == NULL)
    return (NULL);
  str[i + 1] = '\0';
  if (nbr < 0)
    {
      nbr = nbr * (-1);
      str[0] = '-';
    }
  while (nbr >= 10)
    {
      str[i] = (nbr % 10) + '0';
      nbr = nbr / 10;
      i = i - 1;
    }
  str[i] = nbr + '0';
  return (str);
}
