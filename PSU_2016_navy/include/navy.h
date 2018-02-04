/*
** navy.h for navy.h in /home/lecherbonnier/Projet/PSU_2016_navy/include/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Feb 13 09:32:00 2017 Leo Lecherbonnier
** Last update Thu Feb 16 17:24:29 2017 Leo Lecherbonnier
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "gnl.h"
#include "func_struc.h"
#include "my.h"

typedef struct	s_glob
{
  int			pid_adverse;
  char			position_envoye[2];
}			t_glob;

typedef struct	s_player
{
  char			**map;
  char			**enemy;
  int			ships;
}			t_player;

typedef struct	s_pos
{
  int			x;
  int			y;
}			t_pos;

struct s_glob g_player;

int	main_option(int ac, char **av);

void sig_handler(int signo, siginfo_t *info, void *);
void	check_connection(struct sigaction s_sa);
void	check_first_connection(struct sigaction s_sa);
void	print_info(void);

void	send_signal(char *str, int pid);
void	send_letter(int	binaire, int pid);
void	send_number(int binaire, int pid);
int		caracter_str(char *str);
int		number_str(char *str);
int		transform_caracter(int);
int		transform_number(int);
void	my_writer(int bin);
void	convert_binaire(char *str);
void	convert_binaire_number(char *c);
int		**convert_pid_bin(int pid);
char	*transform_less1(int j);
void	send_pid(int pid, char *str);
pid_t	create_process(void);
int	player2(struct sigaction s_sa, t_player *player2, char **av);
int	player1(struct sigaction s_sa, t_player *player1, char **av);
int	check_coord(char *target);
int	check_str(char *str);
void	send_hit_or_missed(char *str, int pid);
char	*attack_status(char *target, char **map);
void	display_map(char **enemy, char **map2);
char	**create_board(void);
void	print_board(char **map);
void	shoot(t_player *player, char *target, char option);
int	place_ships(char **map, char *av);
void	fill_row1(char **map);
int	check_boats(char **coord);
char	**get_boat_coord(char *str);
int	count_ships(char *av);
int	set_player_1(struct sigaction s_sa,
		     t_player *player1, char **av);
int	set_player_2(struct sigaction s_sa, t_player *player2,
		     char **av, int pid_player2);
void	print_first_map(char **map, char **enemy);
t_player	*init_player(char *av);
char	*attack_message(char *target, char **map);
int	game_end(int ships);
char *up(char *str);
int	count_cross(char **map);
char *str_inutile();
