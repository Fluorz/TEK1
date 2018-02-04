/*
** my.h for my.h in /home/lecherbonnier/Projet/CPE_2016_stumper4/include/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue May  9 12:22:09 2017 Leo Lecherbonnier
** Last update Mar May 9 12:22:14 2017
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_param
{
  char		*file;
  int		nb;
  char		**tab;
}		t_param;

void	my_putchar(char c);
void	my_putstr(char *str);

int	my_error(char *str, int nb);
int	my_strlen(char *str);
char	*my_strcpy(char *str, char *dest);

void	free_tab(char **tab);
int	my_tablen(char **tab);

int	my_get_nbr(char *str);

int	check_file(char *file);
int	get_param(t_param *param, char **argv);

char	*my_get_next_line(int fd);

char	**get_file(char *file);
int	check_tab(char **tab);

int	increase(char **tab, int nb);
int	get_len(char **tab);
int	voisin(char **tab, int i, int j);
char	**algo(char **tab);
#endif /* !MY_H_ */
