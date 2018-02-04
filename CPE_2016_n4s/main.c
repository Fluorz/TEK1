/*
** main.c for need4stek in /home/monty/Documents/Rendu/need4stek/CPE_2016_n4s/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Thu Jun  1 11:39:41 2017 Monty Criel
** Last update Sun Jun  4 18:49:36 2017 Monty Criel
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <gnl.h>
#include <nfs.h>

float		*get_lidar(char **data)
{
  float	*lidar;
  int		i;
  int		x;

  i = 6;
  x = 0;
  lidar = malloc(sizeof(double) * 33);
  if (lidar == NULL)
    exit(84);
  while (i != 38)
    {
      lidar[x] = atof(data[i]);
      i += 1;
      x += 1;
    }
  lidar[x] = -1;
  return (lidar);
}

void		stop_car(char *str)
{
  char		**tab;

  tab = wordtab(str, ':');
  if (strcmp(tab[6], "Track") == 0)
    {
      str = request("get_info_simtime\n");
      debug(str);
      request("car_forward:0.5\n");;
      request("car_forward:0.0\n");
      request("cycle_wait:50\n");
      request("stop_simulation\n");
      free(str);
      free_tab(tab);
      exit(0);
    }
}

int		main(int argc, char **argv)
{
  char		*str;
  char		**tab;
  float	*lidar;

  if (argc != 1 || argv[0] == NULL)
    return (84);
  request("start_simulation\n");
  while (42)
    {
      str = request("get_info_lidar\n");
      tab = wordtab(str, ':');
      lidar = get_lidar(tab);
      car_ai(lidar);
      free(str);
      free_tab(tab);
      free(lidar);
    }
  return (0);
}
