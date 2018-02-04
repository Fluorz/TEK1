/*
** fork.c for fork.c in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri Mar 31 23:25:40 2017 Leo Lecherbonnier
** Last update Sat Apr  1 13:04:23 2017 Leo Lecherbonnier
*/

#include "vm.h"

int	instruction_fork(t_champ *champ, t_arena arena, int i)
{
  int	pc;

  pc = champ[i].pc + champ[i].cmd->args_value[0] % IDX_MOD;
  if (pc > MEM_SIZE || pc < 0)
    return (1);
  champ = struct_op(champ, i, pc);
  champ->nbr_player = champ->nbr_player + 1;
  return (SUCCESS);
}

int	instruction_lfork(t_champ *champ, t_arena arena, int i)
{
  int	pc;

  pc = champ[i].pc + champ[i].cmd->args_value[0];
  if (pc > MEM_SIZE || pc < 0)
    return (1);
  champ = struct_op(champ, i, pc);
  champ->nbr_player = champ->nbr_player + 1;
  return (SUCCESS);
}

int instruction_aff(t_champ *champ, t_arena arena, int i)
{
  return (SUCCESS);
}
