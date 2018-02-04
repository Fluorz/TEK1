/*
** my.h for bs in /home/byliarus/work/Graph/bsraytracer1/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Feb 13 13:32:58 2017 John Doe
** Last update Tue Jun  6 13:07:01 2017 Pierre Narcisi
*/

#ifndef _MY_H
# define _MY_H

#include <stdlib.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/System/Vector2.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <unistd.h>
#include <SFML/Graphics/Image.h>

#define HEIGHT 1024
#define WIDTH 1024

typedef struct      s_my_framenuffer
{
  sfUint8*          pixels;
  int               width;
  int               height;
}                   t_my_framebuffer;

typedef struct      s_object
{
  char type;
  int bol;
  int size;
  float k;
  float **matrice;
  sfVector3f inter;
  sfVector3f normal;
  sfVector3f pos;
  sfVector3f eye;
  sfColor color;
}                   t_object;

typedef struct      s_value
{
  t_my_framebuffer  *framebuffer;
  t_object *objects;
}                   t_value;

void op_cylinder(t_value *value, sfVector3f ray, int i);
void op_sphere(t_value *value, sfVector3f ray, int i);
sfColor my_color(char c);
void normalize(sfVector3f *vec);
void init_eye(t_value *value);
void k_value(t_value *value, sfVector2i pos, sfVector3f ray);
sfColor selecte_col(t_value *value, sfVector2f size, sfVector2i pos);
void print_mat(float **mat);
sfVector3f my_mult_vect_mat(sfVector3f eye, float **inv);
sfColor my_light(t_object object, sfVector2f size, sfVector2i pos, sfVector3f light);
sfVector3f get_normal_sphere(sfVector3f intersection_point, sfVector3f pos);
sfVector3f get_normal_cylinder(sfVector3f intersection_point, sfVector3f pos);
sfVector3f get_normal_plane(int upward);
void div_coef(float **inv, float **matrice, int size);
sfVector3f my_transformations(t_object *object, sfVector3f eye);
void pivot(float **matrice, float **inv, int size);
t_object *pars(char *file);
float calc(float a, float b, float c);
void my_change_buffer(t_value *value);
t_my_framebuffer	*my_frame_buffer_create(int width, int height);
sfRenderWindow		*create_window();
void disp(t_my_framebuffer *framebuffer, sfRenderWindow *window, char **av);
float intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector, float radius);
float intersect_cone(sfVector3f eye_pos, sfVector3f dir_vector, float radius);
float intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector, float radius);
sfVector3f calc_dir_vector(sfVector2i pos);
void	my_put_pixel(t_my_framebuffer *framebuffer, int x, int y, sfColor color);
float intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector);
char *get_next_line(int fd);
int my_atoi(char *str);

#endif
