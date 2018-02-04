/*
** joystick.c for wolf3d in /home/monty/Documents/Rendu/wolf3d/wolf3d/bonus/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Fri Jan 13 11:10:57 2017 Monty Criel
** Last update Sun Jun  4 20:41:01 2017 Monty Criel
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "frame_buffer.h"

void	joystick_rotate(t_player *player, t_joystick joystick)
{
  if (joystick.joy2.x < -20.0)
    player->view = player->view - 3.5;
  if (joystick.joy2.x > 20.0)
    player->view = player->view + 3.5;
  if (joystick.joy2.y < -20.0)
    {
      player->view_wall = player->view_wall + 30.0;
      player->view_sky = player->view_sky - 30.0;
    }
  if (joystick.joy2.y > 20.0)
    {
      player->view_wall = player->view_wall - 30.0;
      player->view_floor = player->view_floor - 30.0;
    }
  if (sfJoystick_isButtonPressed(0, 5) == sfTrue)
    respawn(player);
  if (sfJoystick_isButtonPressed(0, 4) == sfTrue)
    player->minimap = 1;
  else
    player->minimap = 0;
}

void		move_strafe(t_player *plyr, int **map, sfVector2i mS,
			    t_joystick joy)
{
  sfVector2i	p;

  p.x = (int)plyr->pos.x;
  p.y = (int)plyr->pos.y;
  if (joy.joy1.x < -20.0)
    {
      if (map[p.x - 1][p.y] != 1 &&
	  raycast(plyr->pos, plyr->view - 45.0, map, mS) >= 0.2)
	plyr->pos = move_forward(plyr->pos, plyr->view - 90.0, plyr->speed);
      if (map[(int)plyr->pos.x][(int)plyr->pos.y] == 1)
	plyr->pos = move_forward(plyr->pos, plyr->view + 90.0, 1.0);
    }
  if (joy.joy1.x > 20.0)
    {
      if (map[p.x + 1][p.y] != 1 &&
	  raycast(plyr->pos, plyr->view + 45.0, map, mS) >= 0.2)
	plyr->pos = move_forward(plyr->pos, plyr->view + 90.0, plyr->speed);
      if (map[(int)plyr->pos.x][(int)plyr->pos.y] == 1)
	plyr->pos = move_forward(plyr->pos, plyr->view - 90.0, 1.0);
    }
}

void		move_player(t_player *plyr, int **map, sfVector2i mS,
			    t_joystick joy)
{
  sfVector2i 	p;

  p.x = (int)plyr->pos.x;
  p.y = (int)plyr->pos.y;
  if (joy.joy1.y < -20.0)
    {
      if (map[p.x][p.y - 1] != 1 &&
	  raycast(plyr->pos, plyr->view, map, mS) >= 0.2)
	plyr->pos = move_forward(plyr->pos, plyr->view, plyr->speed);
      if (map[(int)plyr->pos.x][(int)plyr->pos.y] == 1)
	plyr->pos = move_forward(plyr->pos, plyr->view, -1.0);
    }
  if (joy.joy1.y > 20.0)
    {
      if (map[p.x][p.y + 1] != 1 &&
	  raycast(plyr->pos, plyr->view - 90.0, map, mS) >= 0.2)
	plyr->pos = move_forward(plyr->pos, plyr->view, -plyr->speed);
      if (map[(int)plyr->pos.x][(int)plyr->pos.y] == 1)
	plyr->pos = move_forward(plyr->pos, plyr->view, 1.0);
    }
  move_strafe(plyr, map, mS, joy);
  joystick_rotate(plyr, joy);
}

int	check_joystick()
{
  if (sfJoystick_isConnected(0) == sfTrue)
    return (1);
  else
    return (0);
}

void		player_joystick(t_gui *gui, t_player *player,
				int **map, sfVector2i mS)
{
  t_joystick	joystick;

  if (check_joystick() == 1)
    {
      joystick.joy1.x = sfJoystick_getAxisPosition(0, sfJoystickX);
      joystick.joy1.y = sfJoystick_getAxisPosition(0, sfJoystickY);
      joystick.joy2.x = sfJoystick_getAxisPosition(0, sfJoystickU);
      joystick.joy2.y = sfJoystick_getAxisPosition(0, sfJoystickV);
      joystick.rt_button = sfJoystick_getAxisPosition(0, sfJoystickR);
      move_player(player, map, mS, joystick);
      if (joystick.rt_button > -100.0 || joystick.rt_button > 100.0)
	raygun_animation(gui, player);
    }
  else
    return;
}
