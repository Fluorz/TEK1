/*
** memory.c for memory.c in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sat Mar 11 13:00:46 2017 Leo Lecherbonnier
** Last update Sat Mar 11 13:00:52 2017 Leo Lecherbonnier
*/

#include "vm.h"

int	init_memory()
{
  int	i = 0;

  if ((g_memory.memory = malloc(sizeof(char) * MEM_SIZE)) == NULL)
    return (1);
  while (i != MEM_SIZE)
    {
      g_memory.memory[i] = 0;
      i++;
    }
  return (0);
}
