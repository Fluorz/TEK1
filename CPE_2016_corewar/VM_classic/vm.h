/*
** vm.h for vm.h in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sat Mar 11 11:59:35 2017 Leo Lecherbonnier
** Last update Sun Apr  2 18:14:25 2017 Leo Lecherbonnier
*/

#ifndef _MY_VM__
#define _MY_VM__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include "../include/my.h"
#include "../include/op.h"
#include "graph.h"

# define DEAD 1000
# define ALIVE 1001
# define SUCCESS 0
# define FAILURE -1
# define FALSE 0
# define TRUE 1
# define CONVERT(nbr) convert_indian(&nbr, sizeof(nbr))

char	*winner;
char	map[MEM_SIZE];

typedef struct	s_arena
{
  char	*map;
  int		size;
  int		current_cycle;
  int		cycle_to_die;
  int		nbr_alive;
  int		nbr_player;
  int		*pc;
}		t_arena;

typedef struct	s_px
{
  int		p1;
  int		p2;
  int		p3;
  int		p4;
  int		pp1;
  int		pp2;
  int		pp3;
  int		pp4;
}		t_px;

typedef struct		s_cmd
{
int	instruction;
int	coding_byte;
int			args_type[MAX_ARGS_NUMBER];
int			args_value[MAX_ARGS_NUMBER];
}									t_cmd;

typedef struct		s_hd
{
  int			magic;
  char			prog_name[PROG_NAME_LENGTH + 1];
  int			prog_size;
  char			comment[COMMENT_LENGTH + 1];
}			t_hd;

typedef struct	s_champ
{
  int			j;
  int			nbr_pc;
  int			alive;
  int			nbr_live;
  int			id;
  int			nbr_player;
  int			carry;
  char		*name;
  char		*header_file;
  char		*code;
  int			cycle;
  int			cycle_to_die;
  int			new_pc;
  int			pc;
  int			registre[16];
  t_hd			*header;
  t_cmd			*cmd;
  int				*live;
  int				len;
}		t_champ;

typedef struct s_option
{
  int	dump;
  int prog_number;
  int	load_address;
}								t_option;

/*TOOLS*/
char    *my_parse_str(int s, int e, char *str);
char	*get_next_line(const int fd);
char	*int_to_str(int nbr);
char    **str_to_tab(char *str);
char	*my_realloc(char *str, int size);
void	nbrbase(int nb, char *base);

/*print_help.c*/
void	print_help();

/*init_memory.c*/
int	init_memory();

/*get_option.c*/
t_option	init_option();
int	get_option(char **av, t_option *option);

/*init_arena.c*/
t_arena	init_arena(int	player, t_champ *champ);
t_arena	put_code(t_arena arena, t_champ *champ);
t_arena	init_pc(t_arena arena);
int	my_op_strdup(char *dest, char *elem, int start, int len);

/*game.c*/
int		start_battle(t_champ *champ, t_arena arena, t_option option);
int	still_alive(t_champ *champ);
int		handle_cycles(t_arena *arena, t_champ *champ, int i);
int		actualise_cycles(t_arena *arena, t_champ *champ, int i);

/*init_champs*/
int	my_op_cmp(char *str, char *elem);
int	my_open_file(char *file, int *fd);
/*static int	my_reader_header(char *file, int fd, t_champ *champ, int id);*/
int	my_reader_code(char *file, int fd, t_champ *champ, int id);
t_champ	*put_champs(t_champ *champs, char **av, int ac);

/*convert_indian.c*/
void		convert_indian(void *input, int n);

/*execution.c*/
int	reset_champ(t_champ *champ, int i);
int	exec_command(t_champ *champ, t_arena arena, int i);

void		print_arena(char *str, int len);
t_champ	*init_else_champ(t_champ *champ);

/*take.c*/
int	take_ld(t_arena arena, t_champ *champ, int i, int *index);
int	take_register_number(t_arena arena, t_champ *champ, int i, int *index);
int	take_3_params(t_arena arena, t_champ *champ, int i, int *index);
int	take_register(t_arena arena, t_champ *champ, int i, int *index);
int	take_label(t_arena arena, t_champ *champ, int i, int *index);
int	take_direct(t_arena arena, t_champ *champ, int i, int *index);
int	take_indirect(t_arena arena, t_champ *champ, int i, int *index);
t_champ	*put_pc(t_champ *champ);

/*live.c*/
int	say_hello(t_champ *champ, t_arena arena, int i);

int	debug(t_champ *champ, t_arena arena, int i);
int	starter(t_champ *champ, t_arena arena, int i);
void	exec_instruction(t_champ *champ, t_arena arena, int i);
t_champ	*struct_op(t_champ *champ, int id, int pc);
int	handle_champ(t_arena *arena, t_champ *champ, int i);

int	instruct_live(t_champ *champ, t_arena arena, int i);
int	instrcution_zjmp(t_champ *champ, t_arena arena, int i);
int	instruction_fork(t_champ *champ, t_arena arena, int i);
int	instruction_lfork(t_champ *champ, t_arena arena, int i);
int	instruction_ld(t_champ *champ, t_arena arena, int i);
int	instruction_st(t_champ *champ, t_arena arena, int i);
int	instruction_add(t_champ *champ, t_arena arena, int i);
int	instruction_sub(t_champ *champ, t_arena arena, int i);
int	instruction_and(t_champ *champ, t_arena arena, int i);
int	instruction_or(t_champ *champ, t_arena arena, int i);
int	instruction_ldi(t_champ *champ, t_arena arena, int i);
int	instruction_sti(t_champ *champ, t_arena arena, int i);
int	instruction_lld(t_champ *champ, t_arena arena, int i);
int	instruction_lldi(t_champ *champ, t_arena arena, int i);
int	check_carry(t_champ *champ, int registre, int i);
int	go_other(t_champ *champ, t_arena arena, int i);
int	s_s(t_champ *champ, t_arena arena, int i, int where);
int	get_args_next(t_arena arena, t_champ *champ, int i);
t_my_core moyen(t_champ *champ, t_my_core cr, t_arena arena, int i);
t_champ   *end_alive(t_champ *champ, t_my_core cr, int i);

#endif /*!MY_H*/
