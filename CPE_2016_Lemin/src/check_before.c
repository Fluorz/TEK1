/*
** check_before.c for check_before.c in /home/lecherbonnier/Projet/CPE_2016_Lemin/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sun Apr 30 10:51:58 2017 Leo Lecherbonnier
** Last update Jan Apr 30 11:04:34 2017
*/

#include "open_file.h"

char	**before(t_info	*info)
{
  char	**new_tab;
  int	i = 0;
  int	j = 0;
  int	x = 0;

  while (info->file[j])
    j++;
  if ((new_tab = malloc(sizeof(char *) * j + 10)) == NULL)
    return (NULL);
  while (info->file[i])
    {
      if (my_strlen(info->file[i]) == 0)
	i++;
      else if (info->file[i][0] == '#' && info->file[i][1] != '#')
	i++;
      else
	other_condition(info, new_tab, &i, &x);
    }
  return (new_tab);
}

int	other_condition(t_info *info, char **new_tab, int *i, int *x)
{
  if (my_strcmp("##start", info->file[*i]) == 0 ||
	   my_strcmp("##end", info->file[*i]) == 0)
    {
      new_tab[*x] = my_strdup(info->file[*i]);
      *x = *x + 1;
      *i = *i + 1;
    }
  else
    {
      check_comment(info->file, new_tab, *i, *x);
      *x = *x + 1;
      *i = *i + 1;
    }
  return (SUCCESS);
}
