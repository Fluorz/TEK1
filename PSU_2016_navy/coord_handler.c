/*
** coord_handler.c for navy in /home/monty/Documents/Rendu/navy/PSU_2016_navy/monty/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Fri Feb  3 18:25:10 2017 Monty Criel
** Last update Sun Feb  5 22:27:49 2017 Leo Lecherbonnier
*/

#include "navy.h"

int	get_boat_size(char coord1, char coord2)
{
  int	nb1;
  int	nb2;
  int	size;

  nb1 = coord1 - '0';
  nb2 = coord2 - '0';
  size = 1;
  if (coord2 > coord1)
    {
      while (nb1 != nb2)
	{
	  nb1 = nb1 + 1;
	  size = size + 1;
	}
    }
  else
    {
      while (nb2 != nb1)
	{
	  nb2 = nb2 + 1;
	  size = size + 1;
	}
    }
  return (size);
}

int	verify_boats(char **coord)
{
  int	x;
  int	nb;

  int	size;
  x = 0;
  while (coord[x] != NULL)
    {
      size = coord[x][0] - '0';
      if (coord[x][2] == coord[x][5])
	{
	  nb = get_boat_size(coord[x][3], coord[x][6]);
	  if (nb != size)
	    return (84);
	}
      else
	{
	  nb = get_boat_size(coord[x][2] - 16, coord[x][5] - 16);
	  if (nb != size)
	    return (84);
	}
      x = x + 1;
    }
  return (0);
}

int	check_boat_size(char **coord)
{
  int	x;
  int	i;
  int	size;

  x = 0;
  i = 2;
  while (coord[x] != NULL)
    {
      size = coord[x][0] - '0';
      if (size != i)
	return (84);
      x = x + 1;
      i = i + 1;
    }
  return (0);
}

int	check_boats(char **coord)
{
  int	x;

  x = 0;
  while (coord[x] != NULL)
    {
      if ('1' > coord[x][0] || coord[x][0] > '5')
	return (84);
      if ('@' > coord[x][2] || coord[x][6] > 'H')
	return (84);
      if ((coord[x][2] == coord[x][5]) && (coord[x][3] == coord[x][6]))
	return (84);
      x = x + 1;
    }
  if (check_boat_size(coord) != 0)
      return (84);
  if (verify_boats(coord) != 0)
    return (84);
  return (0);
}
