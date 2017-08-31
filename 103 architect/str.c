/*
** str.c for str.c in /home/lecherbonnier/103 architect/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Dec 20 14:29:35 2016 Leo Lecherbonnier
** Last update Tue Dec 20 14:29:38 2016 Leo Lecherbonnier
*/

#include "architecte.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      str++;
    }
}

void	my_error(char *s)
{
  printf("\033[01;31m%s\n", s);
  printf("\033[0;37m");
  exit (0);
}

void	check_error_one(char *str)
{
  if (my_str_isnum(str) == 0)
    my_error("After option T or H, you must enter two numbers\nExecute ./man_103 to read the man");
}

void	check_error_two(char *str)
{
  if (my_str_isnum(str) == 0)
    my_error("After option R or S, you must enter only on number\nExecute ./man_103 to read the man");
}
