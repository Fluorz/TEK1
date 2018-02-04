/*
** end_game.c for end game in /home/cherkaoui/Bureau/CPE_2016_corewar/VM
**
** Made by Cherkaoui
** Login   <abderrahim.cherkaoui@epitech.eu>
**
** Started on  Sun Apr  2 19:07:48 2017 Cherkaoui
** Last update Sun Apr  2 18:18:27 2017 Leo Lecherbonnier
*/

#include "vm.h"
#include "my.h"

t_champ	*end_alive(t_champ *champ, t_my_core cr, int i)
{
  my_printf("Win %s\n", winner);
  sfMusic_destroy(cr.music);
  sfMusic_destroy(cr.shot);
  sfTexture_destroy(cr.texture);
  sfTexture_destroy(cr.texture2);
  sfTexture_destroy(cr.texture3);
  sfRenderWindow_destroy(cr.window);
  return (champ);
}

t_px	t_px_init(t_champ *champ, t_px p)
{
  p.p1 = 0;
  p.p2 = 0;
  p.p3 = 0;
  p.p4 = 0;
  p.pp1 = 1;
  p.pp2 = 1;
  p.pp3 = 1;
  p.pp4 = 1;
  return (p);
}

t_my_core	t_px_end(t_champ *champ, t_px p, t_my_core cr)
{
  cr.life1 = p.p1 / p.pp1;
  cr.life2 = p.p2 / p.pp2;
  cr.life3 = p.p3 / p.pp3;
  cr.life4 = p.p4 / p.pp4;
  cr.ictdie = champ->cycle_to_die;
  cr.iprocess = champ->nbr_player;
  cr.istillalive = still_alive(champ);
  return (cr);
}

void	champ_stat(int *pp, int *p , int cycle)
{
  *pp = *pp + 1;
  *p = *p + cycle;
}

t_my_core	moyen(t_champ *champ, t_my_core cr, t_arena arena, int i)
{
  t_px		p;

  cr.cycle = arena.current_cycle;
  cr.max = arena.cycle_to_die;
  p = t_px_init(champ, p);
  while (++i != champ->nbr_player)
    if (champ[i].id == 0 && champ[i].alive == ALIVE)
      champ_stat(&p.pp1, &p.p1 , champ[i].cycle_to_die);
    else if (champ[i].id == 1 && champ[i].alive == ALIVE)
      champ_stat(&p.pp2, &p.p2 , champ[i].cycle_to_die);
    else if (champ[i].id == 2 && champ[i].alive == ALIVE)
      champ_stat(&p.pp3, &p.p3 , champ[i].cycle_to_die);
    else if (champ[i].id == 3 && champ[i].alive == ALIVE)
      champ_stat(&p.pp4, &p.p4 , champ[i].cycle_to_die);
  cr  = t_px_end(champ, p, cr);
  return (cr);
}
