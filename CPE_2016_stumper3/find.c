/*
** find.c for find.c in /home/lecherbonnier/Projet/CPE_2016_stumper3/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue May  2 12:14:27 2017 Leo Lecherbonnier
** Last update Tue May  2 10:30:02 2017 Nicolas Ferlet
*/

#include "my.h"

char	*build_str(char **tab, t_pos pos, int nb)
{
  char	*new;
  int	i;
  int	j;

  i = pos.i;
  j = pos.j;
  while (j >= 0 && tab[j] != NULL &&
	 i >= 0 && tab[j][i] != '\0')
    {
      j = j + pos.j_less;
      i = i + pos.i_less;
      nb = nb + 1;
    }
  if (!(new = malloc(sizeof(char) * (nb + 1))))
    return (NULL);
  i = -1;
  while (++i != nb)
    {
      new[i] = tab[pos.j][pos.i];
      pos.i = pos.i + pos.i_less;
      pos.j = pos.j + pos.j_less;
    }
  new[i] = '\0';
  return (new);
}

void	fill_new(char **new, char **tab, int i, int j)
{
  new[0] = build_str(tab, (t_pos){i, j, -1, 0}, 0);
  new[1] = build_str(tab, (t_pos){i, j, -1, -1}, 0);
  new[2] = build_str(tab, (t_pos){i, j, 0, -1}, 0);
  new[3] = build_str(tab, (t_pos){i, j, 1, -1}, 0);
  new[4] = build_str(tab, (t_pos){i, j, 1, 0}, 0);
  new[5] = build_str(tab, (t_pos){i, j, 1, 1}, 0);
  new[6] = build_str(tab, (t_pos){i, j, 0, 1}, 0);
  new[7] = build_str(tab, (t_pos){i, j, -1, 1}, 0);
  new[8] = NULL;
}

void		reduce_find(t_all_word *data, int *k)
{
  data->found += 1;
  *k = -1;
}

void		find_multiple(int i, int j, char **tab, t_all_word *data)
{
  char		**new;
  t_word	*beg;
  int		k;

  if (!(new = malloc(sizeof(char *) * 9)))
    return ;
  fill_new(new, tab, i, j);
  beg = data->list;
  while (data->list != NULL)
    {
      k = -1;
      while (++k != 8)
	{
	  if (data->list != NULL && my_strcmp2(new[k], data->list->str) == 1)
	    {
	      reduce_find(data, &k);
	      remove_one(&beg, &(data->list));
	      data->list = beg;
	    }
	}
      if (data->list != NULL)
	data->list = data->list->next;
    }
  data->list = beg;
  free_tab(new);
}

void	find_word(char **tab, t_all_word *data)
{
  int	i;
  int	j;

  j = 0;
  while (tab[j] != NULL)
    {
      i = 0;
      while (tab[j][i] != '\0')
	{
	  find_multiple(i, j, tab, data);
	  i = i + 1;
	}
      j = j + 1;
    }
}
