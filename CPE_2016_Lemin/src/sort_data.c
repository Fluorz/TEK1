/*
** sort_data.c for sort_data.c in /home/benjamin/chikho_b/rendu/CPE/CPE_2016_Lemin/src
**
** Made by Benjamin
** Login   <benjamin@epitech.net>
**
** Started on  Fri Apr 28 11:32:40 2017 Benjamin
** Last update Jun Apr 28 23:36:04 2017
*/

# include <stdlib.h>
# include "sort.h"

static t_tree	*create_node(char *str, int trick)
{
  t_tree	*new;

  if ((new = malloc(sizeof(t_tree))) == NULL)
    return (NULL);
  new->trick = trick;
  new->line = str;
  new->left = NULL;
  new->right = NULL;
  return (new);
}

static t_tree	*add_binary_node(t_tree **tree, char *line, int flag)
{
  if (*tree == NULL)
    *tree = create_node(line, flag);
  else if (flag == 1)
    add_binary_node(&(*tree)->left, line, flag);
  else if (flag == 2)
    add_binary_node(&(*tree)->right, line, flag);
  else if ((my_getnbr(line)) > (my_getnbr((*tree)->line)) &&
	   (*tree)->trick != 2)
    add_binary_node(&(*tree)->right, line, flag);
  else if ((my_getnbr(line)) < (my_getnbr((*tree)->line)) &&
	   (*tree)->trick != 1)
    add_binary_node(&(*tree)->left, line, flag);
  else if ((my_getnbr(line)) < (my_getnbr((*tree)->line)) &&
	   (*tree)->trick != 2)
    add_binary_node(&(*tree)->right, line, flag);
  else if ((my_getnbr(line)) > (my_getnbr((*tree)->line)) &&
	   (*tree)->trick != 1)
    add_binary_node(&(*tree)->left, line, flag);
  else
    add_binary_node(&(*tree)->left, line, flag);
  return (*tree);
}

static t_tree	*add_binary_node_bis(t_tree **tree, char **tab, char *str)
{
  int		i;
  int		skip;

  i = 0;
  skip = 0;
  if (*tree == NULL)
    *tree = create_node(str, 0);
  else if ((my_getnbr(tab[i])) == (my_getnbr((*tree)->line)))
    {
      skip = my_super_strlen((*tree)->line, '-') + 1;
      ++i;
    }
  if ((my_getnbr(tab[i])) > (my_getnbr((*tree)->line + skip)))
    add_binary_node_bis(&(*tree)->right, tab, str);
  else if ((my_getnbr(tab[i])) < (my_getnbr((*tree)->line + skip)))
    add_binary_node_bis(&(*tree)->left, tab, str);
  return (*tree);
}

t_tree		*make_binary_tree(t_tree **tree, t_tree **room, char **tab)
{
  char		**tmp;
  int		i;

  i = -1;
  while (tab[++i])
    {
      if ((is_char_in_string(tab[i], '-')) == 1)
	{
	  tmp = my_str_to_wordtab(tab[i], '-');
	  *tree = add_binary_node_bis(tree, tmp, tab[i]);
	}
      else if ((is_char_in_string(tab[i], '#')) == 1)
	{
	  if ((my_strncmp(tab[i] + 2, "start", 5)) == 0)
	    *room = add_binary_node(room, tab[++i], 1);
	  else if ((my_strncmp(tab[i] + 2, "end", 3)) == 0)
	    *room = add_binary_node(room, tab[++i], 2);
	}
      else if ((is_char_in_string(tab[i], ' ')) == 1)
	*room = add_binary_node(room, tab[i], 0);
    }
  return (*tree);
}

char		**tri_data(char **tab)
{
  t_tree	*tree;
  t_tree	*room;
  int		i;
  char		**new;

  tree = NULL;
  room = NULL;
  make_binary_tree(&tree, &room, tab);
  i = (count_tree(tree, 0) + count_tree(room, 0));
  if ((new = malloc(sizeof(char *) * (i + 1))) == NULL)
    return (NULL);
  i = -1;
  binary_tree_to_tab(room, new, &i);
  binary_tree_to_tab(tree, new, &i);
  return (new);
}
