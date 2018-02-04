/*
** bootstrap.h for bootstrap in /home/leo/bswireframe
**
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
**
** Started on  Thu Nov 17 22:19:02 2016 leo lecherbonnier
** Last update Fri Mar 17 15:17:31 2017 Leo Lecherbonnier
*/

#ifndef _BOOTSTRAP_H_
# define _BOOTSTRAP_H_

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define M_PI 3.14159265358979323846

# include <SFML/Audio.h>
# include <SFML/Graphics.h>
# include <SFML/System/Export.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

typedef  struct s_my_framebuffer
{
  sfUint8* pixels;
  int       width;
  int       height;
}              t_my_framebuffer;

typedef struct s_player
{
  sfVector2i		from;
  sfVector2i		to;
  sfVector2f		pos;
  sfEvent       event;
  sfVideoMode 	mode;
  sfColor       nice;
  sfVector2i mapSize;
  float	direction;
	int	**map;
	int	lines;
	int	colums;
  sfVector2i screen_size;
  sfVector2i screen_pos;
  sfVector3f eye_pos;
  sfVector3f dir_vector;
  sfVector3f sphere;
  float radius;
  float	plane;
  float	d_plane;
  float	d_sphere;
}							t_player;

typedef struct s_sets
{
  sfRenderWindow*   wd;
  t_my_framebuffer* framebuffer;
  sfTexture*        txt;
  sfSprite*     sprite;
  sfEvent       event;
}								t_sets;

int	**my_retab(int **tab, char *str, int ligne, int colums);
char *fs_open_file(char* filepath, int *ligne, int *colums);
int	**my_reader(int **tab, char *path , int  *line, int *col);

t_my_framebuffer *load_screen(t_player *player, t_my_framebuffer *framebuffer);
void draw_sky(t_my_framebuffer *framebuffer);
void draw_floor(t_my_framebuffer *framebuffer);
t_my_framebuffer* my_framebuffer_create(int width, int height);
void my_put_pixel (t_my_framebuffer* framebuffer, int x, int y, sfColor color);
void my_draw_line(t_my_framebuffer* framebuffer, sfVector2i from,
		  sfVector2i to, sfColor color);
sfVector2f my_parallel_projection(sfVector3f pos3d, float angle);
sfVector2f my_isometric_projection(sfVector3f pos3d);
t_my_framebuffer* my_framebuffer_create(int width, int height);
sfUint8* create_pixel_buffer(void);
sfRenderWindow* create_window(char* name, int width, int height);
void my_clear(t_my_framebuffer *framebuffer);

sfVector2f move_forward(sfVector2f pos, float direction, float distance);
sfVector2f move_backward(sfVector2f pos, float direction, float distance);
float raycast(sfVector2f pos, float direction, int **map, sfVector2i mapsize);

t_sets init_buffer(t_player player);
void init_player(t_player *player, char *str);
void wolf(t_player player);

void parse_line(t_my_framebuffer* buffer, sfVector2i from,
		sfVector2i to, sfColor color);
void left(t_my_framebuffer* buffer, sfVector2i from,
	  sfVector2i to, sfColor color);
void right(t_my_framebuffer* buffer, sfVector2i from,
	   sfVector2i to, sfColor color);
void fix(t_my_framebuffer* buffer, sfVector2i from,
	 sfVector2i to, sfColor color);

t_player move(t_player player, t_my_framebuffer	*framebuffer);
void wall(t_player *player, t_my_framebuffer	*framebuffer);

void minimap(t_player player, t_my_framebuffer *framebuffer);
void draw_blocks(t_player player, t_my_framebuffer *framebuffer,
		    int x, int y);
void draw_blocks1(t_player player, t_my_framebuffer *framebuffer,
		     int x, int y);
void draw_blocks2(t_player player, t_my_framebuffer *framebuffer,
		     int x, int y);

void cross(t_player player, t_my_framebuffer	*framebuffer);
void draw_square(t_player player, t_my_framebuffer *framebuffer,
		    sfColor color);

float intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector);
sfVector3f get_normal_plane(int upward);

sfVector3f	calc_dir_vector(float dist_to_plane,
				sfVector2i screen_size, sfVector2i screen_pos);

float intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector,
		       float radius);
static	float	check_delta(double a, double b, double c);
sfVector3f get_normal_sphere(sfVector3f intersection_point);

t_player	*set_pixel(t_player *p, t_my_framebuffer *buffer,
			int colums, int ligne);
float intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector,
			 float radius);
sfVector3f get_normal_cylinder(sfVector3f intersection_point);
static	float	check_pos(float nb);
int	my_putchar(char	c);
int	my_putstr(char *str);
float intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector,
		     float semiangle);
sfVector3f rotate_zyx(sfVector3f to_rotate, sfVector3f angles);
sfVector3f rotate_xyz(sfVector3f to_rotate, sfVector3f angles);
static	sfVector3f	set_angle(sfVector3f angles);
static	sfVector3f	set_vector(double longeur, sfVector3f vector);
#endif /*_BOOTSTRAP_H_*/
