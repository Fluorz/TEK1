/*
** translate.c for translate.c in /home/lecherbonnier/Projet/raytracer1/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Mar 14 18:15:58 2017 Leo Lecherbonnier
** Last update Tue Mar 14 18:22:56 2017 Leo Lecherbonnier
*/

#include "wolf3d.h"

sfVector3f translate(sfVector3f to_translate, sfVector3f translations)
{
  sfVector3f translate;

  translate.x = to_translate.x + translations.x;
  translate.y = to_translate.y + translations.y;
  translate.z = to_translate.z + translations.z;
  return (translate);
}
