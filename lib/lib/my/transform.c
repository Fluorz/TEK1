/*
** transform.c for transform.c in /home/lecherbonnier/Projet/lib/lib/my/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sat Feb 11 11:20:03 2017 Leo Lecherbonnier
** Last update Sat Feb 11 15:14:13 2017 Leo Lecherbonnier
*/

#include "my.h"

g_hex	base[] =
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

g_hex1	bases[] =
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

int	transform_more(int j)
{
  int	i = 0;
  int	b;
  int	len = 16;
  char	*somme;
  int	c;

  if ((somme = malloc(sizeof(char) * (100))) == 0)
    exit (84);
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
  return (0);
}

int	transform_more1(int j)
{
  int	i = 0;
  int	b;
  int	len = 16;
  char	*somme;
  int	c;

  if ((somme = malloc(sizeof(char) * (100))) == 0)
    exit (84);
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
  return (0);
}
