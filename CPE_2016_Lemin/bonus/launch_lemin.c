/*
** launch_lemin.c for lemin in /home/monty/Documents/Rendu/lemin/CPE_2016_Lemin/bonus/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sun Apr 30 14:19:01 2017 Monty Criel
** Last update Jan Apr 30 23:33:00 2017
*/

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include "lemin.h"
#include "my.h"

void	move_ant_sprite(t_ant *ant, sfVector2f to)
{
  float	run;
  float	rise;
  float	steps;
  int 		i;

  if (abs((float)to.x - (float)ant->pos.x) >= abs((float)to.y -
	  (float)ant->pos.y))
    steps = abs((float)to.x - (float)ant->pos.x);
  else
    steps = abs((float)to.y - (float)ant->pos.y);
  run = ((float)to.x - (float)ant->pos.x) / steps;
  rise = ((float)to.y - (float)ant->pos.y) / steps;
  i = 0;
  while (i <= steps)
    {
      ant->pos.x += run;
      ant->pos.y += rise;
      sfSprite_setPosition(ant->ant, ant->pos);
      i = i + 1;
      usleep(10000);
    }
}

void		move_ant(t_lemin *lemin, int number, char *name, sfVector2f pos)
{
  t_room	*tmp;
  t_ant	*ant;

  ant = lemin->list->head->ant_list->head;
  tmp = lemin->list->head;
  while (ant->number != number)
    ant = ant->next;
  while (my_strcmp(tmp->name, name))
    tmp = tmp->next;
  move_ant_sprite(ant, pos);
}

int		launch_lemin(t_lemin *lemin)
{
  int		i;
  int		x;
  sfVector2f	pos;
  int		number;
  char		*room_name;
  char		**tmp;

  i = 0;
  while (lemin->moves[i] != NULL)
    {
      tmp = my_str_to_wordtab(lemin->moves[i], ' ');
      x = 0;
      while (tmp[x] != NULL)
	{
	  number = get_ant_number(tmp[x]);
	  room_name = get_room_name(tmp[x]);
	  pos = get_room_coord(lemin->list->head, room_name);
	  move_ant(lemin, number, room_name, pos);
	  x += 1;
	}
      i += 1;
    }
  return (0);
}
