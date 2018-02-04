/*
** my_putchar.c for my_putchar in /home/leo/CPool_Day07/lib/my
**
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
**
** Started on  Tue Oct 11 12:38:57 2016 leo lecherbonnier
** Last update Mon Jan 30 11:30:48 2017 Leo Lecherbonnier
*/
#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
