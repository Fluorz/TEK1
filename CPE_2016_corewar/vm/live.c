/*
** live.c for live.c in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri Mar 31 01:08:38 2017 Leo Lecherbonnier
** Last update Sun Apr  2 18:15:35 2017 Leo Lecherbonnier
*/

#include "vm.h"

int	instruct_live(t_champ *champ, t_arena arena, int i)
{
  if ((winner = malloc(sizeof (char) * 129)) == NULL)
      return (84);
  champ[i].cycle_to_die = 0;
  champ->nbr_live = champ->nbr_live + 1;
  winner = champ[i].name;
  my_printf("CHAMPION %s ALIVE\n", champ[i].name);
  return (0);
}

int	instrcution_zjmp(t_champ *champ, t_arena arena, int i)
{
  int	pc;
  int	arg;

  if (champ[i].carry == 0)
    {
      arg = champ[i].cmd->args_value[0];
      pc = champ[i].pc;
      champ[i].pc = pc + arg % IDX_MOD;
      return (SUCCESS);
    }
  return (SUCCESS);
}
