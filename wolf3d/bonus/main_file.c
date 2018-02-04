/*
** main_file.c for header in /home/leo/bswireframe
**
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
**
** Started on  Thu Nov 17 17:32:06 2016 leo lecherbonnier
** Last update Wed Mar  8 10:25:09 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

void	init_player(t_player *player, char *str)
{
  player->from.x = 0;
  player->from.y = 0;
  player->to.x = 0;
  player->to.y = 0;
  player->pos.x = 2;
  player->pos.y = 2;
  player->direction = 4;
  player->lines = 0;
  player->colums = 0;
  player->mode.width = 1280;
  player->mode.height = 720;
  player->mode.bitsPerPixel = 32;
  player->mapSize.x = 1280;
  player->mapSize.y = 720;
  player->map = my_reader(player->map, str, &player->lines, &player->colums);
  player->nice.r = 255;
  player->nice.g = 40;
  player->nice.b = 40;
  player->nice.a = 255;
}

void	wolf(t_player player)
{
  sfRenderWindow*   wd;
  t_my_framebuffer* framebuffer;
  sfTexture*        txt;
  sfSprite*     sprite;
  sfEvent       event;

  framebuffer = my_framebuffer_create(1280, 720);
  wd = sfRenderWindow_create(player.mode, "WOLF", sfResize | sfClose, NULL);
  sprite = sfSprite_create();
  txt = sfTexture_create(1280 , 720);
  sfSprite_setTexture(sprite, txt, sfTrue);
  while (sfRenderWindow_isOpen(wd))
    while (sfRenderWindow_pollEvent(wd, &event))
	{
	  sfRenderWindow_clear(wd, sfWhite);
	  sfRenderWindow_drawSprite(wd, sprite, NULL);
	  sfRenderWindow_display(wd);
	  player = move(player, framebuffer);
	  draw_sky(framebuffer);
	  draw_floor(framebuffer);
	  wall(&player, framebuffer);
	  minimap(player, framebuffer);
	  sfTexture_updateFromPixels(txt, framebuffer->pixels, 1280, 720, 0, 0);
	}
}

int	main(int ac, char **av)
{
  t_player	player;

  if (ac < 2)
    exit(0);
  init_player(&player, av[1]);
  wolf(player);
}
