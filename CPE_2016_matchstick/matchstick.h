/*
** my.h for my.h in /home/lecherbonnier/bin/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Jan 30 11:18:48 2017 Leo Lecherbonnier
** Last update Fri Feb 24 09:57:44 2017 Leo Lecherbonnier
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include "./include/gnl.h"
#include "./include/my.h"

typedef struct s_player
{
  char	**map;
  char	*line;
  char	*number; //Matches
  int		len;
  int		len_max;

}							t_player;

t_player *first_action(t_player *player);
t_player *second_action(t_player *player);
t_player	handler_map(t_player player);
int	handler_lines(t_player player);
int	handler_matches(t_player player);
char	**create_map(int nombre_ligne);
char	*load_str(int	line, int nombre_ligne, int nombre_caractere);
void	print_map(char **map, int len);
int	player(char **map, int len, int len_max);
char	**move_pipe(int line, int number, char **map);
int	play_ia(char **map, int len, int len_max, int);
int rand_a_b(int a, int b);
int	check_end_game(char **map, int len);
int	where_are_pipe(char **map, int len);
int	get_how_many_pipe(t_player player);
int	check_other(t_player player);
int	how_many_pipe(char **map, int line);
int	check_macthes(int number, int matches, int line, char **map);
void	*end_return_null();
int	total_pipe(char **map, int len);
