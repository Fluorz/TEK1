/*
** disp_my_putchar.c for disp my putchar in /home/monty/Documents/Projets/Système Unix/PSU_2016_my_printf/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Wed Nov 16 18:45:02 2016 Monty Criel
** Last update Fri Nov 25 16:18:42 2016 Monty Criel
*/

#include <stdarg.h>
#include <unistd.h>

void	my_putchar(char c);

void	disp_my_putchar(va_list list)
{
  my_putchar(va_arg(list, int));
}
