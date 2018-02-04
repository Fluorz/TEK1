/*
** create_framebuffer.c for frame create in /home/abdel/wireframe
** 
** Made by Abderrahim CHERKAOUI
** Login   <abdel@epitech.net>
** 
** Started on  Thu Dec  8 10:34:51 2016 Abderrahim CHERKAOUI
** Last update Sat Apr  1 06:22:07 2017 Cherkaoui
*/

#include "../graph.h"

t_my_framebuffer*	my_framebuffer_create(int width, int height)
{
  int   i;
  t_my_framebuffer*	framebuffer;
  sfUint8*		pixel;

  framebuffer = malloc(sizeof(t_my_framebuffer));
  pixel = malloc(sizeof(sfUint8) * (width * height * 4));
  if (pixel == NULL)
    exit(84);
  i = 0;
  if (!pixel)
    exit(84);
  framebuffer->width = width;
  framebuffer->height = height;
  framebuffer->pixels = pixel;
  while (i < width * height * 4)
    {
      framebuffer->pixels[i] = 0;
      i++;
    }
  return (framebuffer);
}
