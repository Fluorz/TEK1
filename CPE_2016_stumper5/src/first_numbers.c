/*
** first_numbers.c for stumper5 in /home/monty/Documents/colle/CPE_2016_stumper5/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Fri May 19 13:24:23 2017 Monty Criel
** Last update Jun May 19 16:41:49 2017
*/

#include "my.h"

char	*str_zero(int swag, char c)
{
  char	*str;

  str = copy(" 000 \n0   0\n0   0\n0   0\n 000 \n");
  if (swag == TRUE)
    insert_swag(str, c);
  return (str);
}

char	*str_one(int swag, char c)
{
  char	*str;

  str = copy(" 000 \n0 00 \n  00 \n  00 \n 0000\n");
  if (swag == TRUE)
    insert_swag(str, c);
  return (str);
}

char	*str_two(int swag, char c)
{
  char	*str;

  str = copy(" 000 \n0   0\n   0 \n 0   \n00000\n");
  if (swag == TRUE)
    insert_swag(str, c);
  return (str);
}

char	*str_three(int swag, char c)
{
  char	*str;

  str = copy("0000 \n    0\n 000 \n    0\n0000 \n");
  if (swag == TRUE)
    insert_swag(str, c);
  return (str);
}

char	*str_four(int swag, char c)
{
  char	*str;

  str = copy("  00 \n 0 0 \n0  0 \n00000\n   0 \n");
  if (swag == TRUE)
    insert_swag(str, c);
  return (str);
}
