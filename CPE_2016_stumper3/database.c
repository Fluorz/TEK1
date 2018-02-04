/*
** database.c for database in /home/ferlet_n/colle/CPE_2016_stumper3
** 
** Made by Nicolas Ferlet
** Login   <ferlet_n@epitech.net>
** 
** Started on  Tue May  2 08:00:43 2017 Nicolas Ferlet
** Last update Tue May  2 10:39:09 2017 Nicolas Ferlet
*/

#include "my.h"

int	check_str(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] < 'a' || str[i] > 'z')
	return (-1);
      i = i + 1;
    }
  str[i] = '\0';
  return (0);
}

int		check_len(t_all_word *data, t_param *param)
{
  t_word	*beg;

  beg = data->list;
  while (data->list != NULL)
    {
      if (my_strlen(data->list->str) > param->size)
	return (-1);
      data->list = data->list->next;
    }
  data->list = beg;
  return (0);
}

int	get_database(t_all_word *data, t_param *param)
{
  int	fd;
  char	*str;

  data->list = NULL;
  data->found = 0;
  data->total = 0;
  if ((fd = open(param->file, O_RDONLY)) < 0)
    return (-1);
  while ((str = get_next_line(fd)) != NULL)
    {
      if (check_str(str) == -1)
	return (-1);
      data->total += 1;
      add_node(&(data->list), str);
    }
  close(fd);
  return (check_len(data, param));
}
