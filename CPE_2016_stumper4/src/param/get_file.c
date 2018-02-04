/*
** get_file.c for get_file in /home/ferlet_n/colle/CPE_2016_stumper4/src/param
** 
** Made by Nicolas Ferlet
** Login   <ferlet_n@epitech.net>
** 
** Started on  Tue May  9 07:50:58 2017 Nicolas Ferlet
** Last update Tue May  9 08:49:26 2017 Nicolas Ferlet
*/

#include "my.h"

char	**increase_size(char **tab, char *str, int size)
{
  char	**new;
  int	i;

  if (!(new = malloc(sizeof(char *) * (size + 2))))
    return (NULL);
  i = 0;
  while (tab[i] != NULL)
    {
      new[i] = tab[i];
      i = i + 1;
    }
  new[i] = str;
  new[i + 1] = NULL;
  free(tab);
  return (new);
}

char	**get_file(char *file)
{
  char	**new;
  int	fd;
  char	*str;
  int	i;

  fd = open(file, O_RDONLY);
  if (!(new = malloc(sizeof(char *) * 1)))
    return (NULL);
  new[0] = NULL;
  i = 0;
  while ((str = my_get_next_line(fd)))
    {
      if (!(new = increase_size(new, str, i)))
	return (NULL);
      i = i + 1;
    }
  close(fd);
  return (new);
}

int	my_strlen_check(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != '*' && str[i] != '.')
	return (-1);
      i = i + 1;
    }
  return (i);
}

int	check_tab(char **tab)
{
  int	i;
  int	nb1;
  int	nb2;

  i = 0;
  while (tab[i] != NULL && tab[i + 1] != NULL)
    {
      nb1 = my_strlen_check(tab[i]);
      nb2 = my_strlen_check(tab[i + 1]);
      if (nb1 == -1 || nb2 == -1)
	return (my_error("Bad character in file\n", 84));
      if (nb1 != nb2)
	return (my_error("Lines of different sizes\n", 84));
      i = i + 1;
    }
  return (0);
}
