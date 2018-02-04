/*
** Pop_item.c for kd in /home/cherkaoui/Bureau/Core war
** 
** Made by Cherkaoui
** Login   <abderrahim.cherkaoui@epitech.eu>
** 
** Started on  Thu Mar 30 04:47:53 2017 Cherkaoui
** Last update Sun Apr  2 18:21:37 2017 Cherkaoui
*/

#include "../graph.h"
#include "../vm.h"

void		print_life(t_my_framebuffer *fb , int player, int point, int max)
{
  t_my_square	life;
  sfColor	colorlife;

  life.x0 = 1024;
  life.x1 =  1024 + (int)((float)(185 / (float)(max)) * (float)(point));
  life.y0 = 274 + (72 * (player - 1));
  life.y1 = 290 + (72 * (player - 1));
  if (life.x1 < 1024 + 185)
    {
      colorlife.r = 102;
      colorlife.g = 255;
      colorlife.b = 51;
      colorlife.a = 200;
      draw_sq(fb, life, colorlife);
    }
  else
    draw_sq(fb, life, sfRed);
}

void	set_pos(int i, int x, int *y, t_my_square *pos)
{
  x = (i % 98) * 9;
  if (x == 0)
    *y = *y + 9;
  pos->x0 = 55 + x;
  pos->y0 = 97 + *y;
  pos->x1 = 55 + x + 5;
  pos->y1 = 97 + *y + 5;
}

t_my_core	print_all_champ(t_my_core cr)
{
  int		i;
  int		x;
  int		y;
  t_my_square	pos;

  i = -1;
  y = 0;
  while (++i != MEM_SIZE)
    {
      set_pos(i, x, &y, &pos);
      if (map[i] == '4')
	draw_sq(cr.framebuffer, pos, sfBlack);
      else if (map[i] == '0')
	draw_sq(cr.framebuffer, pos, sfBlue);
      else if (map[i] == '1')
	draw_sq(cr.framebuffer, pos, sfMagenta);
      else if (map[i] == '2')
	draw_sq(cr.framebuffer, pos, sfRed);
      else if (map[i] == '3')
	draw_sq(cr.framebuffer, pos, sfGreen);
      else if (map[i] == '5')
	draw_r(cr.framebuffer, pos, sfWhite, i % 2 + 1);
    }
  return (cr);
}

t_my_core	print_scores(t_my_core cr)
{
  int	max;

  max = cr.max;
  print_life(cr.framebuffer, 1, cr.life1, max);
  print_life(cr.framebuffer, 2, cr.life2, max);
  print_life(cr.framebuffer, 3, cr.life3, max);
  print_life(cr.framebuffer, 4, cr.life4, max);
  return (cr);
}

t_my_core	print_game(t_my_core cr)
{
  my_clear(cr.framebuffer);
  while (sfRenderWindow_pollEvent(cr.window, &cr.event))
    {
      if (cr.event.type == sfEvtKeyPressed)
	if (cr.event.key.code == sfKeyEscape)
	  cr.fase = 0;
    }
  sfRenderWindow_drawSprite(cr.window, cr.first, NULL);
  sfText_setString(cr.text, int_to_str(cr.cycle));
  sfText_setString(cr.ctdie, int_to_str(cr.ictdie));
  sfText_setString(cr.process, int_to_str(cr.iprocess));
  sfText_setString(cr.stillalive, int_to_str(cr.istillalive));
  sfRenderWindow_drawText(cr.window, cr.text, NULL);
  sfRenderWindow_drawText(cr.window, cr.ctdie, NULL);
  sfRenderWindow_drawText(cr.window, cr.process, NULL);
  sfRenderWindow_drawText(cr.window, cr.stillalive, NULL);
  cr = print_all_champ(cr);
  cr = print_scores(cr);
  sfTexture_updateFromPixels(cr.texture, cr.pixels, cr.framebuffer->width,
			     cr.framebuffer->height, 0, 0);
  sfRenderWindow_drawSprite(cr.window, cr.sprite, NULL);
  return (cr);
}
