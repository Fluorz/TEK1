/*
** base.c for base.c in /root/CPool_bistro-matic/base/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Wed Nov  2 10:22:19 2016 Leo Lecherbonnier
** Last update Thu Nov 17 13:42:25 2016 Leo Lecherbonnier
*/

#include <unistd.h>
#include "my.h"

t_hex	base[] =
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
  	{'9'},
  	{'A'},
	{'B'},
	{'C'},
	{'D'},
  	{'E'},
	{'F'},
};

t_hex1	bases[] =
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
  	{'9'},
  	{'a'},
	{'b'},
	{'c'},
	{'d'},
  	{'e'},
  	{'f'},
};

t_oct	oct[] =
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

t_oct	binary[] =
{
  	{'0'},
  	{'1'},
};

int	transform_more(int j)
{
  int	i;
  int	b;
  int	len;
  char	*somme;
  int	c;

  i = 0;
  len = 16;
  somme = malloc(sizeof(char) * (100));
  while (j != 0)
    {
      b = j / len;
      c = b * len;
      if ((j - c) > 10)
	somme[i] = base[j - c].arr;
      else if ((j - c) == 10)
	somme[i] = base[10].arr;
      else
	somme[i] = base[j - c].arr;
      j = b;
      i++;
    }
  somme[i + 1] = '\0';
  somme = my_revstr(somme);
  my_putstr(somme);
}

int	transform_more1(int j)
{
  int	i;
  int	b;
  int	len;
  char	*somme;
  int	c;

  i = 0;
  len = 16;
  somme = malloc(sizeof(char) * (100));
  while (j != 0)
    {
      b = j / len;
      c = b * len;
      if ((j - c) > 10)
	somme[i] = bases[j - c].arr;
      else if ((j - c) == 10)
	somme[i] = bases[10].arr;
      else if ((j - c) < 10)
	somme[i] = bases[j - c].arr;
      j = b;
      i++;
    }
  somme[i + 1] = '\0';
  somme = my_revstr(somme);
  my_putstr(somme);
}

int	transform_less(int j)
{
  int	i;
  int	a;
  int	b;
  int	len;
  char	*somme;
  int	c;

  a = j;
  i = 0;
  len = 8;
  somme = malloc(sizeof(char) * (100));
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
}

int	transform_less1(int j)
{
  int	i;
  int	a;
  int	b;
  int	len;
  char	*somme;
  int	c;

  a = j;
  i = 0;
  len = 2;
  somme = malloc(sizeof(char) * (100));
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
}
