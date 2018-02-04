/*
** my_putchar.c for my_putchar.c in /home/pierre.narcisi/CPool_Day07/lib/my
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.net>
**
** Started on  Tue Oct 11 16:42:41 2016 Pierre Narcisi
** Last update Tue Nov 15 11:20:26 2016 Pierre Narcisi
*/

#include "my.h"
#include <unistd.h>

void my_putchar(char c, int *m)
{
  write(1, &c, 1);
  (*m)++;
}
