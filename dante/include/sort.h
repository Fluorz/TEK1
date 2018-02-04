/*
** sort.h for sort.h in /home/benjamin/chikho_b/rendu/CPE/CPE_2016_Lemin
**
** Made by Benjamin
** Login   <benjamin@epitech.net>
**
** Started on  Fri Apr 28 11:33:57 2017 Benjamin
** Last update Fri Apr 28 23:10:57 2017 Benjamin
*/

# ifndef SORT_H
# define SORT_H

typedef struct	s_tree
{
  int		trick;
  char		*line;
  struct s_tree	*left;
  struct s_tree *right;
}		t_tree;

int		my_getnbr(char *str);
char		**my_str_to_wordtab(char *str, char c);
int		my_strncmp(char *str, char *cmp, int n);
int		my_strlen(char*);
int		my_super_strlen(char *, char);
char		**binary_tree_to_tab(t_tree*, char **, int *);
char		*my_strdup(char *);
void		print_tab(char **tab);
int		count_tree(t_tree *, int);
int		is_char_in_string(char *, char);

# endif
