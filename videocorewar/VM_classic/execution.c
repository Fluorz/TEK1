/*
** execution.c for execution.c in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Mar 28 15:30:34 2017 Leo Lecherbonnier
** Last update Sun Apr  2 17:05:58 2017 Leo Lecherbonnier
*/

#include "vm.h"

void	get_args(t_arena arena, t_champ *champ, int i)
{
  int	k = 0;
  int	j = 0;

  j = champ[i].pc;
  champ[i].cmd->args_value[0] = 0;
  if (arena.map[champ[i].pc] == 1)
    {
      champ[i].cmd->args_type[0] = 2;
      while (k <= 4)
	{
	  champ[i].cmd->args_value[0] = ((champ[i].cmd->args_value[0] << 8
					  & 0xFFFFFF00) | (unsigned char)arena.map[j++]);
	  k++;
	}
      champ[i].pc += k;
      return ;
    }
  else
    get_args_next(arena, champ, i);
}

int get_args_next(t_arena arena, t_champ *champ, int i)
{
  int	k = 0;
  int	j = 0;

  champ[i].cmd->args_type[0] = 0;
  j = champ[i].pc;
  champ[i].cmd->args_value[0] = 0;
  while (k <= 2)
    {
      champ[i].cmd->args_value[0] = ((champ[i].cmd->args_value[0] << 8
				    & 0xFFFFFF00) | (unsigned char)arena.map[j++]);
      k++;
    }
  champ[i].cmd->args_value[0] = (short int)champ[i].cmd->args_value[0];
  champ[i].pc += k;
  return (SUCCESS);
}

void	get_params(t_arena arena, t_champ *champ, int i)
{
  int	index = 0;
  int	op = 0;
  int	j = -1;
  int	k = 6;
  int	arg = 0;

  index = champ[i].pc + 2;
  op = champ[i].cmd->instruction;
  while (++j < op_tab[op - 1].nbr_args)
    {
      champ[i].cmd->args_type[j] = (champ[i].cmd->coding_byte >> k) & 3;
      champ[i].j = j;
      arg = champ[i].cmd->args_type[j];
      if (arg == 1)
	take_register(arena, champ, i, &index);
      else if (arg == 2 && op != 11 && op != 10 && op != 14)
	take_direct(arena, champ, i, &index);
      else if (arg == 2 && (op == 11 || op == 10 || op == 14))
	take_indirect(arena, champ, i, &index);
      else if (arg == 0)
	take_indirect(arena, champ, i, &index);
      k = k - 2;
      champ[i].pc = index;
    }
  champ[i].pc = index;
}

int	exec_command(t_champ *champ, t_arena arena, int i)
{
  reset_champ(champ, i);
	if (arena.map[champ[i].pc] < 1 || arena.map[champ[i].pc] > 16)
    {
      champ[i].pc = (champ[i].pc + 1) % MEM_SIZE;
      champ[i].cycle = 1;
      return (FAILURE);
    }
  champ[i].cmd->instruction = arena.map[champ[i].pc];
  if (arena.map[champ[i].pc] == 1 || arena.map[champ[i].pc] == 9
      || arena.map[champ[i].pc] == 12 || arena.map[champ[i].pc] == 15)
    get_args(arena, champ, i);
  else
    {
      champ[i].cmd->coding_byte = ((champ[i].cmd->coding_byte << 8
			& 0xFFFFFF00) | (unsigned char)arena.map[champ[i].pc + 1]);
      get_params(arena, champ, i);
    }
  champ[i].cycle = op_tab[champ[i].cmd->instruction - 1].nbr_cycles;
  exec_instruction(champ, arena, i);
  return (SUCCESS);
}
