/*
** bsq.h for bsq.h in /root/Desktop/CPE/CPE_2016_BSQ/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Thu Dec  8 15:34:40 2016 Leo Lecherbonnier
** Last update Sun Dec 18 17:20:12 2016 Leo Lecherbonnier
*/


#ifndef	BSQ_H
# define BSQ_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "my.h"

typedef struct s_max
{
  int	ligne;
  int	colums;
  int	max;
  int	caractere;
  int	len;
}	t_max;

char	*fs_open_file(char* filepath, t_max *list);
void	map(char *file, t_max *list, int, int);
int	check_square(int *tab, int colums, int j);
void find_square(char *str, t_max *list, int i, int j);

#endif /* !BSQ_H */
