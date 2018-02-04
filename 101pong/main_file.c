/*
** main_file.c for main_file in /root/101pong/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Mon Nov  7 14:39:29 2016 Leo Lecherbonnier
** Last update Tue Nov  8 15:48:29 2016 Leo Lecherbonnier
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
int	print_speed(void)
{
  write(1, "The speed vector coordinates are :\n", 35);
  return (0);
}

void	print_time(char *c)
{
  write(1, "At time t+", 10);
  my_putstr(c);
  write(1, ", ball coordinates will be :", 28);
  my_putchar('\n');
}

int	main(int ac, char **av)
{
  float	d;
  print_speed();
  printf("(%.2f;", speed_x0(ac, av));
	 printf("%.2f;", speed_y0(ac, av));
	 printf("%.2f)\n", speed_z0(ac, av));
  print_time(av[7]);
  printf("(%.2f;", x0_t(ac, av));
  printf("%.2f;", y0_t(ac, av));
  printf("%.2f)\n", z0_t(ac, av));
  d = calc_angle(ac, av);
  if (d >= 0 && d <= 90)
{
      printf("The incidence angle is :\n");
      printf("%.2f degrees\n", calc_angle(ac, av));
      return (0);
    }
  else
    printf("The ball won't reach the bat\n");
  return (0);
}
