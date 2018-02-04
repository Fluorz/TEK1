/*
** instruction.c for instruction.c in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri Mar 31 12:39:11 2017 Leo Lecherbonnier
** Last update Sun Apr  2 13:53:18 2017 Leo Lecherbonnier
*/

#include "vm.h"

void	exec_instruction(t_champ *champ, t_arena arena, int i)
{
  int	op;

  op = champ[i].cmd->instruction;
  if (op == 1)
    instruct_live(champ, arena, i);
  else if (op == 2)
    instruction_ld(champ, arena, i);
  else if (op == 3)
    instruction_st(champ, arena, i);
  else if (op == 4)
    instruction_add(champ, arena, i);
  else if (op == 5)
    instruction_sub(champ, arena, i);
  else if (op == 6)
    instruction_and(champ, arena, i);
  else if (op == 7)
    instruction_or(champ, arena, i);
  else if (op == 9)
    instrcution_zjmp(champ, arena, i);
  else if (op == 10)
    instruction_ldi(champ, arena, i);
  else if (op == 11)
    instruction_sti(champ, arena, i);
  go_other(champ, arena, i);
}

int	go_other(t_champ *champ, t_arena arena, int i)
{
  int	op;

  op = champ[i].cmd->instruction;
  if (op == 12)
    instruction_fork(champ, arena, i);
  else if (op == 13)
    instruction_lld(champ, arena, i);
  else if (op == 14)
    instruction_lldi(champ, arena, i);
  else if (op == 15)
    instruction_lfork(champ, arena, i);
  return (0);
}
int	reset_champ(t_champ *champ, int i)
{
  champ[i].cmd->instruction = 0;
  champ[i].cmd->args_value[0] = 0;
  champ[i].cmd->args_value[1] = 0;
  champ[i].cmd->args_value[2] = 0;
  champ[i].cmd->args_value[3] = 0;
  champ[i].cmd->args_type[0] = 0;
  champ[i].cmd->args_type[1] = 0;
  champ[i].cmd->args_type[2] = 0;
  champ[i].cmd->args_type[3] = 0;
  champ[i].cmd->coding_byte = 0;
  return (0);
}
