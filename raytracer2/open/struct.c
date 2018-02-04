/*
** struct.c for struct.c in /home/lecherbonnier/Projet/raytracer2/open/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sun May 28 21:15:33 2017 Leo Lecherbonnier
** Last update Jan May 28 23:14:51 2017
*/

#include "open_file.h"
#include "raytracer.h"

int	f_ca(char *argument, char *where)
{
  int	i = 0;
  int	len = 0;

  len = my_strlen(argument);
  while (i != len && where[i])
    {
      if (argument[i] != where[i])
	return (1);
      i++;
    }
  return (0);
}

int	add_it(t_object **object, t_object *node)
{
  if (*object == NULL)
    {
      *object = node;
      (*object)->next = node;
      (*object)->prev = node;
      return (0);
    }
  if ((node->next = malloc(sizeof(t_object))) == NULL)
    return (-1);
  (*object)->prev->next = node;
  node->prev = (*object)->prev;
  node->next = (*object);
  (*object)->prev = node;
  /*(*object)->prev = node;
  node = (*object)->prev;
  node->next->next = *object;
  node->next->prev = node;
  (*object)->prev = node->next;*/
  return (0);
}

t_object *init_struct()
{
  sfVector3f pos;
  t_object *object;

  pos.x = -4;
  pos.y = 0;
  pos.z = 0;
  if (!(object = malloc (sizeof(t_object))))
    return (NULL);
  object->type = 's';
  object->size = 2;
  object->matrice = NULL;
  /*object->color = sfBlack;*/
  object->pos = pos;
  object->rota_x = 0;
  object->rota_y = 0;
  object->rota_z = 0;
  object->next = NULL;
  object->prev = NULL;
  return (object);
}
