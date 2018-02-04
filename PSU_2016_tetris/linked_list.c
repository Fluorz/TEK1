/*
** linked_list.c for tetris in /home/monty/Documents/Rendu/tetris/PSU_2016_tetris/monty/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Thu Mar  9 16:22:32 2017 Monty Criel
** Last update Sat Mar 18 13:59:31 2017 Monty Criel
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "tetris.h"
#include "my.h"

t_node		*create_node(void)
{
  t_node	*node;

  node = malloc(sizeof(t_node));
  if (node == NULL)
    return (NULL);
  node->next = NULL;
  return (node);
}

void	init_node(t_node *node, char *file, char *file_name)
{
  node->name = my_strdup(file_name);
  node->tetrimino = tetris_wordtab(file);
  node->status = 0;
  if ((node->tetrimino == NULL) || (node->name) == NULL)
    exit(84);
}

void		append_tail(t_list *list, t_node *node)
{
  t_node	*tmp;

  tmp = list->head;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = node;
  node->next = NULL;
}

t_list		*init_tetrimino_list(char *tetrimino, int *tmp)
{
  t_list	*list;
  t_node	*node;
  char		*path;
  char		*file;

  if ((list = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  if ((node = malloc(sizeof(t_node))) == NULL)
    return (NULL);
  if (list == NULL || node == NULL)
    exit(84);
  list->head = node;
  path = my_strcat("./tetriminos/", tetrimino);
  file = get_data(path);
  node->name = tetrimino;
  node->tetrimino = tetris_wordtab(file);
  node->status = 0;
  node->next = NULL;
  if (node->tetrimino == NULL)
    exit(84);
  *tmp = 1;
  return (list);
}

t_list			*tetrimino_list(DIR *directory)
{
  t_list		*list;
  t_node		*node;
  int			tmp;
  char			*file;
  struct dirent	*dir;

  tmp = 0;
  list = NULL;
  while ((dir = readdir(directory)) != NULL)
    {
      if (is_tetrimino(dir->d_name) == 0)
	{
	  if (tmp == 0)
	    list = init_tetrimino_list(dir->d_name, &tmp);
	  else
	    {
	      file = get_data(my_strcat("./tetriminos/", dir->d_name));
	      if ((node = malloc(sizeof(t_node))) == NULL)
		return (NULL);
	      add_node(list, node, file, dir->d_name);
	    }
	}
    }
  return (empty_list(list));
}
