/*
** my_change_buffer.c for my_change_buffer.c in
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.eu>
**
** Started on  Fri Nov 25 14:32:23 2016 Pierre Narcisi
** Last update Sun Mar 19 20:29:54 2017 John Doe
*/

#include "my.h"

sfColor my_color(char c)
{
  sfColor color;

  if (c == 'r')
    color = sfRed;
  else if (c == 'w')
    color = sfWhite;
  else if (c == 'm')
    color = sfMagenta;
  else if (c == 'b')
    color = sfBlue;
  else if (c == 'y')
    color = sfYellow;
  else if (c == 'g')
    color = sfGreen;
  return (color);
}

sfVector3f my_mult_vect_mat(sfVector3f eye, float **inv)
{
  sfVector3f ouais;

  ouais.x = eye.x * inv[0][0] + eye.y * inv[0][1] + eye.z * inv[0][2] + inv[0][3];
  ouais.y = eye.x * inv[1][0] + eye.y * inv[1][1] + eye.z * inv[1][2] + inv[1][3];
  ouais.z = eye.x * inv[2][0] + eye.y * inv[2][1] + eye.z * inv[2][2] + inv[2][3];
  return (ouais);
}

float abso(float nb)
{
  if (nb > 0)
    return (nb);
  else
    return (nb * -1);
}

void my_change_buffer(t_value *value)
{
  sfVector2i pos;
  sfColor color;
  sfVector2f size;

  size.x = 2;
  size.y = 2;
  init_eye(value);
  pos.y = 0;
  while (pos.y < HEIGHT)
  {
    pos.x = 0;
    while (pos.x < WIDTH)
    {
      k_value(value, pos, calc_dir_vector(pos));
      color = selecte_col(value, size, pos);
      my_put_pixel(value->framebuffer, pos.x, pos.y, color);
      pos.x++;
    }
    pos.y++;
  }
}

int main(int ac, char **av)
{
  disp(my_frame_buffer_create(WIDTH, HEIGHT), create_window(), av);
  return (0);
}
