/*
** take.c for take.c in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Mar 30 03:31:18 2017 Leo Lecherbonnier
** Last update Sun Apr  2 16:53:17 2017 Leo Lecherbonnier
*/

#include "vm.h"

/*1 byte*/
int	take_register(t_arena arena, t_champ *champ, int i, int *index)
{
  champ[i].cmd->args_value[champ[i].j] = arena.map[*index];
  *index = *index + 1;
  return (0);
}

/*2 bite*/
int	take_indirect(t_arena arena, t_champ *champ, int i, int *index)
{
  int	k = 0;
  int	arg = 0;

  arg = champ[i].j;
  while (k < 2)
{
      champ[i].cmd->args_value[arg] = ((champ[i].cmd->args_value[arg] << 8
				      & 0xFFFFFF00) | (unsigned char)arena.map[*index]);
      *index = *index + 1;
      k++;
  }
  champ[i].cmd->args_value[arg] = (short int)champ[i].cmd->args_value[arg];
  return (0);
}

/*4 bite*/
int	take_direct(t_arena arena, t_champ *champ, int i, int *index)
{
  int	k = 0;
  int	arg = 0;

  arg = champ[i].j;
  while (k < 4)
{
      champ[i].cmd->args_value[arg] = ((champ[i].cmd->args_value[arg] << 8
				      & 0xFFFFFF00) | (unsigned char)arena.map[*index]);
      *index = *index + 1;
      k++;
  }
  return (0);
}
