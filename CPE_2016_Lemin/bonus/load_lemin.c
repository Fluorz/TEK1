/*
** load_lemin.c for lemin in /home/monty/Documents/Rendu/lemin/CPE_2016_Lemin/bonus/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Fri Apr 28 18:11:19 2017 Monty Criel
** Last update Sun Apr 30 23:18:35 2017 Monty Criel
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

void		load_ants(t_lemin *lemin, t_gui *gui)
{
  t_ant	*ant;
  t_ant_list	*ant_list;
  t_room	*tmp;
  sfVector2f	pos;
  int		i;

  init_ant_list(lemin, gui);
  ant_list = malloc(sizeof(t_ant_list));
  ant_list->head = NULL;
  if (ant_list == NULL)
    return;
  pos.x = lemin->list->head->coord.x;
  pos.y = lemin->list->head->coord.y;
  i = 0;
  while (i != lemin->ants)
    {
      ant = create_ant(gui, pos, (i + 1));
      append_ant(ant_list, ant);
      i += 1;
    }
  lemin->list->head->ant_list = ant_list;
}

void			load_lemin(t_lemin *lemin, t_gui *gui)
{
  t_room		*tmp;
  sfVector2f		pos;

  tmp = lemin->list->head;
  while (tmp != NULL)
    {
      pos.x = 128;
      pos.y = 128;
      tmp->room = create_sprite();
      sfSprite_setOrigin(tmp->room, pos);
      pos.x = tmp->pos.x * 40 + 40;
      pos.y = tmp->pos.y * 40 + 40;
      sfSprite_setPosition(tmp->room, pos);
      pos.x = 0.35;
      pos.y = 0.35;
      sfSprite_setScale(tmp->room, pos);
      sfSprite_setTexture(tmp->room, gui->room_texture, sfTrue);
      if (my_strcmp(tmp->type, "start") == 0)
	sfSprite_setColor(tmp->room, sfGreen);
      if (my_strcmp(tmp->type, "end") == 0)
	sfSprite_setColor(tmp->room, sfRed);
      tmp = tmp->next;
    }
  load_ants(lemin, gui);
}

void		draw_rooms(t_lemin *lemin, t_gui *gui)
{
  t_room	*tmp;

  tmp = lemin->list->head;
  while (tmp != NULL)
    {
      sfRenderWindow_drawSprite(gui->window, tmp->room, NULL);
      tmp = tmp->next;
    }
  free(tmp);
}

void		draw_ants(t_lemin *lemin, t_gui *gui)
{
  t_room	*tmp1;
  t_ant	*tmp2;

  tmp1 = lemin->list->head;
  while (tmp1 != NULL)
    {
      if (tmp1->ant_list != NULL)
	{
	  tmp2 = tmp1->ant_list->head;
	  while (tmp2 != NULL)
	    {
	      sfRenderWindow_drawSprite(gui->window, tmp2->ant, NULL);
	      tmp2 = tmp2->next;
	    }
	}
      tmp1 = tmp1->next;
    }
  free(tmp1);
}

void		draw_tunnels(t_lemin *lemin, t_gui *gui)
{
  int		i;
  char		**tmp;
  sfVector2f	pos1;
  sfVector2f	pos2;

  i = 0;
  while (lemin->tunnels[i] != NULL)
    {
      tmp = seperate_rooms(lemin->tunnels[i]);
      pos1 = get_room_coord(lemin->list->head, tmp[0]);
      pos2 = get_room_coord(lemin->list->head, tmp[1]);
      draw_tunnel(gui, pos1, pos2);
      free_tab(tmp);
      i += 1;
    }
}
