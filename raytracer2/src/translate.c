/*
** translate.c for raytracer1 in /home/byliarus/work/Graph/raytracer1/src/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Feb 27 14:26:13 2017 John Doe
** Last update Fri Mar 10 19:01:20 2017 John Doe
*/

#include "my.h"

sfVector3f translate(sfVector3f to_translate, sfVector3f translations)
{
  to_translate.x += translations.x;
  to_translate.y += translations.y;
  to_translate.z += translations.z;
  return (to_translate);
}
