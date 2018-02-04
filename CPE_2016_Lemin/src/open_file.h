/*
** open_file.h for open_file.h in /home/lecherbonnier/Projet/CPE_2016_Lemin/leo/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Apr 20 13:03:26 2017 Leo Lecherbonnier
** Last update Jan Apr 30 22:29:43 2017
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include "../include/my.h"
#include "../include/gnl.h"

# define SIZE_MALLOC 1000
# define SUCCESS 0
# define FAILURE -1
# define FALSE 0
# define TRUE 1

typedef struct s_room
{
  char*			name;
  int			x;
  int			y;
  struct	s_room		*next;
  struct	s_room		*prev;
  struct	t_access	*access;
}		t_room;

typedef struct	s_elem *ptr;

typedef struct	s_link
{
  ptr		way;
  struct s_link	*next;
  struct s_link	*prev;
}		t_link;

typedef struct	s_elem
{
  char		*name;
  int		x;
  int		y;
  int		temps;
  int		view;
  int		empty;
  t_link	*link;
  struct s_elem	*prev;
  struct s_elem	*next;
}		t_elem;

typedef struct	s_road
{
  t_elem	*oway;
  struct s_road	*next;
  struct s_road	*prev;
}		t_road;

typedef struct s_info
{
  int		nb_ant;
  t_room	start;
  t_room	end;
  char**	file;
}		t_info;

t_info	*get_file();
char	**epure(t_info	*info);
int	gestion_erreur(t_info	*info);
int	create_room(t_info *info);
void	print_ant(int ant);
void	print_tmp_moves();
int	check_comment(char **file, char **new_tab, int i, int x);
char	*take_name(char *str);
int	take_x(char *str);
int	take_y(char *str);
int	check_bad_caracter(char *str);
char	**tri_data(char **tab);
int	check_other(t_info *info, char ** new_tab, int *i, int *x);
int	check_before(t_info *info);
int	check_erreur(t_info *info, int *one, int j);
int	graph_init(t_elem **lem, char *line);
int	init_link(t_elem *lem, t_elem *ptr);
int	node_linker(t_elem **lem, t_elem *nod1, t_elem *nod2);
t_elem	*my_nod_create(char *name, t_elem **lem);
int	put_in_graph(char **tab, t_elem **elem, int nb_ants);
int	create_my_graph(char **tab, int nb_ants);
int	launch_resolution(t_info *info, int);
int	path_finding(int temps, t_elem *room);
void	road(t_road *road, int temps, t_link *temporaire, int boole);
t_elem	*end_graph(t_elem **lem);
int	find_road(t_elem *room, int ants);
int	check_after_end_start(char *str);
t_elem	*my_node_create(char *name, t_elem **elem);
void	two_possibilities(int nb_ants, t_road *road1, t_road *road2, int i);
void	only_one_possibility(int nbr_ants, t_road *road, int i, t_road *end);
int	check_room(char *str);
int	move_nbr_ants(int nbr_ants, t_road *road1, t_road *road2);
int	else_again(t_info *info, char ** new_tab, int *i, int *x);
char	**before(t_info	*info);
int	other_condition(t_info *info, char **new_tab, int *i, int *x);
t_road	*init_road(t_road *road, t_elem *pointeur);
int	before_return(t_road	*road1, t_road	*road2, int ants);
t_road	*first_step(t_road *road);
int	coordonate(int **new_tab);
int	check_coordonate(char **tab);
int	third_step(t_road *move2, t_road *end, t_road *road2, int nb_ants,
		    int	*i);
int	second_step(t_road *road1, t_road *move, t_road *end, int nb_ants,
		    int	*i);
char	**bad_epure(t_info	*info);
int	fcheck_other(t_info *info, char ** new_tab, int *i, int *x);
int	fcheck_bad_caracter(char *str);
int	fcheck_comment(char **file, char **new_tab, int i, int x);
int	check_room_and_co(char **tab);
int	check_name(char **name);
int	obtain_index(char **file);
int	check_connection(char **name, char **file);
t_elem		*road_link(t_link *tmp, int *temps, int boole);
t_road		*rd_ch(t_road *road);
t_road	*find_init(t_elem *room, t_road *road1, t_link *temporaire1,
		  int *temps);
t_road	*room_next(t_road *road2, t_elem *room, t_link *temporaire2,
		   int *temps);
t_link	*road_else(t_elem *pointeur, t_link *temporaire, t_road *road,
		   int boole);
