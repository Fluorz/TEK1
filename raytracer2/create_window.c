/*
** create_window.c for create_window.c in /home/pierre/work/c_graphical/wir
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.eu>
**
** Started on  Fri Nov 25 14:25:06 2016 Pierre Narcisi
** Last update Tue Jun  6 13:03:07 2017 Pierre Narcisi
*/

#include "my.h"

t_my_framebuffer	*my_frame_buffer_create(int width, int height)
{
  sfUint8		*pixels;
  int			i;
  t_my_framebuffer	*framebuffer;

  i = 0;
  if (!(framebuffer = malloc(sizeof(t_my_framebuffer))))
    return (NULL);
  if (!(pixels = malloc(width * height * 4 * sizeof(sfUint8) + 1)))
    return (NULL);
  while (i < width * height * 4)
    {
      pixels[i] = 0;
      i++;
    }
  framebuffer->width = width;
  framebuffer->height = height;
  framebuffer->pixels = pixels;
  return (framebuffer);
}

sfRenderWindow		*create_window()
{
  sfVideoMode		mode;
  sfRenderWindow	*window;

  mode.width  = WIDTH;
  mode.height = HEIGHT;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, "SFML window",
  sfResize | sfClose, NULL);
  if (window == NULL)
    return (NULL);
  return (window);
}

void disp2(sfTexture *texture, t_value *value, sfRenderWindow *window,
   sfSprite *sprite)
{
  sfTexture_updateFromPixels(texture, value->framebuffer->pixels,
    value->framebuffer->width, value->framebuffer->height, 0, 0);
  my_change_buffer(value);
  sfRenderWindow_clear(window, sfBlack);
  sfRenderWindow_drawSprite(window, sprite, NULL);
  sfRenderWindow_display(window);
}

void disp(t_my_framebuffer *framebuffer, sfRenderWindow *window, char **av)
{
  t_value	value;
  sfSprite	*sprite;
  sfTexture	*texture;
  sfEvent	event;

  value.framebuffer = framebuffer;
  value.objects = pars(av[1]);
  sprite = sfSprite_create();
  texture = sfTexture_create(framebuffer->width, framebuffer->height);
  sfSprite_setTexture(sprite, texture, sfTrue);
  while (sfRenderWindow_isOpen(window))
    {
      while (sfRenderWindow_pollEvent(window, &event))
	     {
	        if (event.type == sfEvtClosed)
	         sfRenderWindow_close(window);
	     }
      disp2(texture, &value, window, sprite);
      // while (1);
    }
  sfTexture_destroy(texture);
  sfSprite_destroy(sprite);
  sfRenderWindow_destroy(window);
}
