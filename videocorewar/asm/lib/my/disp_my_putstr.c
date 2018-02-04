/*
** disp_my_putstr.c for disp my put str in /home/monty/Documents/Projets/Système Unix/PSU_2016_my_printf/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Wed Nov 16 22:24:25 2016 Monty Criel
** Last update Sat Nov 19 21:39:14 2016 Monty Criel
*/

#include <stdarg.h>
#include <unistd.h>

void	my_putchar(char c);

int	my_putstr(char *str)
{
  int	letter;

  if (str == NULL)
    {
      my_putstr("(null)");
      return (0);
    }
  letter = 0;
  while (str[letter] != '\0')
    {
      my_putchar(str[letter]);
      letter = letter + 1;
    }
  return (letter);
}

void	disp_my_putstr(va_list list)
{
  my_putstr(va_arg(list, char*));
}
