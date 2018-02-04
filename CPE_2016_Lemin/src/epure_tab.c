/*
** epure_tab.c for epure_tab.c in /home/lecherbonnier/Projet/CPE_2016_Lemin/leo/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Apr 24 11:54:01 2017 Leo Lecherbonnier
** Last update Jan Apr 30 09:54:15 2017
*/

#include "open_file.h"

int	got_line(char **tab)
{
  int	j = 0;

  while (tab[j])
    j++;
  return (j);
}

char	**epure(t_info	*info)
{
  char	**new_tab;
  int	i = 0;
  int	x = 0;
  int	pipe = 0;

  if ((new_tab = malloc(sizeof(char *) * got_line(info->file) + 10)) == NULL)
    return (NULL);
  while (info->file[i])
    {
      if (info->file[i][1] == '-')
	pipe++;
      if (my_strlen(info->file[i]) == 0)
	return (NULL);
      else if (check_bad_caracter(info->file[i]) == FAILURE)
	return (NULL);
      else if (info->file[i][0] == '#' && info->file[i][1] != '#')
	i++;
      else
	{
	  if ((check_other(info, new_tab, &i, &x)) != SUCCESS)
	    return (NULL);
	}
    }
  if (pipe == 0)return (NULL);
  return (new_tab);
}

int	check_other(t_info *info, char ** new_tab, int *i, int *x)
{
  static int	boole = 0;

  if (my_strcmp("##start", info->file[*i]) == 0 ||
	   my_strcmp("##end", info->file[*i]) == 0)
    {
      if (check_after_end_start(info->file[*i + 1]) != 0)
	return (FAILURE);
      if (((my_strcmp("##end", info->file[*i])) == 0) && boole == 0)
	return (FAILURE);
      if ((my_strcmp("##start", info->file[*i])) == 0)
	boole++;
      new_tab[*x] = my_strdup(info->file[*i]);
      *x = *x + 1;
      *i = *i + 1;
    }
  else
    {
      if ((else_again(info, new_tab, i, x)) != 0)
	return (FAILURE);
    }
  return (SUCCESS);
}

int	else_again(t_info *info, char ** new_tab, int *i, int *x)
{
  static int	finish = 0;

  if (info->file[*i][1] != '-' && *i != 0)
    {
      if ((check_room(info->file[*i])) != 0)
	return (FAILURE);
      finish++;
    }
  if ((my_strcmp("cookie", info->file[*i])) == 0)
    return (FAILURE);
  check_comment(info->file, new_tab, *i, *x);
  *x = *x + 1;
  *i = *i + 1;
  if (info->file[*i + 1] == NULL && finish == 0)
    {
      return (FAILURE);
    }
  return (0);
}
