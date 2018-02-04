/*
** init_lemin.c for lemin in /home/monty/Documents/Rendu/lemin/CPE_2016_Lemin/bonus/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Fri Apr 28 15:27:39 2017 Monty Criel
** Last update Sun Apr 30 14:25:08 2017 Monty Criel
*/

#include <unistd.h>
#include <stdlib.h>
#include "lemin.h"
#include "my.h"

char	**get_tunnels(char **tab)
{
  char	**tunnels;
  int	i;
  int	tmp;
  int	size;

  i = 0;
  size = 0;
  while (my_strcmp(tab[i], "#tunnels") != 0)
    i += 1;
  i += 1;
  tmp = i;
  while (my_strcmp(tab[i], "#moves") != 0)
    {
      size += 1;
      i += 1;
    }
  if ((tunnels = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  i = tmp;
  tmp = 0;
  while (tmp != size)
    tunnels[tmp++] = copy_line(tab[i++]);
  tunnels[tmp] = NULL;
  return (tunnels);
}

void	init_var_rooms(int *i, int *size, char **tab, char *option)
{
  *i = 0;
  *size = 0;
  while (my_strcmp(tab[*i], option) != 0)
    *i += 1;
}

char	**get_rooms(char **tab)
{
  char	**rooms;
  int	i;
  int	tmp;
  int	size;

  init_var_rooms(&i, &size, tab, "#rooms");
  tmp = i + 1;
  while (my_strcmp(tab[i], "#tunnels") != 0)
    {
      if (tab[i][0] != '#')
	size += 1;
      i += 1;
    }
  if ((rooms = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  i = tmp;
  tmp = 0;
  while (my_strcmp(tab[i], "#tunnels") != 0)
    {
      if (tab[i][0] != '#')
	rooms[tmp++] = copy_line(tab[i]);
      i += 1;
    }
  rooms[tmp] = NULL;
  return (rooms);
}

char	**get_moves(char **tab)
{
  char	**moves;
  int	i;
  int	tmp;
  int	size;

  init_var_rooms(&i, &size, tab, "#moves");
  tmp = i + 1;
  while (tab[i] != NULL)
    {
      if (tab[i][0] != '#')
	size += 1;
      i += 1;
    }
  if ((moves = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  i = tmp;
  tmp = 0;
  while (tab[i] != NULL)
    {
      if (tab[i][0] != '#')
	moves[tmp++] = copy_line(tab[i]);
      i += 1;
    }
  moves[tmp] = NULL;
  return (moves);
}

char	*get_type(int *i)
{
  char	*str;

  if (*i == 0)
    str = copy_line("start");
  else if (*i == 1)
    str = copy_line("end");
  else
    str = copy_line("normal");
  *i += 1;
  return (str);
}
