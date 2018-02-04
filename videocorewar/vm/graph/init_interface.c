/*
** init_interface.c for init in /home/cherkaoui/Bureau/Core war
** 
** Made by Cherkaoui
** Login   <abderrahim.cherkaoui@epitech.eu>
** 
** Started on  Thu Mar 30 06:19:40 2017 Cherkaoui
** Last update Thu Apr 20 16:15:29 2017 abdel cherkaoui
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


  nv.cours2 = sfSprite_create();
  nv.texture6 = sfTexture_createFromFile("Sprite/cours2.png", NULL);
  sfSprite_setTexture(nv.cours2, nv.texture6, sfTrue);
  sfVector2f scales;
  scales.x = 1.5;
  scales.y = 1.5;
  sfSprite_setScale(nv.cours2, scales);
  nv.select = sfSprite_create();
  nv.texture7 = sfTexture_createFromFile("Sprite/select.png", NULL);
  sfSprite_setTexture(nv.select, nv.texture7, sfTrue);
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

  nv.ch1 = sfText_create();
  nv.ch2 = sfText_create();
  nv.ch3 = sfText_create();
  nv.ch4 = sfText_create();

  sfText_setString(nv.ch1, "null");
  sfText_setString(nv.ch2, "null");
  sfText_setString(nv.ch3, "null");
  sfText_setString(nv.ch4, "null");
  
  sfText_setFont(nv.ch1, nv.font);
  sfText_setFont(nv.ch2, nv.font);
  sfText_setFont(nv.ch3, nv.font);
  sfText_setFont(nv.ch4, nv.font);

  sfText_setCharacterSize(nv.ch1, 30);
  sfText_setCharacterSize(nv.ch2, 30);
  sfText_setCharacterSize(nv.ch3, 30);
  sfText_setCharacterSize(nv.ch4, 30);

  int dist = 58;

  
  nv.position.x = 944;
  nv.position.y = 289 + dist * 0;
  sfText_setPosition(nv.ch1, nv.position);
  nv.position.y = 289 + dist * 1;
  sfText_setPosition(nv.ch2, nv.position);
  nv.position.y = 289 + dist * 2;
  sfText_setPosition(nv.ch3, nv.position);
  nv.position.y = 289 + dist * 3;
  sfText_setPosition(nv.ch4, nv.position);

  nv.position.y = 32;
  nv.position.x = 829;
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
