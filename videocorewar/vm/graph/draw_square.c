/*
** draw_square.c for draw square in /home/abdel/bswolf3d/minimap
** 
** Made by Abderrahim CHERKAOUI
** Login   <abdel@epitech.net>
** 
** Started on  Sat Dec 24 23:06:46 2016 Abderrahim CHERKAOUI
** Last update Sun Apr  2 18:20:55 2017 Cherkaoui
*/

#include "../graph.h"

void	draw_ro(t_my_framebuffer *fb, t_my_square pos, sfColor color)
{
  int	x;
  int	y;
  int	r;
  float	PI;
  float	i;

  r = 5;
  PI = 3.15;
  i = 0;
  while (i < 360)
    {
      x = pos.x0 + (int)(r * cos(i * PI / 180));
      y = pos.y0 + (int)(r * sin(i * PI / 180));
      fb->pixels[(fb->width * y + x) * 4] = color.r;
      fb->pixels[(fb->width * y + x) * 4 + 1] = color.g;
      fb->pixels[(fb->width * y + x) * 4 + 2] = color.b;
      fb->pixels[(fb->width * y + x) * 4 + 3] = color.a;
      i += 0.1;
    }
}

void	my_put_pixel(int x, int y, t_my_framebuffer *fb, sfColor color)
{
  fb->pixels[(fb->width * y + x) * 4] = color.r;
  fb->pixels[(fb->width * y + x) * 4 + 1] = color.g;
  fb->pixels[(fb->width * y + x) * 4 + 2] = color.b;
  fb->pixels[(fb->width * y + x) * 4 + 3] = color.a;
}

t_circle	init_val_circle(t_circle c, t_my_square pos, int i)
{
  if (i == 1)
    {
      c.x0 = pos.x0;
      c.y0 = pos.y0;
      c.x =  2 + c.b;
      c.y = -1;
      c.xC = 1 - (5 << 1);
      c.yC = 0;
      c.rE = 0;
      c.i = 0;
    }
  else if (i == 2)
    {
      c.rE += c.yC;
      c.yC += 2;
      if (((c.rE << 1) + c.xC) > 0)
	{
	  c.x--;
	  c.rE += c.xC;
	  c.xC += 2;
	}
    }
  return (c);
}

void		draw_r(t_my_framebuffer *fb, t_my_square pos,
		       sfColor color, int bool)
{
  t_circle	c;

  if (bool == 2)
    color = sfRed;
  c.b = bool;
  c = init_val_circle(c, pos, 1);
  while (c.x >= ++c.y)
    {
      c.i = c.x0 - c.x - 1;
      while (++c.i <= c.x0 + c.x)
	{
	  my_put_pixel(c.i, c.y0 + c.y, fb, color);
	  my_put_pixel(c.i, c.y0 - c.y, fb, color);
	}
      c.i = c.x0 - c.y - 1;
      while (++c.i <= c.x0 + c.y)
	{
	  my_put_pixel(c.i, c.y0 + c.x, fb, color);
	  my_put_pixel(c.i, c.y0 - c.x, fb, color);
	}
      c = init_val_circle(c, pos, 2);
    }
}

void	draw_sq(t_my_framebuffer *fb, t_my_square pos, sfColor color)
{
  int	x;
  int	y;
  int	stock;

  stock = pos.y0;
  while (pos.x0 < pos.x1)
    {
      pos.y0 = stock;
      while (pos.y0 < pos.y1)
	{
	  x = pos.x0;
	  y = pos.y0;
	  fb->pixels[(fb->width * y + x) * 4] = color.r;
	  fb->pixels[(fb->width * y + x) * 4 + 1] = color.g;
	  fb->pixels[(fb->width * y + x) * 4 + 2] = color.b;
	  fb->pixels[(fb->width * y + x) * 4 + 3] = color.a;
	  pos.y0 = pos.y0 + 1;
	}
      pos.x0 = pos.x0 + 1;
    }
}
