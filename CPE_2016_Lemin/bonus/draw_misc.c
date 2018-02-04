/*
** draw_misc.c for lemin in /home/monty/Documents/Rendu/lemin/CPE_2016_Lemin/bonus/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sun Apr 30 15:28:01 2017 Monty Criel
** Last update Sun Apr 30 18:27:42 2017 Monty Criel
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

char	*seperate_room_2(char **tab, char *str)
{
  int	i;
  int	tmp;
  char	*name;

  i = 0;
  tmp = 0;
  while (str[i++] != '-');
  tmp = i;
  while (str[i++] != '\0');
  if ((name = malloc(sizeof(char) * (i - tmp + 1))) == NULL)
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

char	**seperate_rooms(char *str)
{
  char	**tab;
  int	i;

  if ((tab = malloc(sizeof(char *) * 3)) == NULL)
    return (NULL);
  i = 0;
  tab[2] = NULL;
  while (str[i++] != '-');
  if ((tab[0] = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '-')
    {
      tab[0][i] = str[i];
      i += 1;
    }
  tab[0][i] = '\0';
  tab[1] = seperate_room_2(tab, str);
  return (tab);
}

sfVector2f	get_room_coord(t_room *room, char *name)
{
  sfVector2f	pos;
  t_room	*tmp;

  tmp = room;
  while (my_strcmp(tmp->name, name) != 0)
    tmp = tmp->next;
  pos.x = tmp->coord.x;
  pos.y = tmp->coord.y;
  return  (pos);
}

void		draw_tunnel(t_gui *gui, sfVector2f pos1, sfVector2f pos2)
{
  sfVector2i	p1;
  sfVector2i	p2;

  p1.x = (int)pos1.x;
  p1.y = (int)pos1.y;
  p2.x = (int)pos2.x;
  p2.y = (int)pos2.y;
  my_draw_line(gui->fb, p1, p2, sfYellow);
}
