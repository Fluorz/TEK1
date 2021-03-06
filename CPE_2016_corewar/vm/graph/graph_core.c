/*
** graph_navy.c for navy in /home/cherkaoui/Bureau/wolf3d/ONE-NAVY
** 
** Made by Cherkaoui
** Login   <abderrahim.cherkaoui@epitech.eu>
** 
** Started on  Wed Feb 15 19:42:15 2017 Cherkaoui
** Last update Sun Apr  2 18:13:00 2017 Cherkaoui
*/

#include "../graph.h"
#include "../vm.h"

sfRenderWindow		*create_window(char* name, int width, int height)
{
  sfRenderWindow*	window;
  sfVideoMode		mode;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
  if (window == NULL)
    exit (EXIT_FAILURE);
  return (window);
}

t_my_core	init_game(t_my_core nv)
{
  nv.window = create_window("CORE-WAR", 1280, 720);
  nv = init_music(nv);
  nv = init_sprites(nv);
  nv = init_framebuffer(nv);
  nv = init_textcycle(nv);
  nv.cycle = 0;
  nv.fase = 0;
  nv.start = 0;
  return (nv);
}
