/*
** parsing.c for parsing.c in /home/lecherbonnier/wolf3d/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Jan  5 20:01:05 2017 Leo Lecherbonnier
** Last update Wed Mar  8 10:25:18 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

int	**my_retab(int **tab, char *str, int ligne, int colums)
{
  int	i;
  int	x;
  int	y;

  i = 0;
  x = 0;
  y = 0;
  tab = malloc((ligne + 2) * sizeof(int *));
  while (y != ligne)
    {
      tab[y] = malloc((colums + 2) * sizeof(int));
      while (str[i] != '\n' && str[i] != '\0')
	{
	  tab[y][x] = str[i] - 48;
	    x++;
	    i++;
	}
      x = 0;
      i++;
      y++;
    }
  return (tab);
}

char	*fs_open_file(char* filepath, int *ligne, int *colums)
{
  char	c;
  char  *str;
  int	fd;
  int	i;

  fd = open(filepath, O_RDONLY);
    if (fd <= 0)
      exit(0);
  str = malloc(sizeof(char) * 1000000);
  i = -1;
  while (read(fd, &c, 1) != '\0')
    {
      str[++i] = c;
      if (str[i] == '\n')
	*ligne = *ligne + 1;
    }
  str[i] = '\0';
  i = -1;
  while (str[++i] != '\n')
    if (str[i]!='\0')
      *colums = *colums + 1;
  *ligne = *ligne + 1;
  return (str);
}

int	**my_reader(int **tab, char *path , int  *line, int *col)
{
  int	ligne;
  int	colums;
  char	*str;

  ligne = 0;
  colums = 0;
  if (path != NULL)
    str = fs_open_file(path, &ligne, &colums);
  else
	{
    str = NULL;
	  exit(0);
	}
  if (str == NULL)
    {
      tab = NULL;
      return (tab);
    }
  tab = my_retab(tab, str, ligne, colums);
  *line = ligne - 1;
  *col = colums;
  return (tab);
}
