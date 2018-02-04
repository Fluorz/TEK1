/*
** my_putchar.c for my putchar in /home/monty.criel/Rendu/CPool_Day07/lib/my
** 
** Made by Monty Monty
** Login   <monty.criel@epitech.net>
** 
** Started on  Tue Oct 11 10:30:20 2016 Monty Monty
** Last update Fri Oct 14 09:35:34 2016 Monty Monty
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
