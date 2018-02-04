/*
** navy.h for navy.h in /home/lecherbonnier/Projet/PSU_2016_navy/include/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Feb 13 09:32:00 2017 Leo Lecherbonnier
** Last update Sun Mar 19 20:28:09 2017 Monty Criel
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <string.h>
#include <unistd.h>
# include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "gnl.h"
#include "func_struc.h"
#include "linked_list.h"
#include "leo.h"
#include "my.h"

# define BUFF_SIZE 4096
typedef struct s_debug
{
  char	*key_left;
  char	*key_right;
  char	*key_turn;
  char	*key_drop;
  char	*key_quit;
  char	*key_pause;
  char	*next;
  int		level;
  char	*size;
  int		ac;
  int		boolean;
  char	**list;
  int		len_list;
}								t_debug;

typedef struct	s_flag
{
  	char	*arr;
  	t_debug	(*s_flag)(t_debug debug, char **list, char *str);
}								t_flag;

int	print_info(char **av);
t_debug	init_debug(int, t_debug debug);
t_debug	build_debug(t_debug debug);
t_debug	flag_level(t_debug debug, char **list, char *str);
t_debug	flag_key_left(t_debug debug, char **list, char *str);
t_debug	flag_key_right(t_debug debug, char **list, char *str);
t_debug	flag_key_turn(t_debug debug, char **list, char *str);
t_debug	flag_key_drop(t_debug debug, char **list, char *str);
t_debug	flag_key_quit(t_debug debug, char **list, char *str);
t_debug	flag_key_pause(t_debug debug, char **list, char *str);
t_debug	flag_key_map(t_debug debug, char **list, char *str);
t_debug	flag_key_next(t_debug debug, char **list, char *str);
t_debug	flag_key_debug(t_debug debug, char **list, char *str);
t_debug	parse_list(char **list, int ac, t_debug debug);
t_debug	check_other(t_debug);
char	**init_tab(t_debug debug);
void	print_debug(t_debug debug);
int	check_after_minus(char **list, int j);
int	check_after_arg(char **list, int j);
char	**convert_arg(char *str, t_debug debug, int j);
int	check_special_case(char *str);
int	check_list(char **list, int len);
void	my_memset(void *mem, char c, int size);
int			initTerm(bool mode);
int	map(void);

char	*get_data(char *file_name);
int	check_tetrimino(void);
char	*get_data(char *file_name);
char	**tetris_wordtab(char *str);
int	max_width(char **tetrimino);
void	print_tetrimino_name(char *file);
int	print_tetrimino_size(char **tetrimino);
int	tetrimino_color(char **tetrimino);
int	is_tetrimino(char *file);
t_list	*tetrimino_list(DIR *directory);
char	*get_data(char *file_name);
void	sort_list(t_list *list);
int	error_tetriminos(t_list *list);
void	init_node(t_node *node, char *file, char *file_name);
void	append_tail(t_list *list, t_node *node);
void	add_node(t_list *list, t_node *node, char *file, char *name);
char	**tab_pop(char **tab, int pos);
void	remove_carrage(t_list *list);
char	*epure_tetrimino(char *str);
t_list	*empty_list(t_list *list);
