/*
** lemin.h for lemin in /home/monty/Documents/Rendu/lemin/CPE_2016_Lemin/bonus/include/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Mon Apr 24 09:47:49 2017 Monty Criel
** Last update Sun Apr 30 23:09:23 2017 Monty Criel
*/

#ifndef LEMIN_H

#include <SFML/Graphics.h>

#define WIDTH 1200
#define HEIGHT 600

typedef struct	s_ant
{
  int			number;
  sfVector2f		pos;
  sfSprite		*ant;
  struct s_ant	*next;
}			t_ant;

typedef struct	s_ant_list
{
  t_ant		*head;
}			t_ant_list;

typedef struct	s_room
{
  char			*name;
  char			*type;
  int			total;
  sfVector2i		pos;
  sfVector2f		coord;
  sfSprite		*room;
  sfText		*text;
  sfFont		*font;
  t_ant_list		*ant_list;
  struct s_room	*next;
}			t_room;

typedef struct	s_list
{
  t_room		*head;
}			t_list;

typedef struct	s_lemin
{
  int			ants;
  int			total;
  char			**tunnels;
  char			**moves;
  sfSprite		*tube;
  sfTexture		*tube_texture;
  t_list		*list;
}			t_lemin;

typedef struct	s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

typedef struct	s_gui
{
  sfRenderWindow	*window;
  sfSprite		*sprite;
  sfTexture		*texture;
  sfSprite		*bg_sprite;
  sfTexture		*bg_texture;
  sfVector2f		pos;
  sfTexture		*room_texture;
  sfTexture		*ant_texture;
  sfView		*view;
  t_my_framebuffer	*fb;
}			t_gui;

typedef struct	s_args
{
  t_lemin		*lemin;
  t_gui		*gui;
}			t_args;

char	**tab_append_tail(char **tab, char *str);
char	**get_data(char *file_name);
void	print_tab(char **tab);
void	free_tab(char **tab);
char	**wordtab(char *str);
char	*copy_line(char *line);
char	**get_rooms(char **tab);
sfRenderWindow	*create_window(char *name, int width, int height);
void	my_put_pixel(t_my_framebuffer *framebuffer, int x,
		     int y, sfColor color);
void	my_draw_line(t_my_framebuffer *framebuffer, sfVector2i from,
		     sfVector2i to, sfColor color);
t_my_framebuffer*	my_frame_buffer_create(int width, int height);
sfSprite		*create_sprite();
sfTexture		*create_texture(int width, int height);
char			**get_tunnels(char **tab);
char			**get_moves(char **tab);
t_list			*create_list(t_list *list, char **tab);
int			window_loop(t_args *args);
int			exit_event(t_gui *gui, t_lemin *lemin);
char			*get_type(int *i);
void			load_lemin(t_lemin *lemin, t_gui *gui);
void			draw_rooms(t_lemin *lemin, t_gui *gui);
void			draw_tunnels(t_lemin *lemin, t_gui *gui);
t_ant			*create_ant(t_gui *gui, sfVector2f pos, int nb);
void			append_ant(t_ant_list *list, t_ant *ant);
void			draw_ants(t_lemin *lemin, t_gui *gui);
void			init_ant_list(t_lemin *lemin, t_gui *gui);
char			**seperate_rooms(char *str);
sfVector2f		get_room_coord(t_room *room, char *name);
void			draw_tunnel(t_gui *gui, sfVector2f pos1,
				    sfVector2f pos2);
int			launch_lemin(t_lemin *lemin);
void			view_event(t_gui *gui);
int			get_ant_number(char *str);
char			*get_room_name(char *str);
void			camera_event(t_gui *gui);

#endif /*LEMIN_H*/
