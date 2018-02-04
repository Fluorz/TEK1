/*
** my_getnb.c for my get number in /home/monty.criel/Exercices piscines beta
** 
** Made by Monty Monty
** Login   <monty.criel@epitech.net>
** 
** Started on  Thu Oct 13 14:44:34 2016 Monty Monty
** Last update Mon Oct 17 14:00:16 2016 Monty Monty
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_strlen.c"

int	my_getnbr(char *str)
{
  int	i;
  int	len;
  int	result;

  i = 0;
  len = my_strlen(str);
  result = 0;
  if (str[i] == '-')
    {
      i = i + 1;
    }
  while (i < len)
    {
      result = result * 10 + (str[i] - '0');
      i = i + 1;
    }
  if (str[0] == '-')
    {
      result = result * (-1);
      return (result);
    }
  return (result);
}
