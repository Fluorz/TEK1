/*
** sort_data_bis.c for sort in /home/benjamin/chikho_b/rendu/CPE/CPE_2016_Lemin
**
** Made by Benjamin
** Login   <benjamin@epitech.net>
**
** Started on  Fri Apr 28 22:34:29 2017 Benjamin
** Last update Jun Apr 28 23:31:34 2017
*/

# include "sort.h"

int		my_super_strlen(char *str, char c)
{
  int		i;

  i = -1;
  while (str[++i] && str[i] != c);
  return (i);
}

int		count_tree(t_tree *tree, int count)
{
  if (tree->left)
    count = count_tree(tree->left, count);
  if (tree->right)
    count = count_tree(tree->right, count);
  return (++count);
}

char		**binary_tree_to_tab(t_tree *tree, char **tab, int *i)
{
  if (tree->left)
    binary_tree_to_tab(tree->left, tab, i);
  tab[++(*i)] = my_strdup(tree->line);
  if (tree->right)
    binary_tree_to_tab(tree->right, tab, i);
  return (tab);
}

int		is_char_in_string(char *str, char c)
{
  int		i;

  i = -1;
  while (str[++i])
    if (str[i] == c)
      return (1);
  return (0);
}
