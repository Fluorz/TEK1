/*
** my.h for my in /home/ferlet_n/colle/CPE_2016_stumper3/include
**
** Made by Nicolas Ferlet
** Login   <ferlet_n@epitech.net>
**
** Started on  Tue May  2 07:20:09 2017 Nicolas Ferlet
** Last update Tue May  2 10:23:34 2017 Nicolas Ferlet
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

typedef struct	s_param
{
  char		*file;
  int		size;
}		t_param;

typedef struct	s_word
{
  char		*str;
  struct s_word	*next;
}		t_word;

typedef struct	s_all_word
{
  int		found;
  int		total;
  t_word	*list;
}		t_all_word;

typedef struct	s_pos
{
  int		i;
  int		j;
  int		i_less;
  int		j_less;
}		t_pos;

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
int	my_error(char *str, int nb);
int     my_strcpy(char *str, char *dest);
int     my_strlen(char *str);
char    *my_realloc(char *str);
int	my_strcmp(char *str, char *other);
char	*revert_str(char *str);
void	my_put_nbr(int nbr);
char    get_char(int fd);
int     my_get_nbr(char *str);
char	*get_next_line(int fd);
void	free_tab(char **tab);

int	get_param(t_param *param, char **argv);

t_word	*create_node(char *str);
void	add_node(t_word **list, char *str);
void	remove_one(t_word **list, t_word **to_delete);

int	get_database(t_all_word *data, t_param *param);

void	print_tab(char **tab);
void	first_and_last_line(char **tab);
void	fill_tab(char **tab);

int	my_strcmp2(char *str, char *needed);

void	find_word(char **tab, t_all_word *data);

#endif /* !MY_H_ */
