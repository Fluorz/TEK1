/*
** debug.c for debug.c in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri Mar 31 12:35:08 2017 Leo Lecherbonnier
** Last update Sun Apr  2 16:45:20 2017 Leo Lecherbonnier
*/

#include "vm.h"

int	starter(t_champ *champ, t_arena arena, int i)
{
  my_printf("---STARTER--\n");
  my_printf("champ alive = %d\n", still_alive(champ));
  my_printf("champs->nbr_player = %d\n", champ->nbr_player);
  my_printf("arena.current_cycle %d\n", arena.cycle_to_die);
  my_printf("still alive = %d\n", still_alive(champ));
  my_printf("!champ[i].cycle = %d\n", champ[i].cycle);
  my_printf("!champ[i + 1].cycle = %d\n", champ[i + 1].cycle);
  my_printf("champ[0].pc = %d\n", champ[0].pc);
  my_printf("champ[1].pc = %d\n", champ[1].pc);
  my_printf("champ[2].pc = %d\n", champ[2].pc);
  my_printf("champ[3].pc = %d\n", champ[3].pc);
  my_printf("champ[i + 1].pc %d\n", champ[i + 1].pc);
  my_printf("---GAME-----\n");
  return (SUCCESS);
}

int	debug(t_champ *champ, t_arena arena, int i)
{
  my_printf("START EXEC INSTRUCTION\n");

  my_printf("CHAMP = %d\n", i);
  my_printf("CODING BYTE = %x\n", champ[i].cmd->coding_byte);
  my_printf("Instruction = %d\n", champ[i].cmd->instruction);

  my_printf("ARG_TYPE 0 = %d\n", champ[i].cmd->args_type[0]);
  my_printf("ARG_VALUE 0 = %d\n", champ[i].cmd->args_value[0]);

  my_printf("ARG_TYPE 1 = %d\n", champ[i].cmd->args_type[1]);
  my_printf("ARG_VALUE 1 = %d\n", champ[i].cmd->args_value[1]);

  my_printf("ARG_TYPE 2 = %d\n", champ[i].cmd->args_type[2]);
  my_printf("ARG_VALUE 2 = %d\n", champ[i].cmd->args_value[2]);

  my_printf("ARG_TYPE 3 = %d\n", champ[i].cmd->args_type[3]);
  my_printf("ARG_VALUE 3 = %d\n", champ[i].cmd->args_value[3]);

  my_printf("PC = %d\n", champ[i].pc);
  my_printf("STOP\n");
  return (SUCCESS);
}
