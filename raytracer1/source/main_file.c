/*
** main_file.c for header in /home/leo/bswireframe
**
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
**
** Started on  Thu Nov 17 17:32:06 2016 leo lecherbonnier
** Last update Fri Mar 17 10:48:30 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

void	init_player(t_player *player, char *str)
{
  player->direction = 4;
  player->lines = 0;
  player->colums = 0;
  player->mode.width = 1280;
  player->mode.height = 720;
  player->mode.bitsPerPixel = 32;
  player->mapSize.x = 1280;
  player->mapSize.y = 720;
  player->nice.r = 255;
  player->nice.g = 40;
  player->nice.b = 40;
  player->nice.a = 255;
  player->screen_size.x = 1280;
  player->screen_size.y = 720;
  player->eye_pos.x = -200;
  player->eye_pos.y = 0;
  player->eye_pos.z = 0;
  player->sphere = (sfVector3f){0, 0, 0};
  player->radius = 50;
  player->plane = -25;
}

t_sets init_buffer(t_player player)
{
  t_sets	set;

  set.framebuffer = my_framebuffer_create(1280, 720);
  return (set);
}

t_sets		init_sets(t_player player)
{
  t_sets	set;

  set.wd = sfRenderWindow_create(player.mode, "RAYTRACER1",
				 sfResize | sfClose, NULL);
  set.sprite = sfSprite_create();
  set.txt = sfTexture_create(1280 , 720);
  return (set);
}

void	wolf(t_player player)
{
  t_sets set;

  set = init_sets(player);
  set = init_buffer(player);
  set.framebuffer = load_screen(&player, set.framebuffer);
  sfSprite_setTexture(set.sprite, set.txt, sfTrue);
  while (sfRenderWindow_isOpen(set.wd))
    while (sfRenderWindow_pollEvent(set.wd, &set.event))
	{
	  sfRenderWindow_clear(set.wd, sfWhite);
	  sfRenderWindow_drawSprite(set.wd, set.sprite, NULL);
	  sfRenderWindow_display(set.wd);
	  sfTexture_updateFromPixels(set.txt, set.framebuffer->pixels
				     , 1280, 720, 0, 0);
	}
}

int	main(int ac, char **av)
{
  t_player	player;

  if (ac > 1)
    {
      my_putstr("Bad numbers of argument\n");
      return (0);
    }
  init_player(&player, av[1]);
  wolf(player);
  return (0);
}
