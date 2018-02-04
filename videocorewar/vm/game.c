/*
** game.c for game.c in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sun Mar 12 13:31:14 2017 Leo Lecherbonnier
** Last update Fri Apr 21 12:07:57 2017 abdel cherkaoui
*/

#include "vm.h"

int		actualise_cycles(t_arena *arena, t_champ *champ, int i)
{
  if (champ->nbr_live >= NBR_LIVE)
    {
      arena->cycle_to_die -= 5;
      champ->nbr_live = 0;
    }
  else if (arena->current_cycle < 0)
    {
      arena->current_cycle = arena->cycle_to_die - 20;
      if (champ[i].cycle_to_die > arena->cycle_to_die)
	return (DEAD);
    }
  return (SUCCESS);
}

int		handle_cycles(t_arena *arena, t_champ *champ, int i)
{
  if (champ[i].cycle_to_die >= arena->cycle_to_die)
    return (DEAD);
  if (--(champ[i].cycle) == 0)
    {
      exec_command(champ, *arena, i);
    }
  return (actualise_cycles(arena, champ, i));
}

int	still_alive(t_champ *champ)
{
  int	i = 0;
  int	player_0 = 0;
  int	player_1 = 0;
  int	player_2 = 0;
  int	player_3 = 0;

  while (i != champ->nbr_player)
    {
      if (champ[i].id == 0)
	player_0 = 1;
      else if (champ[i].id == 1)
	player_1 = 1;
      else if (champ[i].id == 2)
	player_2 = 1;
      else if (champ[i].id == 3)
	player_3 = 1;
      i++;
    }
  return (player_0 + player_1 + player_2 + player_3);
}

t_arena	delete_elem(t_champ *champ, t_arena arena, int player)
{
  printf("delete 1\n");
  map[champ[player].pc] = champ[player].id + 48;
  printf("delete 2\n");
  champ[player].alive = DEAD;
  printf("delete 3\n");
  arena.nbr_alive--;
  printf("delete 4\n");
  champ->nbr_player--;
  printf("delete 5\n");
  champ[player].cycle_to_die = arena.cycle_to_die;
  printf("delete 6\n");
  return (arena);
}

int	handle_champ(t_arena *arena, t_champ *champ, int i)
{
  printf("la2zzzzz chap [%i] I  PC %i  ID %i\n",i, champ[i].pc, champ[i].id);
  map[champ[i].pc] = champ[i].id + 48;
  printf("la2zzzzz\n");
  if (handle_cycles(arena, champ, i) == DEAD)
    {
      printf("la2zzzzppp\n");
      delete_elem(champ, *arena, i);
      return (0);
    }
  printf("la2zzfsfffqf\n");
  champ[i].cycle_to_die++;
  printf("END\n");
  map[champ[i].pc] = 5 + 48;
  printf("END2\n");
  return (0);
}
