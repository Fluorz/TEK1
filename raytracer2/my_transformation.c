/*
** my_transformation.c for raytracer1 in /home/byliarus/work/Graph/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Feb 27 19:38:49 2017 John Doe
** Last update Tue Jun  6 13:04:44 2017 Pierre Narcisi
*/

#include "my.h"

float **mat_cp(float **src)
{
  float **res;
  int i;
  int j;

  i = -1;
  if (!(res = malloc(sizeof(float*) * 5)))
    return (NULL);
  while (++i < 4)
  {
    if (!(res[i] = (float*)malloc(sizeof(float) * 5)))
      return (NULL);
    j = -1;
    while (++j < 4)
      res[i][j] = src[i][j];
  }
  return (res);
}

float **init_id()
{
  float **id;
  int i;
  int j;

  i = 0;
  if (!(id = malloc(sizeof(float*) * 5)))
    return (NULL);
  while (i < 4)
  {
    if (!(id[i] = (float*)malloc(sizeof(float) * 5)))
      return (NULL);
    j = 0;
    while (j < 4)
    {
      id[i][j] = 0;
      j++;
    }
    i++;
  }
  id[0][0] = 1;
  id[1][1] = 1;
  id[2][2] = 1;
  id[3][3] = 1;
  return (id);
}

float **my_translation(sfVector3f vect)
{
  float **id;

  id = init_id();
  id[0][3] = vect.x;
  id[1][3] = vect.y;
  id[2][3] = vect.z;
  return (id);
}

float **matrix_mult(float **src, float **dest)
{
  int i;
  int j;
  float **res;

  if (!(res = malloc(sizeof(float*) * 5)))
    return (NULL);
  i = -1;
  while (++i < 4)
  {
    if (!(res[i] = malloc(5 * sizeof(float))))
      return (NULL);
    j = -1;
    while (++j < 4)
    {
      res[i][j] = src[i][0] * dest[0][i] + src[i][1] * dest[1][i] + src[i][2]
       * dest[2][i] + src[i][3] * dest[3][i];
    }
  }
  return (res);
}

sfVector3f my_transformations(t_object *object, sfVector3f eye)
{
  float **trans;
  float **inv;

  inv = init_id();
  trans = my_translation(object->pos);
  object->matrice = mat_cp(trans);
  pivot(trans, inv, 4);
  div_coef(inv, trans, 4);
  return (my_mult_vect_mat(eye, inv));
}
