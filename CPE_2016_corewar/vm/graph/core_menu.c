/*
** core_menu.c for core menu in /home/cherkaoui/Bureau/Core war
** 
** Made by Cherkaoui
** Login   <abderrahim.cherkaoui@epitech.eu>
** 
** Started on  Thu Mar 30 07:47:29 2017 Cherkaoui
** Last update Sun Apr  2 01:48:24 2017 Cherkaoui
*/

#include "../graph.h"

void            print_effect(t_my_framebuffer *fb)
{
  t_my_square	pos;
  sfColor       colorch;
  int           i;

  i = 0;
  while (i != 10)
    {
      pos.x0 = 100 + (rand() % 550);
      pos.y0 = 300 + (rand() % 350);
      pos.x1 = pos.x0 + 10;
      pos.y1 = pos.y0 + 10;
      colorch.r = 204;
      colorch.g = 51;
      colorch.b = 204;
      colorch.a = 90;
      draw_sq(fb, pos, colorch);
      i++;
    }
}

t_my_core key_board_menu(t_my_core cr)
{
  if (cr.event.key.code == sfKeyUp)
    {
      sfMusic_play(cr.shot);
      if (cr.start == 0)
	cr.start = 58 * 4;
      else
	cr.start = cr.start - 58;
    }
  else if (cr.event.key.code == sfKeyReturn)
    {
      if (cr.start == 0)
	cr.fase = 1;
      else if (cr.start == 58)
	cr.fase = 2;
      else if (cr.start == 58 * 3)
	cr.fase = 4;
      else if (cr.start == (58 * 4))
	cr.fase = 5;
    }
  return (cr);
}

t_my_core       print_menu(t_my_core cr)
{
  int	start;

  my_clear(cr.framebuffer);
  while (sfRenderWindow_pollEvent(cr.window, &cr.event))
    {
      if (cr.event.type == sfEvtKeyPressed)
	{
	  if (cr.event.key.code == sfKeyDown)
	    if (cr.start == 58 * 4)
	      cr.start = 0;
	    else
	      cr.start = cr.start + 58;
	  else
	    cr = key_board_menu(cr);
	}
      sfMusic_play(cr.shot);
    }
  sfRenderWindow_drawSprite(cr.window, cr.menu, NULL);
  sfSprite_setPosition(cr.cours, (sfVector2f){899, 290 + cr.start});
  sfRenderWindow_drawSprite(cr.window, cr.cours, NULL);
  print_effect(cr.framebuffer);
  sfTexture_updateFromPixels(cr.texture, cr.pixels, cr.framebuffer->width,
			     cr.framebuffer->height, 0, 0);
  sfRenderWindow_drawSprite(cr.window, cr.sprite, NULL);
  return (cr);
}

t_my_core       print_converter(t_my_core cr)
{
  my_clear(cr.framebuffer);
  while (sfRenderWindow_pollEvent(cr.window, &cr.event))
    {
      if (cr.event.type == sfEvtKeyPressed)
	{
	  if (cr.event.key.code == sfKeyEscape)
	    {
	      cr.fase = 0;
	    }
	}
    }
  sfRenderWindow_drawSprite(cr.window, cr.converter, NULL);
  sfTexture_updateFromPixels(cr.texture, cr.pixels, cr.framebuffer->width,
			     cr.framebuffer->height, 0, 0);
  sfRenderWindow_drawSprite(cr.window, cr.sprite, NULL);
  return (cr);
}

t_my_core       print_credit(t_my_core cr)
{
  my_clear(cr.framebuffer);
  while (sfRenderWindow_pollEvent(cr.window, &cr.event))
    {
      if (cr.event.type == sfEvtKeyPressed)
	{
	  if (cr.event.key.code == sfKeyEscape)
	    {
	      cr.fase = 0;
	    }
	}
    }
  print_effect(cr.framebuffer);
  sfRenderWindow_drawSprite(cr.window, cr.credit, NULL);
  sfTexture_updateFromPixels(cr.texture, cr.pixels, cr.framebuffer->width,
			     cr.framebuffer->height, 0, 0);
  sfRenderWindow_drawSprite(cr.window, cr.sprite, NULL);
  return (cr);
}
