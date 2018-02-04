/*
** error_handler.c for bootstrap tetris in /home/monty/Documents/Rendu/tetris/PSU_2016_btetris/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Tue Feb 21 11:11:53 2017 Monty Criel
** Last update Sun Mar 12 16:35:41 2017 Monty Criel
*/

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "tetris.h"
#include "my.h"

void		count_tetriminos(t_list *list)
{
  t_node	*tmp;
  int		i;

  tmp = list->head;
  i = 0;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      i += 1;
    }
  my_printf("Tetriminos : %d\n", i);
}

void	print_forme(char **tetrimino)
{
  int	x;
  int	y;

  x = 1;
  while (tetrimino[x] != NULL)
    {
      y = 0;
      while (tetrimino[x][y] != '\0')
	{
	  my_putchar(tetrimino[x][y]);
	  y += 1;
	}
      my_putchar('\n');
      x += 1;
    }
}

int		print_tetriminos(t_list *list)
{
  t_node	*tmp;
  int		size;
  int		status;

  count_tetriminos(list);
  tmp = list->head;
  while (tmp != NULL)
    {
      status = 0;
      print_tetrimino_name(tmp->name);
      size = print_tetrimino_size(tmp->tetrimino);
      if (size != 0)
	status = 1;
      if (size == 0)
	{
	  if (tetrimino_color(tmp->tetrimino) != 0)
	    status = 1;
	}
      if (status == 0)
	print_forme(tmp->tetrimino);
      tmp = tmp->next;
    }
  return (0);
}

int			check_tetrimino(void)
{
  t_list		*list;
  DIR			*directory;
  struct dirent	*dir;

  directory = opendir("./tetriminos");
  if (directory == NULL)
    {
      my_putstr("tetriminos directory not found\n");
      return (84);
    }
  list = tetrimino_list(directory, dir);
  sort_list(list);
  print_tetriminos(list);
  closedir(directory);
  my_putstr("Press any key to start Tetris\n");
  return (0);
}
