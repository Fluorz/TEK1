/*
** asm_funcs.c for corewar in /home/monty/Documents/Rendu/corewar/CPE_2016_corewar/ASM/monty/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sat Mar 11 13:30:41 2017 Monty Criel
** Last update Sun Apr  2 23:27:01 2017 Sid
*/

#include <stdlib.h>
#include "op.h"

int	change_endian(int nb)
{
  int	tmp;
  char	dev;

  tmp = nb;
  nb = 0;
  dev = -8;
  while ((dev += 8) != sizeof(int) * 8)
    {
      nb <<= 8;
      nb |= ((tmp >> dev) & 0xFF);
    }
  return (nb);
}

char	*my_find_label(char *str)
{
  char	*label;
  int	i;
  int	x;
  int	tmp;

  i = 0;
  while (str[i] != LABEL_CHAR)
    i += 1;
  i += 1;
  tmp = i;
  while (str[i] != '\0')
    i += 1;
  label = malloc(sizeof(char) * (i - tmp + 1));
  if (label == NULL)
    exit(84);
  x = 0;
  i = tmp;
  while (str[i] != '\0')
    {
      label[x] = str[i];
      i += 1;
      x += 1;
    }
  label[x] = '\0';
  return (label);
}
