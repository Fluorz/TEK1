/*
** init_ants.c for lemin in /home/monty/Documents/Rendu/lemin/CPE_2016_Lemin/bonus/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sat Apr 29 16:54:54 2017 Monty Criel
** Last update Sun Apr 30 21:48:44 2017 Monty Criel
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

t_ant		*create_ant(t_gui *gui, sfVector2f pos, int nb)
{
  t_ant	*ant;
  sfVector2f	coord;

  ant = malloc(sizeof(t_ant));
  if (ant == NULL)
    return (NULL);
  ant->ant = create_sprite();
  sfSprite_setTexture(ant->ant, gui->ant_texture, sfTrue);
  coord.x = 98;
  coord.y = 83;
  sfSprite_setOrigin(ant->ant, coord);
  coord.x = 0.15;
  coord.y = 0.15;
  sfSprite_setScale(ant->ant, coord);
  sfSprite_setColor(ant->ant, sfRed);
  sfSprite_setPosition(ant->ant, pos);
  ant->number = nb;
  ant->pos = pos;
  ant->next = NULL;
  return (ant);
}

void		append_ant(t_ant_list *list, t_ant *ant)
{
  t_ant	*tmp;

  if (list->head == NULL)
    {
      list->head = ant;
      return;
    }
  tmp = list->head;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = ant;
  ant->next = NULL;
}

void		init_ant_list(t_lemin *lemin, t_gui *gui)
{
  t_room	*tmp;
  t_ant_list	*ant_list;

  tmp = lemin->list->head->next;
  while (tmp != NULL)
    {
      ant_list = malloc(sizeof(t_ant_list));
      ant_list->head = NULL;
      if (ant_list == NULL)
	return;
      tmp->ant_list = ant_list;
      tmp = tmp->next;
    }
}

int	get_ant_number(char *str)
{
  int	number;
  int	i;
  int	x;
  char	*new;

  i = 0;
  while (str[i] != '-')
    i += 1;
  new = malloc(sizeof(char) * i);
  if (new == NULL)
    return (-1);
  x = 0;
  i = 1;
  while (str[i] != '-')
    {
      new[x] = str[i];
      i += 1;
      x += 1;
    }
  new[x] = '\0';
  number = my_getnbr(new);
  return (number);
}

char	*get_room_name(char *str)
{
  char	*name;
  int	i;
  int	tmp;

  i = 0;
  tmp = 0;
  while (str[i] != '-')
    i += 1;
  i += 1;
  tmp = i;
  while (str[i] != '\0')
    i += 1;
  name = malloc(sizeof(char) * (i - tmp + 1));
  if (name == NULL)
    return (NULL);
  i = tmp;
  tmp = 0;
  while (str[i] != '\0')
    {
      name[tmp] = str[i];
      i += 1;
      tmp += 1;
    }
  name[tmp] = '\0';
  return (name);
}
