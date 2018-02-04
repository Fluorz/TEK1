/*
** speed_vector.c for speed_vector in /root/101pong/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Mon Nov  7 14:42:50 2016 Leo Lecherbonnier
** Last update Tue Nov  8 14:01:53 2016 Leo Lecherbonnier
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

float	speed_x0(int ac, char **av)
{
  float	a;
  float	b;
  float	c;

  a = atof(av[1]);
  b = atof(av[4]);
  c = b - a;
  return (c);
}

float	speed_y0(int ac, char **av)
{
  float	a;
  float	b;
  float	c;

  a = atof(av[2]);
  b = atof(av[5]);
  c = b - a;
  return (c);
}

float	speed_z0(int ac, char **av)
{
  float	a;
  float	b;
  float	c;

  a = atof(av[3]);
  b = atof(av[6]);
  c = b - a;
  return (c);
}

float	x0_t(int ac, char **av)
{
  float	a;
  float	b;
  float	c;
  float	d;

  a = atof(av[1]);
  b = speed_x0(ac, av);
  c = atof(av[7]);
  d = a + b * (c + 1);
  return (d);
}

float	y0_t(int ac, char **av)
{
  float	a;
  float	b;
  float	c;
  float	d;

  a = atof(av[2]);
  b = speed_y0(ac, av);
  c = atof(av[7]);
  d = a + b * (c + 1);
  return (d);
}

float	z0_t(int ac, char **av)
{
  float	a;
  float	b;
  float	c;
  float	d;

  a = atof(av[3]);
  b = speed_z0(ac, av);
  c = atof(av[7]);
  d = a + b * (c + 1);
  return (d);
}
