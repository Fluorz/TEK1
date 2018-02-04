/*
** car_ai.c for need4stek in /home/monty/Documents/Rendu/need4stek/CPE_2016_n4s/src/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sat Jun  3 18:26:56 2017 Monty Criel
** Last update Sun Jun  4 19:01:29 2017 Monty Criel
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nfs.h"
#include "gnl.h"

float		get_dist_avg(float *lidar, char dir)
{
  int		i;
  int		end;
  float	avg;

  if (dir == 'l')
    {
      i = 0;
      end = 16;
    }
  else
    {
      i = 16;
      end = 32;
    }
  avg = 0;
  while (i != end)
    {
      avg += lidar[i];
      i += 1;
    }
  avg = avg / 16;
  return (avg);
}

void	speed_control(float avg)
{
  char	*str;

  if (avg > 2000.0)
    str = request("car_forward:1.0\n");
  else if (avg > 1500.0)
    str = request("car_forward:0.7\n");
  else if (avg > 1000.0)
    str = request("car_forward:0.6\n");
  else if (avg > 600.0)
    str = request("car_forward:0.5\n");
  else if (avg > 400.0)
    str = request("car_forward:0.4\n");
  else if (avg > 300.0)
    str = request("car_forward:0.3\n");
  else
    str = request("car_forward:0.2\n");
  stop_car(str);
  free(str);
}

void		move_wheel(float *lidar, float mid)
{
  float	dir;
  char		*str;
  float	diff;

  if (mid > 1500.0)
    dir = 0.005;
  else if (mid > 1000.0)
    dir = 0.05;
  else if (mid > 600.0)
    dir = 0.1;
  else if (mid > 400.0)
    dir = 0.2;
  else if (mid > 200.0)
    dir = 0.3;
  else
    dir = 0.5;
  diff = lidar[0] - lidar[31];
  if (diff > 0.0)
    dprintf(1, "wheels_dir:%f\n", dir);
  else
    dprintf(1, "wheels_dir:-%f\n", dir);
  str = get_next_line(0);
  stop_car(str);
  free(str);
}

int	stuck(float avg, float *lidar)
{
  if (avg < 150.0 || lidar[0] < 80.0 || lidar[31] < 80.0)
    {
      if (lidar[0] > lidar[31])
	request("wheels_dir:0.1\n");
      else
	request("wheels_dir:-0.1\n");
      request("car_backwards:0.7\n");
      return (0);
    }
  return (-1);
}

void		car_ai(float *lidar)
{
  float	avg;
  float	mid;

  avg = get_lidar_avg(lidar);
  mid = lidar[15];
  if (stuck(avg, lidar) == 0)
    return;
  speed_control(mid);
  move_wheel(lidar, mid);
}
