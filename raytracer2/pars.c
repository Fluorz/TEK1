/*
** pars.c for ray in /home/byliarus/work/Graph/raytracer1/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Mar  1 16:36:15 2017 John Doe
** Last update Tue Jun  6 13:06:01 2017 Pierre Narcisi
*/

#include "my.h"

int my_count_word (char *str)
{
  int i;
  int nb;

  i = 0;
  nb = 0;
  while (str[i])
  {
    if (str[i] == ':')
    nb++;
    i++;
  }
  return (nb);
}

int word_length(int j, char *str)
{
  int i;

  i = 0;
  while (str[j] != ':' && str[j] != '\0')
    {
      i++;
      j++;
    }
    return (i);
}

char **my_str_to_wordtab(char *str)
{
  char **tab;
  int word;
  int length;
  int i;
  int k;
  int j;

  i = -1;
  j = -1;
  word = my_count_word(str) + 1;
  if (!(tab = malloc(sizeof(char*) * (word + 1))))
    return (NULL);
  while (++i < word)
  {
    k = -1;
    length = word_length(j + 1, str);
    if (!(tab[i] = malloc(sizeof(char) * (length + 1))))
      return (NULL);
    while (++k < length)
    {
      tab[i][k] = str[++j];
    }
    j++;
    tab[i][k] = '\0';
  }
  tab[i] = NULL;
  return (tab);
}

void my_init(t_object *object, char **tab)
{
  object->pos.x = my_atoi(tab[2]);
  object->pos.y = my_atoi(tab[3]);
  object->pos.z = my_atoi(tab[4]);
  object->size = my_atoi(tab[5]);
}

t_object *pars(char *file)
{
  t_object *objects;
  int fd;
  int i;
  char **tab;
  char *str;

  i = 0;
  if (!(objects = malloc(sizeof(t_object) * (11))))
    return (NULL);
  fd = open(file, O_RDWR);
  while ((str = get_next_line(fd)) != NULL)
  {
    tab = my_str_to_wordtab(str);
    objects[i].type = tab[0][0];
    objects[i].color = my_color(tab[1][0]);
    if (objects[i].type != 'p')
      my_init(&objects[i], tab);
    objects[i].bol = 1;
    i++;
  }
  objects[i].bol = 0;
  return (objects);
}
