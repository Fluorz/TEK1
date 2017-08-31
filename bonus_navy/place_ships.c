/*
** place_ships.c for navy in /home/monty/Documents/Rendu/navy/PSU_2016_navy/monty/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Fri Feb  3 15:00:24 2017 Monty Criel
** Last update Thu Feb 16 15:38:44 2017 Leo Lecherbonnier
*/

#include "navy.h"

char	*get_data(char *file_name)
{
  int	file;
  char	*buff[2];
  char	*buffer;
  int	count;
  int	end;

  if ((file = open(file_name, O_RDONLY)) == -1)
    return (NULL);
  count = 0;
  while (read(file, buff, 1))
      count = count + 1;
  close(file);
  if ((file = open(file_name, O_RDONLY)) == -1)
    return (NULL);
  if ((buffer = malloc(sizeof(char) * (count + 1))) == 0)
    return (NULL);
  end = read(file, buffer, count);
  buffer[end] = '\0';
  close(file);
  return (buffer);
}

int	count_ships(char *av)
{
  char	**tab;
  int	tmp;
  int	x;
  int	i;

  if ((tab = get_boat_coord(get_data(av))) == NULL)
    return (-1);
  x = 0;
  i = 0;
  while (tab[x] != NULL)
    {
      tmp = tab[x][0] - '0';
      i = i + tmp;
      x = x + 1;
    }
  free(tab);
  return (i);
}

void		place_boat_vertical(char **map, char *coord)
{
  int		x;
  int		y;
  int		i;
  int		end;
  char		pos;

  i = 0;
  end = coord[0] - '0';
  if (coord[6] > coord[3])
    pos = coord[3];
  else
    pos = coord[6];
  while (i != end)
    {
      x = (pos - 48) + 1;
      y = (coord[2] - 64) * 2;
      map[x][y] = coord[0];
      i = i + 1;
      pos = pos + 1;
    }
}

void		place_boat_horizontal(char **map, char *coord)
{
  int		x;
  int		y;
  int		i;
  int		end;
  char		pos;

  i = 0;
  end = coord[0] - '0';
  if (coord[5] > coord[2])
    pos = coord[2];
  else
    pos = coord[5];
  while (i != end)
    {
      x = (coord[3] - 48) + 1;
      y = (pos - 64) * 2;
      map[x][y] = coord[0];
      i = i + 1;
      pos = pos + 1;
    }
}

int		place_ships(char **map, char *av)
{
  char		**boats;
  int		x;

  x = 0;
  boats = get_boat_coord(get_data(av));
  if (boats == NULL)
    {
      my_putstr("Invalid position file\n");
      return (84);
    }
  if (check_boats(boats) != 0)
    {
      my_putstr("Invalid position file\n");
      return (84);
    }
  while (boats[x] != NULL)
    {
      if (boats[x][2] == boats[x][5])
	place_boat_vertical(map, boats[x]);
      else
	place_boat_horizontal(map, boats[x]);
      x = x + 1;
    }
  return (0);
}
