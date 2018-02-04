/*
** angle.c for 101pong in /home/tawa/101pong/
**
** Made by Marvyn Quivront
** Login   <marvyn.quivront@epitech.eu@epitech.eu>
**
** Started on  Mon Nov  7 15:11:45 2016 Marvyn Quivront
** Last update	Mon Nov 07 15:53:07 2016 Full Name
*/
#include <math.h>
#include "my.h"

float	calc_angle(int ac, char **av)
{
  float	angle_radian;
  float	angle_bat;

  angle_radian = acos((speed_z0(ac, av))/(sqrt(pow((speed_x0(ac, av)), 2) + pow((speed_y0(ac, av)), 2) + pow((speed_z0(ac, av)), 2))));
  angle_bat = 180*(angle_radian - (M_PI/2))/M_PI;
  return (angle_bat);
}
