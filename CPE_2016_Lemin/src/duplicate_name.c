/*
** duplicate_name.c for duplicate_name.c in /home/lecherbonnier/Projet/TMP_SUN/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sun Apr 30 20:17:10 2017 Leo Lecherbonnier
** Last update Jan Apr 30 22:52:57 2017
*/

#include "open_file.h"

int	check_room_and_co(char **tab)
{
  char	**name;
  char	**new_tab;
  int	i = 0;
  int	j = 0;

  if ((name = malloc(sizeof(char *) * obtain_index(tab) + 5)) == NULL)
    return (FAILURE);
  i = 0;
  while (i != (obtain_index(tab)) && tab[i])
    {
      new_tab = my_str_to_wordtab(tab[i], ' ');
      name[j] = my_strdup(new_tab[0]);
      j++;
      i++;
    }
  if (name[j] != NULL)
    name[j + 1] = NULL;
  if ((check_name(name)) != SUCCESS)
    return (FAILURE);
  if ((check_connection(name, tab)) != SUCCESS)
    return (FAILURE);
  return (SUCCESS);
}

int	check_name(char **name)
{
  int	i = 0;
  int	j = 0;
  while (name[i])
    {
      j = 0;
      while (name[j])
	{
	  if (i == j)
	    j++;
	  else if ((my_strcmp(name[i], name[j])) == 0)
	    return (FAILURE);
	  else
	    j++;
	}
      i++;
    }
  return (SUCCESS);
}

int	obtain_index(char **file)
{
  int	i;
  int	j = 0;

  i = 0;
  while (file[i])
    {
      j = 0;
      while (file[i][j] != '\0')
	{
	  if (file[i][j] == '-')
	    return (i);
	  j++;
	}
      i++;
    }
  return (0);
}

int	check_connection(char **name, char **file)
{
  char	**tab;
  int	i = 0;
  int	x = 0;
  int	tmp;
  int	boole = 0;

  tmp = i = obtain_index(file);
  while (name[x])
    {
      i = tmp;
      boole = 0;
      while (file[i] != NULL && boole == 0)
	{
	  tab = my_str_to_wordtab(file[i], '-');
	  if ((my_strcmp(name[x], tab[0])) == 0 ||
	      ((my_strcmp(name[x], tab[1]) == 0)))
	      boole = 1;
	  i++;
	}
      if (boole == 0)
	return (FAILURE);
      x++;
    }
  return (SUCCESS);
}
