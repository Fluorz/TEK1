/*
** tetris.h for tetris in /home/monty/Documents/Rendu/tetris/PSU_2016_tetris/monty/include/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Thu Mar  9 16:13:56 2017 Monty Criel
** Last update Fri Mar 10 18:49:10 2017 Monty Criel
*/

#include "linked_list.h"

int	check_tetrimino(void);
char	*get_data(char *file_name);
char	**tetris_wordtab(char *str);
int	max_width(char **tetrimino);
void	print_tetrimino_name(char *file);
int	print_tetrimino_size(char **tetrimino);
int	tetrimino_color(char **tetrimino);
int	is_tetrimino(char *file);
t_list	*tetrimino_list(DIR *directory, struct dirent *dir);
char	*get_data(char *file_name);
void	sort_list(t_list *list);
