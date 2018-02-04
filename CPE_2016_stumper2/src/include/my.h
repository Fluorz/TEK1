/*
** my.h for my.h in /home/lecherbonnier/Projet/CPE_2016_stumper2/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Apr 25 12:15:13 2017 Leo Lecherbonnier
** Last update Tue Apr 25 10:45:27 2017 Nicolas Ferlet
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>

typedef struct	s_param
{
  int		width;
  int		height;
  char		avatar1;
  char		avatar2;
  char		referee;
}		t_param;

typedef struct	s_pos
{
  int		x;
  int		y;
  int		dec_x;
  int		dec_y;
  int		nb;
}		t_pos;

typedef struct	s_coord
{
  int		i;
  int		j;
}		t_coord;

int	my_putchar(char c);
int	my_putstr(char *str);
int	my_putchar_error(char c);
int	my_putstr_error(char *str);
int	my_error(char *str, int nb);
char	*my_strcpy(char *dest, char *str, int len);

int	my_strlen(char *str);
int	my_getnbr(char *str);

int	my_strcmp(char *str1, char *str2);
char	*get_next_line(int fd);

char	**create_bord(t_param param);
char	**put_space(char **tab, t_param param);

void	init_param(t_param *param);
int	get_width(t_param *param, char **argv, int *i);
int	get_height(t_param *param, char **argv, int *i);
int	get_avatar1(t_param *param, char **argv, int *i);
int	get_avatar2(t_param *param, char **argv, int *i);
int	get_referee(t_param *param, char **argv, int *i);

int	get_param(t_param *param, char **argv);
int	check_param(t_param *param);

int     distrib_diago(char **tab, int j, int i, char c);
int     check_line(char **tab, char c);
int     check_haut_gauche(char **tab, int j, int i, char c);
int     check_haut_droit(char **tab, int j, int i, char c);
int     check_bas_droit(char **tab, int j, int i, char c);
int     check_bas_gauche(char **tab, int j, int i, char c);
int     check_diago(char **tab, char c);
int     full_map(char **tab);

int	check_winner(char **tab, t_param *param);

void    put_in_tab(char **tab, int turn, t_param param, int nb);
int	game(t_param *param, char **tab);

#endif /* !MY_H_ */
