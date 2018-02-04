/*
** init_arena.c for init_arena?c in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sun Mar 12 13:19:51 2017 Leo Lecherbonnier
** Last update Fri Mar 31 22:56:05 2017 Leo Lecherbonnier
*/

#include "vm.h"

t_arena	init_pc(t_arena arena)
{
  if ((arena.pc = malloc(sizeof(int) * 4)) == NULL)
    exit (0);
  return (arena);
}

int	my_op_strdup(char *dest, char *elem, int start, int len)
{
  int	j = start;
  int	i = 0;

  while (i != len)
    {
      dest[j] = elem[i];
      i++;
      j++;
    }
  return (SUCCESS);
}

int			create_map(t_arena arena, t_champ *champ)
{
  int		i = 0;
  int		j = 0;
  int		pc;

  while (i != champ->nbr_player)
    {
      pc = champ[i].pc;
      j = pc;
      while (j != champ[i].header->prog_size + pc)
	{
	  map[j] = i + 48;
	  j++;
	}
      i++;
    }
  return (SUCCESS);
}

t_arena	put_code(t_arena arena, t_champ *champ)
{
  int	player = 0;

  while (player != champ->nbr_player)
    {
      my_op_strdup(arena.map, champ[player].code, champ[player].pc,
		  champ[player].header->prog_size);
      player++;
    }
  return (arena);
}

t_arena	init_arena(int	player, t_champ *champ)
{
  t_arena arena;

  int	i = 0;

  if ((arena.map = malloc(sizeof(char *) * MEM_SIZE)) == NULL)
    exit (0);
  while (i != MEM_SIZE)
    {
      arena.map[i] = 0;
      map[i] = 4 + 48;
      i++;
    }
  arena.current_cycle = 0;
  arena.cycle_to_die = CYCLE_TO_DIE;
  arena.nbr_alive = player;
  arena.nbr_player = player;
  arena = init_pc(arena);
  arena = put_code(arena, champ);
  create_map(arena, champ);
  return (arena);
}
