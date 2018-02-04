/*
** last_number.c for last_number.c in /home/lecherbonnier/Projet/CPE_2016_stumper5/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri May 19 14:03:30 2017 Leo Lecherbonnier
** Last update Fri May 19 16:34:27 2017 Monty Criel
*/

#include "my.h"

char	*str_five(int swag, char c)
{
  char	*str;

  str = copy("00000\n0    \n0000 \n    0\n0000 \n");
  if (swag == TRUE)
    insert_swag(str, c);
  return (str);
}

char	*str_six(int swag, char c)
{
  char	*str;

  str = copy(" 000 \n0    \n0000 \n0   0\n 000 \n");
  if (swag == TRUE)
    insert_swag(str, c);
  return (str);
}

char	*str_seven(int swag, char c)
{
  char	*str;

  str = copy("00000\n    0\n   0 \n  0  \n 0   \n");
  if (swag == TRUE)
    insert_swag(str, c);
  return (str);
}

char	*str_eight(int swag, char c)
{
  char	*str;

  str = copy(" 000 \n0   0\n 000 \n0   0\n 000 \n");
  if (swag == TRUE)
    insert_swag(str, c);
  return (str);
}

char	*str_nine(int swag, char c)
{
  char	*str;

  str = copy(" 000 \n0   0\n 0000\n    0\n 000 \n");
  if (swag == TRUE)
    insert_swag(str, c);
  return (str);
}
