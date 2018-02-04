/*
** tab.c for tab in /home/ferlet_n/colle/CPE_2016_stumper3
**
** Made by Nicolas Ferlet
** Login   <ferlet_n@epitech.net>
**
** Started on  Tue May  2 08:36:14 2017 Nicolas Ferlet
** Last update Mar May 2 11:37:37 2017
*/

#include "my.h"

void	first_and_last_line(char **tab)
{
  int	j;
  int	i;

  j = 0;
  i = my_strlen(tab[0]);
  my_putchar('+');
  while (j < i)
    {
      my_putchar('-');
      j++;
    }
  my_putchar('+');
  my_putchar('\n');
}

void	print_tab(char **tab)
{
  int	i;

  i = 0;
  first_and_last_line(tab);
  while (tab[i] != NULL)
    {
      my_putchar('|');
      my_putstr(tab[i]);
      my_putchar('|');
      my_putchar('\n');
      i = i + 1;
    }
  first_and_last_line(tab);
}

char	get_random_char(int i, int j)
{
  srandom(time(NULL) * j + getpid() + i);
  return (random() % 26 + 'a');
}

void	fill_tab(char **tab)
{
  int	i;
  int	j;

  j = 0;
  while (tab[j] != NULL)
    {
      i = 0;
      while (tab[j][i] != '\0')
	{
	  tab[j][i] = get_random_char(i, j);
	  i = i + 1;
	}
      j = j + 1;
    }
}
