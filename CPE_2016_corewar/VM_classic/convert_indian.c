/*
** convert_indian.c for convert_indian.c in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Mar 27 20:05:54 2017 Leo Lecherbonnier
** Last update Mon Mar 27 20:06:02 2017 Leo Lecherbonnier
*/

#include "vm.h"

void		convert_indian(void *input, int n)
{
  char		tmp;
  char		*output;
  int		low;
  int		hi;

  output = input;
  low = -1;
  hi = n;
  while (--hi > ++low)
    {
      tmp = output[low];
      output[low] = output[hi];
      output[hi] = tmp;
    }
}
