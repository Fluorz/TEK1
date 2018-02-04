/*
** extra.c for lemin in /home/monty/Documents/Rendu/lemin/CPE_2016_Lemin/bonus/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sun Apr 30 22:30:43 2017 Monty Criel
** Last update Sun Apr 30 23:14:00 2017 Monty Criel
*/

#include "lemin.h"

void	camera_event2(t_gui *gui, sfVector2f pos)
{
  sfView_move(gui->view, pos);
  sfSprite_setPosition(gui->bg_sprite, gui->pos);
}

void		camera_event(t_gui *gui)
{
  sfVector2f	pos;

  pos.x = 0;
  pos.y = 0;
  if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
    {
      gui->pos.y -= 10;
      pos.y -= 10;
    }
  if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
    {
      gui->pos.y += 10;
      pos.y += 10;
    }
  if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
    {
      gui->pos.x -= 10;
      pos.x -= 10;
    }
  if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
    {
      gui->pos.x += 10;
      pos.x += 10;
    }
  camera_event2(gui, pos);
}
