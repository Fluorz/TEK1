/*
** get_file.c for get_file.c in /home/lecherbonnier/Projet/CPE_2016_Lemin/leo/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Apr 24 11:43:22 2017 Leo Lecherbonnier
** Last update Jan Apr 30 21:02:13 2017
*/

#include "open_file.h"

t_info	*get_file()
{
  char		*str;
  t_info	*info;
  int		j = 0;

  if ((info = malloc(sizeof(t_info))) == NULL)
    return (NULL);
  if ((info->file = malloc(sizeof(char *) * SIZE_MALLOC)) == NULL)
    return (NULL);
  while ((str = get_next_line(0)))
    {
      if (j >= SIZE_MALLOC - 100)
	return (NULL);
      info->file[j++] = my_strdup(str);
    }
  return (info);
}
