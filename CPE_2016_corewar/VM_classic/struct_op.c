/*
** struct_op.c for struct_op.c in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri Mar 31 23:00:55 2017 Leo Lecherbonnier
** Last update Sat Apr  1 21:37:18 2017 Leo Lecherbonnier
*/

#include "vm.h"

t_champ	*struct_op(t_champ *champ, int id, int pc)
{
  t_champ	*new_champ;
  int	i = 0;
  int	j = 0;
  int	new_line = 0;

  new_line = champ->nbr_player;
  if ((new_champ = malloc(sizeof(t_champ) * new_line + 1)) == NULL)
    exit(my_putstr("Problem with memory champs"));
  new_champ = champ;
  while (i != new_line)
    {
      if (champ[i].alive == ALIVE)
	{
    new_champ[j] = champ[i];
	  j++;
	}
      i++;
    }
  new_champ[j + 1] = champ[id];
  new_champ[j + 1].pc = pc;
  new_champ[j + 1].alive = ALIVE;
  map[pc] = 5 + 48;
  return (new_champ);
}
