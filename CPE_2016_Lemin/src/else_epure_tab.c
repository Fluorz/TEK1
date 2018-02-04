/*
** else_epure_tab.c for else_epure_tab.c in /home/lecherbonnier/Projet/CPE_2016_Lemin/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri Apr 28 18:32:58 2017 Leo Lecherbonnier
** Last update Jan Apr 30 09:54:06 2017
*/

#include "open_file.h"

int	check_after_end_start(char *str)
{
  char **tab;

  tab = my_str_to_wordtab(str, ' ');
  if (tab[0] == NULL || tab[1] == NULL || tab[2] == NULL)
    return (FAILURE);
  if ((my_str_isnum(tab[1])) != 0)
    return (FAILURE);
  if ((my_str_isnum(tab[2])) != 0)
    return (FAILURE);
  return (0);
}

int	check_room(char *str)
{
  char **tab;

  tab = my_str_to_wordtab(str, ' ');
  if (tab[0] == NULL || tab[1] == NULL || tab[2] == NULL)
    {
      return (FAILURE);
    }
  if ((my_str_isnum(tab[1])) != 0)
    return (FAILURE);
  if ((my_str_isnum(tab[2])) != 0)
    return (FAILURE);
  return (0);
}

int	check_bad_caracter(char *str)
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

int	check_comment(char **file, char **new_tab, int i, int x)
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
