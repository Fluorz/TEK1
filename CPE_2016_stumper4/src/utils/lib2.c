/*
** lib2.c for lib2 in /home/ferlet_n/colle/CPE_2016_stumper4
** 
** Made by Nicolas Ferlet
** Login   <ferlet_n@epitech.net>
** 
** Started on  Tue May  9 07:26:22 2017 Nicolas Ferlet
** Last update Tue May  9 07:27:20 2017 Nicolas Ferlet
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return ;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
