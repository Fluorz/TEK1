/*
** algo.c for algo.c in /home/lecherbonnier/CPE_2016_BSQ/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Dec 15 14:09:00 2016 Leo Lecherbonnier
** Last update Sun Dec 18 17:25:35 2016 Leo Lecherbonnier
*/

#include "bsq.h"

int	check_square(int *tab, int colums, int j)
{
  int	diagonale;

  ++colums;
  diagonale = j - colums;
  if (j <= colums || tab[j - 1] <= 0 ||
      tab[diagonale] == 0 || tab[diagonale - 1] == 0)
    return (1);
  else
    {
      if (tab[j - 1] <= tab[diagonale] && tab[j - 1] <= tab[diagonale - 1])
	return (tab[j - 1] + 1);
      else if (tab[diagonale] <= tab[j - 1]
	       && tab[diagonale] <= tab[diagonale - 1])
	return (tab[diagonale] + 1);
      else if (tab[diagonale - 1] <= tab[j - 1]
	       && tab[diagonale - 1] <= tab[diagonale])
	return (tab[diagonale - 1] + 1);
      return (0);
    }
}

void	find_square(char *str, t_max *list, int i, int j)
{
  int	*tab;

  if ((tab = malloc(sizeof(int) * (list->len))) == NULL)
    exit(-1);
  while (str[i++] != '\0' && list->max < list->colums)
    {
      if (str[i - 1] == '.')
	tab[i - 1] = check_square(tab, list->colums, j);
      else if (str[i - 1] == 'o')
	tab[i - 1] = 0;
      else if (str[i - 1] == '\n' || str[i - 1] == '\0')
	tab[i - 1] = -1;
      else
	exit(-1);
      if (tab[j++] > list->max)
	{
	  list->max = tab[i - 1];
	  list->caractere = i - 1;
	}
    }
}

void	map(char *file, t_max *list, int pos, int s)
{
  int	stock;
  int	rep;

  pos = list->caractere;
  s = list->max;
  stock = 0;
  rep = 0;
  while (rep != s)
    {
      stock = pos;
      while (pos != stock - s)
	{
	  file[pos] = 'x';
	  pos--;
	}
      pos = stock - list->colums - 1;
      rep++;
    }
  write(1, file, list->len);
}

char	*fs_open_file(char* filepath, t_max *list)
{
  char	c;
  char  *str;
  int	fd;
  int	i;
  struct stat	buf;

  stat(filepath, &buf);
  if (buf.st_size == 0)
    exit (-1);
  if ((fd = open(filepath, O_RDONLY)) <= 0)
    exit(-1);
  if ((str = malloc(sizeof(char) * buf.st_size + 2)) == NULL)
    exit(-1);
  i = 0;
  read(fd, str, buf.st_size);
  str[buf.st_size] = '\0';
  while (*str++ != '\n' && str != NULL);
  while (str[i++] != '\n')
    list->colums = list->colums + 1;
  close(fd);
  list->len = my_strlen(str);
  return (str);
}

int	main(int ac, char **av)
{
  t_max	*list;
  char	*str;

  if (ac != 2)
    return (84);
  list = malloc(sizeof(t_max));
  list->ligne = 0;
  list->colums = 0;
  list->max = 0;
  list->caractere = 0;
  list->len = 0;
  str = malloc(sizeof(char));
  str = fs_open_file(av[1], list);
  if (str == NULL)
    return (84);
  find_square(str, list, 0, 0);
  map(str, list, 0, 0);
  free(list);
  return (0);
}
