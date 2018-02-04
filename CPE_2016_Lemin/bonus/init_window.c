/*
** init_².c for initialise window in /home/monty/Documents/Rendu/wolf3d/bswolf3d/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Sat Dec 24 12:04:00 2016 Monty Criel
** Last update Sun Apr 30 22:54:24 2017 Monty Criel
*/

#include <SFML/Graphics.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include "lemin.h"

t_my_framebuffer*	my_frame_buffer_create(int width, int height)
{
  t_my_framebuffer*	framebuffer;

  framebuffer = malloc(sizeof(t_my_framebuffer));
  if (!framebuffer)
    return (NULL);
  framebuffer->pixels = malloc(sizeof(sfUint8) * width * height * 4);
  if (!framebuffer->pixels)
    {
      free(framebuffer);
      return NULL;
    }
  framebuffer->width = width;
  framebuffer->height = height;
  return (framebuffer);
}

sfRenderWindow		*create_window(char *name, int width, int height)
{
  sfRenderWindow	*window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  return (window);
}

sfSprite		*create_sprite()
{
  sfSprite		*sprite;

  sprite = sfSprite_create();
  if (sprite == NULL)
    return (NULL);
  return (sprite);
}

sfTexture		*create_texture(int width, int height)
{
  sfTexture		*texture;

  texture = sfTexture_create(width, height);
  if (texture == NULL)
    return (NULL);
  return (texture);
}

int		window_loop(t_args *args)
{
  while (sfRenderWindow_isOpen(args->gui->window))
    {
      if (exit_event(args->gui, args->lemin) == 1)
	pthread_exit(NULL);
      camera_event(args->gui);
      sfRenderWindow_clear(args->gui->window, sfBlack);
      sfRenderWindow_setView(args->gui->window, args->gui->view);
      sfRenderWindow_drawSprite(args->gui->window,
             args->gui->bg_sprite, NULL);
      sfRenderWindow_drawSprite(args->gui->window, args->gui->sprite, NULL);
      draw_tunnels(args->lemin, args->gui);
      sfTexture_updateFromPixels(args->gui->texture,
				 args->gui->fb->pixels, args->gui->fb->width,
				 args->gui->fb->height, 0, 0);
      draw_rooms(args->lemin, args->gui);
      draw_ants(args->lemin, args->gui);
      sfRenderWindow_display(args->gui->window);
    }
}
