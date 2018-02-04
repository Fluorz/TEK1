/*
** asm.h for corewar in /home/monty/Documents/Rendu/corewar/CPE_2016_corewar/ASM/monty/include/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sat Mar 11 12:41:09 2017 Monty Criel
** Last update Mon Apr  3 00:06:31 2017 Sid
*/

#ifndef _ASM_H_
# define _ASM_H_

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

char	*get_data(char *file_name);
char	**realloc_tab(char **tab, int size);
char	**wordtab(char *str);
char	**tab_append_tail(char **tab, char *str);
void	free_tab(char **tab);
void	print_tab(char **tab);
int	get_help(void);
int	create_header(char *av, char *cor_file);
int	get_prog_name(char *file, char *name);
int	get_prog_comment(char *file, char *comment);
int	change_endian(int nb);
t_list	*get_labels(char *av);
int	is_label(char *str);
char	**epure_wordtab(char **tab);
char	**get_label_instruction(char **tab, int line);
char	*get_label_name(char *str);
void	init_epure_label(char **tab, char *line1, char *line2);
char	**epure_label(char **inst);
int	get_label_len(char **tab, int line);
char	**wordtab_asm(char *str);
int	create_instructions(t_list *labels, char *file, char *cor_file);
char	**seperate_label_tab(char **tab);
char	**get_instruction(char *str);
char	**instruction_list(void);
char	get_mnemonic(char *inst);
char	**instruction_list(void);
char	*mnemonic_list(void);
int	binary_to_hex(char *str);
int	write_parameters(t_list *labels, char **instruction, int fd);
int	decimal_to_hex(int nb);
int	get_register_value(char *reg);
int	get_label_value(char *param, t_list *labels, char *option);
int	find_label_value(t_list *labels, char *label);
int	get_dir_value(char *param);
int	get_ind_value(char *param);
char	*my_find_label(char *str);
char	*revstr_bin(char *str);
char	*convert_bin(int nb);
char	**str_to_wordtab(char *str, char c);
char	**second_epure(char **tab);
char	**do_it_tab(char **tab);
int	my_asm(int argc, char **argv);

#endif
