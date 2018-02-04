/*
** start_battle.c for start_battle.c in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sat Apr  1 03:47:37 2017 Leo Lecherbonnier
** Last update Fri Apr 21 12:14:57 2017 abdel cherkaoui
*/

#include "vm.h"
#include "my.h"

t_my_core       fase(t_my_core cr)
{
  if (cr.fase == 0)
    cr = print_menu(cr);
  else if (cr.fase == 1)
    cr = print_select(cr);
  else if (cr.fase == 2)
    cr = print_game(cr);
  else if (cr.fase == 4)
    cr = print_converter(cr);
  else if (cr.fase == 5)
    cr = print_credit(cr);
  return (cr);
}

int		check_dump(t_arena *arena, t_option option)
{
  arena->current_cycle++;
  if (arena->current_cycle == option.dump)
    print_arena(map, MEM_SIZE);
  return (SUCCESS);
}

t_my_core	start_battle(t_champ *champ, t_arena arena, t_option option, t_my_core cr)
{
  int		i;
  int		stock;

  i = 0;
  /* champ[i].pc = arena.pc[i]; */
  stock = 0;
  /* cr = init_game(cr); */
  while (still_alive(champ) > 1)
    {
      sfRenderWindow_clear(cr.window, sfBlack);
      if (cr.fase == 6)
	break ;
      cr = print_game(cr);
      cr = moyen(champ, cr, arena, -1);
      i = 0;
      while (i < champ->nbr_player && still_alive(champ) > 1)
	{
	  if (champ[i].alive != DEAD)
	    handle_champ(&arena, champ, i);
	  i++;
	  check_dump(&arena, option);
	}
      sfRenderWindow_display(cr.window);
    }
  champ = end_alive(champ, cr, i);
  return (cr);
}
