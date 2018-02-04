/*
** epure_tab.c for epure_tab.c in /home/lecherbonnier/Projet/CPE_2016_Lemin/leo/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Apr 24 11:54:01 2017 Leo Lecherbonnier
** Last update Jan Apr 30 18:25:50 2017
*/

#include "open_file.h"

char	**bad_epure(t_info	*info)
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
	return (NULL);
      else if (fcheck_bad_caracter(info->file[i]) == FAILURE)
	return (NULL);
      else if (info->file[i][0] == '#' && info->file[i][1] != '#')
	i++;
      else
	fcheck_other(info, new_tab, &i, &x);
    }
  return (new_tab);
}

int	fcheck_other(t_info *info, char ** new_tab, int *i, int *x)
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
      fcheck_comment(info->file, new_tab, *i, *x);
      *x = *x + 1;
      *i = *i + 1;
    }
  return (SUCCESS);
}

int	fcheck_bad_caracter(char *str)
{
  int	boole = 0;
  int	i = 0;

  while (str[i] != '\0')
    {
      if (str[i] >= '0' && str[i] <= '9')
	boole = 0;
      else if (str[i] >= 'a' && str[i] <= 'z')
	boole = 0;
      else if (str[i] >= 'A' && str[i] <= 'Z')
	boole = 0;
      else if (str[i] == '-' || str[i] == '#' || str[i] == ' '
	       || str[i] == '\n')
	boole = 0;
      else
	boole = 1;
      if (boole != 0)
	  return (FAILURE);
      i++;
    }
  return (SUCCESS);
}

int	fcheck_comment(char **file, char **new_tab, int i, int x)
{
  int	j = 0;

  if ((new_tab[x] = malloc(sizeof(char) * my_strlen(file[i]))) == NULL)
       return (1);
  while (file[i][j] != '#' && file[i][j] != '\0')
    {
      new_tab[x][j] = file[i][j];
      j++;
    }
  j = 0;
  while (new_tab[x][j])
    {
      if (new_tab[x][j] >= '0' && new_tab[x][j] <= '9')
	j++;
      else if (new_tab[x][j] == ' ' && new_tab[x][j + 1] == '\0')
	{
	  new_tab[x][j] = '\0';
	  break;
	}
      else
	j++;
    }
  return (0);
}
