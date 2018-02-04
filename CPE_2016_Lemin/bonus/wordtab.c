/*
** wordtab.c for bootstrap tetris in /home/monty/Documents/Rendu/tetris/PSU_2016_btetris/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Tue Feb 21 11:24:06 2017 Monty Criel
** Last update Mon Apr 24 11:33:39 2017 Monty Criel
*/

#include <stdlib.h>

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i += 1;
    }
  free(tab[i]);
  free(tab);
}

char	**alloc_tab(char *str)
{
  char	**tab;
  int	i;
  int	len;

  i = 0;
  len = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	len += 1;
      i += 1;
    }
  tab = malloc(sizeof(char *) * (len + 1));
  if (tab == NULL)
    return (NULL);
  tab[len] = NULL;
  return (tab);
}

char	*alloc_line(char *str, int i)
{
  char	*line;
  int	len;

  len = 0;
  while (str[i] != '\n')
    {
      len += 1;
      i += 1;
    }
  line = malloc(sizeof(char) * (len + 1));
  if (line == NULL)
    return (NULL);
  return (line);
}

void	fill_tab(char **tab, char *str, int lines)
{
  int	i;
  int	x;
  int	y;

  x = 0;
  i = 0;
  while (x != lines)
    {
      tab[x] = alloc_line(str, i);
      if (tab[x] == NULL)
	{
	  tab = NULL;
	  return;
	}
      y = 0;
      while (str[i] != '\n')
	{
	  tab[x][y] = str[i];
	  y += 1;
	  i += 1;
	}
      tab[x][y] = '\0';
      x += 1;
      i += 1;
    }
}

char	**wordtab(char *str)
{
  int	i;
  int	count;
  char	**tab;

  tab = alloc_tab(str);
  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	count += 1;
      i += 1;
    }
  if (count == 0)
    count = 1;
  fill_tab(tab, str, count);
  if (tab == NULL)
    return (NULL);
  return (tab);
}
