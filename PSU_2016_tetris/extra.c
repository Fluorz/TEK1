/*
** extra.c for tetris in /home/monty/Documents/Rendu/tetris/PSU_2016_tetris/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sun Mar 19 17:02:02 2017 Monty Criel
** Last update Sun Mar 19 20:19:14 2017 Monty Criel
*/

#include <unistd.h>
#include "linked_list.h"
#include "tetris.h"
#include "my.h"

char	*epure_tetrimino(char *str)
{
  int	i;

  while (str[i] != '\0')
    i += 1;
  i = i - 1;
  while (str[i] == ' ')
    i -= 1;
  str[i + 1] = '\0';
  return (str);
}

void		remove_carrage(t_list *list)
{
  t_node	*tmp;
  int		i;

  tmp = list->head;
  while (tmp != NULL)
    {
      i = 0;
      while (tmp->tetrimino[i] != NULL)
	{
	  tmp->tetrimino[i] = my_strdup(epure_tetrimino(tmp->tetrimino[i]));
	  if (my_strlen(tmp->tetrimino[i]) == 1 &&
	      tmp->tetrimino[i][0] == '\n')
	    tab_pop(tmp->tetrimino, i);
	  i += 1;
	}
      tmp = tmp->next;
    }
}
