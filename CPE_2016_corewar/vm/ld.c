/*
** ld.c for ld.c in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri Mar 31 23:51:59 2017 Leo Lecherbonnier
** Last update Sun Apr  2 13:43:33 2017 Leo Lecherbonnier
*/

#include "vm.h"

int	check_carry(t_champ *champ, int registre, int i)
{
  if (champ[i].registre[registre] == 0)
    champ[i].carry = 0;
  else
    champ[i].carry = 1;
  return (0);
}

int	instruction_ld(t_champ *champ, t_arena arena, int i)
{
  int	k = 0;
  int	where;
  int	registre;
  int	value;

  value = champ[i].cmd->args_value[0];
  registre = champ[i].cmd->args_value[1];
  if (registre < 1 || registre > 16)
    return (0);
  where = champ[i].pc + value % IDX_MOD;
  if (where < 4 || where > MEM_SIZE - 4)
    return (1);
  champ[i].registre[registre] = 0;
  while (k < 4)
    {
      champ[i].registre[registre] = ((champ[i].registre[registre] << 8
				      & 0xFFFFFF00) | (unsigned char)arena.map[where]);
      where++;
      k++;
    }
  check_carry(champ, registre, i);
  return (0);
}

int	instruction_lld(t_champ *champ, t_arena arena, int i)
{
  int	k = 0;
  int	where;
  int	registre;
  int	value;

  value = champ[i].cmd->args_value[0];
  registre = champ[i].cmd->args_value[1];
  if (registre < 1 || registre > 16)
    return (0);
  where = champ[i].pc + value;
  if (where < 4 || where > MEM_SIZE - 4)
    return (1);
  champ[i].registre[registre] = 0;
  while (k < 4)
    {
      champ[i].registre[registre] = ((champ[i].registre[registre] << 8
				      & 0xFFFFFF00) | (unsigned char)arena.map[where]);
      where++;
      k++;
    }
  check_carry(champ, registre, i);
  return (0);
}

int	instruction_ldi(t_champ *champ, t_arena arena, int i)
{
  int	value_1;
  int	value_2;
  int s;
  int	where;
  int	registre;
  int	k = 0;

  value_1 = champ[i].cmd->args_value[0];
  value_2 = champ[i].cmd->args_value[1];
  registre = champ[i].cmd->args_value[2];
  if (registre < 1 || registre > 16)
    return (0);
  s = champ[i].pc + value_1 % IDX_MOD;
  s = s + value_2;
  where = champ[i].pc + s % IDX_MOD;
  while (k < 4)
    {
      champ[i].registre[registre] = ((champ[i].registre[registre] << 8
				      & 0xFFFFFF00) | (unsigned char)arena.map[where]);
      where++;
      k++;
    }
  check_carry(champ, registre, i);
  return (0);
}

int	instruction_lldi(t_champ *champ, t_arena arena, int i)
{
  int	value_1;
  int	value_2;
  int s;
  int	where;
  int	registre;
  int	k = 0;

  value_1 = champ[i].cmd->args_value[0];
  value_2 = champ[i].cmd->args_value[1];
  registre = champ[i].cmd->args_value[2];
  if (registre < 1 || registre > 16)
    return (0);
  s = champ[i].pc + value_1;
  s = s + value_2;
  where = champ[i].pc + s;
  if (where < 4 || where > MEM_SIZE - 4)
    return (1);
  while (k < 4)
    {
      champ[i].registre[registre] = ((champ[i].registre[registre] << 8
				      & 0xFFFFFF00) | (unsigned char)arena.map[where]);
      where++;
      k++;
    }
  return (check_carry(champ, registre, i));
}
