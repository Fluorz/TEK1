/*
** init_interface.c for init in /home/cherkaoui/Bureau/Core war
** 
** Made by Cherkaoui
** Login   <abderrahim.cherkaoui@epitech.eu>
** 
** Started on  Thu Mar 30 06:19:40 2017 Cherkaoui
** Last update Sun Apr  2 01:19:30 2017 Cherkaoui
*/

#include "../graph.h"

t_my_core	init_sprites(t_my_core nv)
{
  nv.first = sfSprite_create();
  nv.texture1 = sfTexture_createFromFile("Sprite/first.png", NULL);
  sfSprite_setTexture(nv.first, nv.texture1, sfTrue);
  nv.menu = sfSprite_create();
  nv.texture2 = sfTexture_createFromFile("Sprite/menu.png", NULL);
  sfSprite_setTexture(nv.menu, nv.texture2, sfTrue);
  nv.cours = sfSprite_create();
  nv.texture3 = sfTexture_createFromFile("Sprite/cours.png", NULL);
  sfSprite_setTexture(nv.cours, nv.texture3, sfTrue);
  nv.credit = sfSprite_create();
  nv.texture4 = sfTexture_createFromFile("Sprite/credit.png", NULL);
  sfSprite_setTexture(nv.credit, nv.texture4, sfTrue);
  nv.converter = sfSprite_create();
  nv.texture5 = sfTexture_createFromFile("Sprite/converter.png", NULL);
  sfSprite_setTexture(nv.converter, nv.texture5, sfTrue);
  return (nv);
}

t_my_core	init_music(t_my_core nv)
{
  nv.music = sfMusic_createFromFile("sound/musica.ogg");
  nv.shot = sfMusic_createFromFile("sound/shot.ogg");
  sfMusic_play(nv.music);
  return (nv);
}

t_my_core	init_framebuffer(t_my_core nv)
{
  nv.framebuffer = my_framebuffer_create(1280, 720);
  nv.sprite = sfSprite_create();
  nv.texture = sfTexture_create(nv.framebuffer->width, nv.framebuffer->height);
  sfSprite_setTexture(nv.sprite, nv.texture, sfTrue);
  nv.pixels = nv.framebuffer->pixels;
  return (nv);
}

t_my_core	init_textcycle(t_my_core nv)
{
  nv.position.y = 32;
  nv.position.x = 829;
  nv.font = sfFont_createFromFile("fontbase.ttf"); // TEXT
  nv.text = sfText_create();
  nv.ctdie = sfText_create();
  nv.process = sfText_create();
  nv.stillalive = sfText_create();
  sfText_setString(nv.text, "0");
  sfText_setFont(nv.text, nv.font);
  sfText_setFont(nv.ctdie, nv.font);
  sfText_setFont(nv.process, nv.font);
  sfText_setFont(nv.stillalive, nv.font);
  sfText_setCharacterSize(nv.text, 30); //SIZE
  sfText_setPosition(nv.text, nv.position); //POS
  sfText_setColor(nv.text, sfWhite);
  sfText_setPosition(nv.text, nv.position); //POS
  nv.position.x = 1167;
  nv.position.y = 31;
  sfText_setPosition(nv.ctdie, nv.position); //POS
  nv.position.y = 31 + 29;
  sfText_setPosition(nv.process, nv.position); //POS
  nv.position.y = 31 + 58;
  sfText_setPosition(nv.stillalive, nv.position); //POS
  return (nv);
}

void    my_clear(t_my_framebuffer *fb)
{
  int   i;

  i = -1;
  while (++i < fb->width * fb->height *4)
    fb->pixels[i] = 0;
}
