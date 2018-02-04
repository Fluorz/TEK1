/*
** base.c for base.c in /root/CPool_bistro-matic/base/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Wed Nov  2 10:22:19 2016 Leo Lecherbonnier
** Last update Mon Feb 27 12:14:51 2017 Leo Lecherbonnier
*/

#include <unistd.h>
#include "my.h"

g_oct	oct[] =
{
  	{'0'},
  	{'1'},
  	{'2'},
  	{'3'},
  	{'4'},
  	{'5'},
  	{'6'},
  	{'7'},
  	{'8'},
};

g_oct	binary[] =
{
  	{'0'},
  	{'1'},
};

int	transform_less(int j)
{
  int	i = 0;
  int	a;
  int	b;
  int	len = 8;
  char	*somme;
  int	c;

  a = j;
  if ((somme = malloc(sizeof(char) * (100))) == 0)
    return (84);
  while (a != 0)
    {
      b = a / len;
      c = b * len;
      somme[i] = oct[(a - c)].arr;
      a = b;
      i++;
    }
  somme[i + 1] = '\0';
  somme = my_revstr(somme);
  my_putstr(somme);
  return (0);
}

int	transform_less1(int j)
{
  int	i = 0;
  int	a;
  int	b;
  int	len = 2;
  char	*somme;
  int	c;

  a = j;
  if ((somme = malloc(sizeof(char) * (100))) == 0)
    return (84);
  while (a != 0)
    {
      b = a / len;
      c = b * len;
      somme[i] = binary[(a - c)].arr;
      a = b;
      i++;
    }
  somme[i + 1] = '\0';
  somme = my_revstr(somme);
  my_putstr(somme);
  return (0);
}
