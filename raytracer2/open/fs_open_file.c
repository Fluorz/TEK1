/*
** fs_open_file.c for fs_open_file.c in /home/lecherbonnier/Projet/raytracer2/include/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sun May 28 20:22:19 2017 Leo Lecherbonnier
** Last update Jan May 28 23:16:38 2017
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include "gnl.h"
#include "open_file.h"
#include "raytracer.h"

char	**get_tab(char **av)
{
  char		*str;
  char		**tab;
  int		fd;
  int		j = 0;

  if (av[1] == NULL)
    return (NULL);
  if ((fd = open(av[1], O_RDONLY)) < 0)
    return (NULL);
  if ((tab = malloc(sizeof(char *) * 1100)) == NULL)
    return (NULL);
  while ((str = get_next_line(fd)))
    {
      if (str[0] == '\0' || my_strlen(str) == 0)
	{
	  tab[j] = NULL;
	  return (tab);
	}
      if (j >= 1000)
	return (NULL);
      tab[j] = my_strdup(str);
      j++;
    }
  return (tab);
}

t_object	*fs_open_file(char **av)
{
  char		**tab;
  int		i = 0;
  t_object	*object = NULL;
  t_object	*new_one;
  char		**new_tab;

  if ((tab = get_tab(av)) == NULL)
    return (NULL);
  if ((new_one = init_struct()) == NULL)
    return (NULL);
  printf("cocoooo %c\n", new_one->type);
  add_it(&object, new_one);
  printf("%c\n", object->type);
  while (tab[i])
    {
      printf("%s\n", tab[i]);
      if (my_strlen(tab[i]) > 4)
	{
	  if (f_ca("type:", tab[i]) == 0)
	    {
	      add_it(&object, new_one);
	      if ((new_one = init_struct()) == NULL)
		return (NULL);
	      new_one->type = tab[i][my_strlen("type:")];
	      printf("repere %c\n", new_one->type);
	    }
	  else if (f_ca("size:", tab[i]) == 0)
	    {
	      new_tab = my_str_to_wordtab(tab[i], ':');
	      new_one->type = atoi(new_tab[1]);
	      printf("kkkk size : %d\n", new_one->type);
	    }
	}
      i++;
    }
  add_it(&object, new_one);
  return (object);
}


int		checkout(t_object *object)
{
  t_object	*tmp;

  tmp = object;
  printf("ici %c\n", object->next->type);
  object = object->next;
  while (object->next != tmp)
    {
      printf("ici %c\n", object->type);
      object = object->next;
    }
  return (0);
}

int	main(int ac, char **av)
{
  t_object	*object;

  if ((object = fs_open_file(av)) == NULL)
    return (84);
  checkout(object);
}
