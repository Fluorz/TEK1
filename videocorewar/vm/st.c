/*
** st.c for st.c in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sat Apr  1 00:05:14 2017 Leo Lecherbonnier
** Last update Thu Apr 20 12:44:11 2017 abdel cherkaoui
*/

#include "vm.h"

static void	write_on_arena(t_champ *champ, int pos, int size, int i)
{
  int		k;

  k = size - 1;
  while (k >= 0 && pos < MEM_SIZE && pos > 0)
    {
      map[pos] = champ[i].id + 48;
      pos++;
      k--;
    }
}

int	instruction_st(t_champ *champ, t_arena arena, int i)
{
  int	where;

  where = champ[i].pc + champ[i].cmd->args_value[1] % IDX_MOD;
	if (champ[i].cmd->args_type[1] == 0 && champ[i].cmd->args_value[0] > 1 &&
    champ[i].cmd->args_value[0] < 16)
    {
      if (where < 0)
	where = -(where) % IDX_MOD;
      else if (where > MEM_SIZE)
	where = where - MEM_SIZE - 4;
      write_on_arena(champ, where, 4, i);
    }
  else if (champ[i].cmd->args_type[1] == 1 && champ[i].cmd->args_value[1] > 1
	   && champ[i].cmd->args_value[1] < 16 &&
	   champ[i].cmd->args_value[0] > 1 &&
   	   champ[i].cmd->args_value[0] < 16)
    {
      champ[i].registre[champ[i].cmd->args_value[1]] =
      champ[i].registre[champ[i].cmd->args_value[0]];
    }
  return (0);
}

int	instruction_sti(t_champ *champ, t_arena arena, int i)
{
  int	registre;
  int	v_1;
  int	v_2;
  int	where;

  registre = champ[i].cmd->args_value[0];
  if (registre < 1 || registre > 16)
    return (0);
  if (champ[i].cmd->args_type[1] == 1)
    {
      v_1 = champ[i].cmd->args_value[1];
      if (v_1 < 1 || v_1 > 16) return (0);
      v_1 = champ[i].registre[v_1];
    }
  else
    v_1 = champ[i].cmd->args_value[1];
  if (champ[i].cmd->args_type[2] == 1)
    {
      v_2 = champ[i].cmd->args_value[2];
      if (v_2 < 1 || v_2 > 16) return (0);
      v_2 = champ[i].registre[v_2];
    }
  else
    v_2 = champ[i].cmd->args_value[2];
  return (s_s(champ, arena, i, where = champ[i].pc + (v_1 + v_2) % IDX_MOD));
}

int	s_s(t_champ *champ, t_arena arena, int i, int where)
{
  if (where < 0)
    where = -(where) % IDX_MOD;
  write_on_arena(champ, where, 4, i);
  return (SUCCESS);
}
