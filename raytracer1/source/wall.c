/*
** wall.c for wall.c in /home/lecherbonnier/wolf3d/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sun Jan  8 16:51:13 2017 Leo Lecherbonnier
** Last update Fri Mar 17 10:55:57 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

t_my_framebuffer *load_screen(t_player *p, t_my_framebuffer *buffer)
{
  float	distance_sphere;
  float	distance_plane;
  int	colums = 0;
  int	ligne = 0;
  int	i = 0;

  while (ligne != 720)
    {
      colums = 0;
      while (colums != 1280)
	{
	  p->dir_vector = calc_dir_vector(500.00, p->screen_size,
					  (sfVector2i){colums, ligne});
	      p->d_sphere = intersect_sphere(p->eye_pos, p->dir_vector, p->radius);
	  p->d_plane = intersect_plane(p->eye_pos, p->dir_vector);
	  p = set_pixel(p, buffer, colums, ligne);
	  colums++;
	}
      ligne++;
    }
  return (buffer);
}

t_player	*set_pixel(t_player *p, t_my_framebuffer *buffer,
			int colums, int ligne)
{
  if (p->d_plane == -1 && p->d_sphere != -1)
    my_put_pixel(buffer, colums, ligne, sfBlue);
  else if (p->d_sphere == -1 && p->d_plane != -1)
    my_put_pixel(buffer, colums, ligne, sfBlack);
  if (p->d_plane != -1 && p->d_plane < p->d_sphere)
    my_put_pixel(buffer, colums, ligne, sfBlue);
  else if (p->d_sphere != -1 && p->d_sphere < p->d_plane)
    my_put_pixel(buffer, colums, ligne, sfRed);
  return (p);
}
