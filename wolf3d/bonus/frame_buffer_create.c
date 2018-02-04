/*
** frame_buffer_create.c for frame_buffer_create.c in /home/lecherbonnier/Bureau/bswireframe/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Dec  8 14:00:55 2016 Leo Lecherbonnier
** Last update Wed Mar  8 10:25:43 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

t_my_framebuffer*   my_framebuffer_create(int width, int height)
{
  int   i;
  t_my_framebuffer* buffer;
  sfUint8*						pixels;

  i = 0;
  buffer = malloc(sizeof(t_my_framebuffer));
  pixels = malloc(sizeof(sfUint8) * (width * height * 4));
  if (buffer == NULL)
    exit(84);
  if (!pixels)
    exit(84);
  buffer->width = width;
  buffer->pixels = pixels;
  buffer->height = height;
  if (pixels == NULL)
    exit(84);
  while (i < (width * height * 4))
    {
      pixels[i] = 0;
      i++;
    }
  return (buffer);
}
