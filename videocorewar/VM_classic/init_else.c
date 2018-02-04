/*
** init_else.c for init_else.c in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Mar 30 02:45:19 2017 Leo Lecherbonnier
** Last update Sat Apr  1 21:51:10 2017 Leo Lecherbonnier
*/

#include "vm.h"

t_champ	*put_pc(t_champ *champ)
{
  if (champ->nbr_player == 4)
    {
      champ[0].pc = 0;
      champ[1].pc = MEM_SIZE / 4;
      champ[2].pc = MEM_SIZE / 4 + MEM_SIZE / 4;
      champ[3].pc = MEM_SIZE / 4 + MEM_SIZE / 4 + MEM_SIZE / 4;
    }
  else if (champ->nbr_player == 3)
    {
      champ[0].pc = 0;
      champ[1].pc = MEM_SIZE / 3;
      champ[2].pc = MEM_SIZE / 3 + MEM_SIZE / 3;
    }
  else if (champ->nbr_player == 2)
    {
      champ[0].pc = 0;
      champ[1].pc = MEM_SIZE / 2;
    }
  return (champ);
}

t_champ	*init_else_champ(t_champ *champ)
{
  int	i = 0;
  while (i != champ->nbr_player)
    {
      if ((champ[i].cmd = malloc(sizeof(t_champ) * 1)) == NULL)
	return (NULL);
      champ[i].cycle = 100;
      champ[i].new_pc = 0;
      champ[i].id = i;
      i++;
    }
  champ = put_pc(champ);
  if ((champ->live = malloc(sizeof (int) * 4)) == NULL)
    return (NULL);
  return (champ);
}
