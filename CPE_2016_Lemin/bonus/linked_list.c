/*
** linked_list.c for lemin in /home/monty/Documents/Rendu/lemin/CPE_2016_Lemin/bonus/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sun Apr 30 17:25:19 2017 Monty Criel
** Last update Sun Apr 30 23:18:36 2017 Monty Criel
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "lemin.h"
#include "my.h"

t_room		*create_room()
{
  t_room	*room;

  room = malloc(sizeof(t_room));
  if (room == NULL)
    return (NULL);
  room->next = NULL;
  return (room);
}

void		append_tail(t_list *list, t_room *room)
{
  t_room	*tmp;

  if (list->head == NULL)
    {
      list->head = room;
      return;
    }
  tmp = list->head;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = room;
  room->next = NULL;
}

void		init_room(t_room *room, char **tab, char *type, int ants)
{
  room->name = copy_line(tab[0]);
  room->total = ants;
  room->type = copy_line(type);
  room->pos.x = my_getnbr(tab[1]);
  room->pos.y = my_getnbr(tab[2]);
  room->coord.x = room->pos.x * 40 + 40;
  room->coord.y = room->pos.y * 40 + 40;
  room->font = sfFont_createFromFile("./fonts/the_curious_incident.ttf");
  if (!room->font)
    return;
  room->text = sfText_create();
  sfText_setFont(room->text, room->font);
}

t_list		*create_list(t_list *list, char **tab)
{
  t_room	*room;
  char		**rooms;
  char		*type;
  char		**tmp;
  int		ants;
  int		i;

  if ((rooms = get_rooms(tab)) == NULL)
    return (NULL);
  i = 0;
  while (rooms[i] != NULL)
    {
      tmp = my_str_to_wordtab(rooms[i], ' ');
      room = create_room();
      type = get_type(&i);
      if (my_strcmp("start", type) == 0)
	ants = my_getnbr(tab[1]);
      else
	ants = 0;
      init_room(room, tmp, type, ants);
      append_tail(list, room);
      free_tab(tmp);
    }
  return (list);
}
