/*
** add.c for add.c in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sat Apr  1 00:21:46 2017 Leo Lecherbonnier
** Last update Sun Apr  2 13:50:03 2017 Leo Lecherbonnier
*/

#include "vm.h"

int	instruction_add(t_champ *champ, t_arena arena, int i)
{
  int	registre_1 = 0;
  int	registre_2 = 0;
  int	registre_3 = 0;

  registre_1 = champ[i].cmd->args_value[0];
  registre_1 = champ[i].cmd->args_value[1];
  registre_1 = champ[i].cmd->args_value[2];
  if (registre_1 > 1 && registre_1 < 16 &&
      registre_2 > 1 && registre_2 < 16 &&
      registre_3 > 1 && registre_3 < 16)
    {
      champ[i].registre[registre_1] = champ[i].registre[registre_2] +
	  champ[i].registre[registre_3];
    }
  if (champ[i].registre[registre_1] == 0)
    champ[i].carry = 0;
  else
    champ[i].carry = 1;
  return (SUCCESS);
}

int	instruction_sub(t_champ *champ, t_arena arena, int i)
{
  int	registre_1 = 0;
  int	registre_2 = 0;
  int	registre_3 = 0;

  registre_1 = champ[i].cmd->args_value[0];
  registre_1 = champ[i].cmd->args_value[1];
  registre_1 = champ[i].cmd->args_value[2];
  if (registre_1 > 1 && registre_1 < 16 &&
      registre_2 > 1 && registre_2 < 16 &&
      registre_3 > 1 && registre_3 < 16)
    {
      champ[i].registre[registre_1] = champ[i].registre[registre_2] -
	  champ[i].registre[registre_3];
    }
  if (champ[i].registre[registre_1] == 0)
    champ[i].carry = 0;
  else
    champ[i].carry = 1;
  return (SUCCESS);
}

int	instruction_and(t_champ *champ, t_arena arena, int i)
{
  int	value_1 = 0;
  int	value_2 = 0;
  int	value_3 = 0;

  if (champ[i].cmd->args_type[0] == 1)
    {
      if (champ[i].cmd->args_value[0] < 1 || champ[i].cmd->args_value[0] > 16)
	return (0);
      value_1 = champ[i].registre[champ[i].cmd->args_value[0]];
    }
  else
    value_1 = champ[i].cmd->args_value[0];
  if (champ[i].cmd->args_type[1] == 1)
    {
      if (champ[i].cmd->args_value[1] < 1 || champ[i].cmd->args_value[1] > 16)
	return (0);
      value_2 = champ[i].registre[champ[i].cmd->args_value[1]];
    }
  else
    value_2 = champ[i].cmd->args_value[1];
  value_3 = champ[i].cmd->args_value[2];
    if (value_3 < 1 || value_3 > 16)
  return (0);
  champ[i].registre[value_3] = value_1 + value_2;
  return (check_carry(champ, value_3, i));
}

int	instruction_or(t_champ *champ, t_arena arena, int i)
{
  int	registre_1 = 0;
  int	registre_2 = 0;
  int	registre_3 = 0;

  registre_1 = champ[i].cmd->args_value[0];
  registre_1 = champ[i].cmd->args_value[1];
  registre_1 = champ[i].cmd->args_value[2];
  if (registre_1 > 1 && registre_1 < 16 &&
      registre_2 > 1 && registre_2 < 16 &&
      registre_3 > 1 && registre_3 < 16)
    {
      champ[i].registre[registre_1] = champ[i].registre[registre_2] |
	  champ[i].registre[registre_3];
    }
  return (SUCCESS);
}
