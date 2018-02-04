/*
** new_game.c for new_game.c in /home/lecherbonnier/Projet/CPE_2016_Lemin/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri Apr 28 12:19:06 2017 Leo Lecherbonnier
** Last update Jan Apr 30 20:58:42 2017
*/

#include "open_file.h"

int	put_in_graph(char **tab, t_elem **new_elem, int nb_ants)
{
 char	**new_tab;
  t_elem	*nod_1;
  t_elem *nod_2;
  int	j = 0;

  while (tab[j][1] != '-')
    j++;
  if (tab[j][1] != '-' && tab[j + 1][1] == '-')
    j++;
  while (tab[j])
    {
      new_tab = my_str_to_wordtab(tab[j], '-');
      nod_1 = my_node_create(new_tab[0], new_elem);
      nod_2 = my_node_create(new_tab[1], new_elem);
      if ((node_linker(new_elem, nod_1, nod_2)) != SUCCESS)
	return (FAILURE);
      j++;
    }
  path_finding(0, end_graph(new_elem));
  if ((find_road(*new_elem, nb_ants)) != SUCCESS)
    return (FAILURE);
  return (SUCCESS);
}

t_elem		*end_graph(t_elem **elem)
{
  t_elem		*end;

  end = *elem;
  while (end->next != NULL)
    end = end->next;
  return (end);
}

int	create_my_graph(char **tab, int nb_ants)
{
  t_elem	*new_elem;
  int	j = 0;

  new_elem = NULL;
  while (tab[j][1] != ' ')
    j++;
  while (tab[j])
    {
      if (tab[j][1] == '#')
	j++;
      if (tab[j][1] == '-')
	break;
      graph_init(&new_elem, tab[j]);
      j++;
    }
  if ((put_in_graph(tab, &new_elem, nb_ants)) != SUCCESS)
    return (FAILURE);
  return (SUCCESS);
}

int	launch_resolution(t_info *info, int nb_ants)
{
  my_printf("#moves\n");
  if ((create_my_graph(info->file, nb_ants)) != SUCCESS)
    return (FAILURE);
  return (SUCCESS);
}
