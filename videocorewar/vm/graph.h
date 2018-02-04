/*
** my.h for one nay in /home/cherkaoui/Bureau/wolf3d/ONE-NAVY
** 
** Made by Cherkaoui
** Login   <abderrahim.cherkaoui@epitech.eu>
** 
** Started on  Wed Feb 15 19:48:17 2017 Cherkaoui
** Last update Thu Apr 20 16:45:55 2017 abdel cherkaoui
*/

#ifndef _MY_GRAPH__
#define _MY_GRAPH__

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/System/Export.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>


typedef struct	s_my_framebuffer
{
  sfUint8	*pixels;
  int		width;
  int		height;
}		t_my_framebuffer;

typedef struct	s_circle
{
  int x0;
  int y0;
  int x;
  int y;
  int xC;
  int yC;
  int rE;
  int i;
  int b;
}		t_circle;

typedef struct	s_my_square
{
  int	x0;
  int	x1;
  int	y0;
  int	y1;
}		t_my_square;

typedef struct          s_my_core
{
  sfRenderWindow*       window;
  sfTexture*            texture;
  sfTexture*            texture1;
  sfTexture*            texture2;
  sfTexture*            texture3;
  sfTexture*            texture4;
  sfTexture*            texture5;
  sfTexture*            texture6;
  sfTexture*            texture7;
  sfSprite*             sprite;
  sfSprite*             cours;
  sfSprite*             first;
  sfSprite*             menu;
  sfSprite*             credit;
  sfSprite*             converter;

  sfSprite*             cours2;
  sfSprite*             select;

  sfUint8*              pixels;
  t_my_framebuffer*     framebuffer;
  sfEvent               event;
  sfVector2f            pos;
  sfVector2i            cor;
  sfMusic*              music;
  sfMusic*              shot;
  sfColor               nice;
  sfText*		text;
  sfFont*		font;
  sfVector2f		position;
  int			cycle;
  int			fase;
  int			start;
  int			life1;
  int			life2;
  int			life3;
  int			life4;
  int			max;
  sfText*		ctdie;
  sfText*		process;
  sfText*		stillalive;

  sfText*		ch1;
  sfText*		ch2;
  sfText*		ch3;
  sfText*		ch4;

  char			*champ1;
  char			*champ2;
  char			*champ3;
  char			*champ4;

  char			*newav[5];
  int			ac;
  char			**listcor;
  char			**lists;
  char			**pathcor;
  int			nbcor;
  char			**paths;
  int			ictdie;
  int			iprocess;
  int			istillalive;
}			t_my_core;

t_my_core		fase(t_my_core cr);
char			*int_to_str(int nbr);
void			draw_sq(t_my_framebuffer *fb, t_my_square pos,
				sfColor color);
void			draw_r(t_my_framebuffer *fb, t_my_square pos,
			       sfColor color, int bool);
void			draw_wow(t_my_framebuffer *fb, t_my_square pos, sfColor color);
t_my_framebuffer*	 my_framebuffer_create(int width, int height);
void			print_life(t_my_framebuffer *fb , int player,
				   int point, int max);
t_my_core		print_game(t_my_core cr);
t_my_core		print_menu(t_my_core cr);
t_my_core		print_select(t_my_core cr);
void			my_clear(t_my_framebuffer *fb);
t_my_core		init_sprites(t_my_core nv);
t_my_core		init_music(t_my_core nv);
t_my_core		init_framebuffer(t_my_core nv);
t_my_core		init_textcycle(t_my_core nv);
void			my_clear(t_my_framebuffer *fb);
t_my_core		print_credit(t_my_core cr);
t_my_core		print_converter(t_my_core cr);
t_my_core		init_game(t_my_core nv);
t_my_core		give_files(t_my_core cr);
void			my_put_pixel(int x, int y,
				     t_my_framebuffer *fb, sfColor color);

#endif /*!MY_H*/
