/*
** raytracer.h for raytracer1 in /home/monty/Documents/Rendu/raytracer/raytracer1/include/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Tue Mar 14 15:34:47 2017 Monty Criel
** Last update Jan May 28 20:54:28 2017
*/

#ifndef RAYTRACER_H_
#define RAYTRACER_H_

#include <SFML/Graphics.h>
#include "../include/frame_buffer.h"

#define WIDTH 600
#define HEIGHT 400

typedef struct    s_object
{
  struct s_object *next;
  struct s_object *prev;
  char            type;
  int             size;
  float           dist;
  float           **matrice;
  int             rota_x;
  int             rota_y;
  int             rota_z;
  sfVector3f      inter;
  sfVector3f      normal;
  sfVector3f      pos;
  sfVector3f      eye;
  sfColor         color;
}                 t_object;

typedef struct	s_scene
{
  t_object *object;
  t_object *closer;
  float coef;
  sfVector3f		light_pos;
}			t_scene;

typedef struct	s_vectors
{
  sfVector3f		light_vector;
}			t_vectors;

typedef struct	s_normal
{
  sfVector3f		sphere;
  sfVector3f		plane;
  sfVector3f		cylinder;
}			t_normal;

typedef struct	s_render
{
  t_gui		*gui;
  t_scene		scene;
  sfVector2i		size;
  int			distance;
  float		from;
  float		to;
}			t_render;

sfVector3f my_transformations(t_object *object, sfVector3f eye);
sfVector3f	translate(sfVector3f to_translate, sfVector3f translations);
sfVector3f	calc_dir_vector(float dist_to_plane, sfVector2i screen_size,
				sfVector2i screen_pos);
float		intersect_sphere(sfVector3f eye_pos, sfVector3f dir_vector,
				 float radius);
float		intersect_cylinder(sfVector3f eye_pos, sfVector3f dir_vector,
				   float radius);
float		intersect_plane(sfVector3f eye_pos, sfVector3f dir_vector);
float		calc_solution(float delta, float a, float b);
sfVector3f	get_normal_plane(int upward);
sfVector3f	get_normal_cylinder(sfVector3f intersection_point);
float		get_light_coef(sfVector3f light_vector,
			       sfVector3f normal_vector);
sfVector3f	get_normal_sphere(sfVector3f intersection_point);
sfVector3f	normalize_vector(sfVector3f vector, float normal);
void		init_normal(t_scene *scene, sfVector3f dir_vector);
void		init_var(sfVector3f *eye, sfVector2i *screen_pos);
void		init_light(t_vectors *vectors, t_scene *scene, t_normal *normal,
		   sfVector3f dir_vector);
void		init_scene(t_scene *scene, sfVector3f eye, sfVector3f dir_vector);
void		solo_shape(t_gui *gui, t_scene *scene, sfVector2i screen_pos);
void		multi_shape(t_gui *gui, t_scene *scene, sfVector2i screen_pos);
void		render_percent(sfVector2i screen_pos);
void		render_part(t_render args);

#endif
