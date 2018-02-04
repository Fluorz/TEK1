/*
** main.c for main.c in /home/lecherbonnier/Projet/CPE_2016_stumper3/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue May  2 10:47:30 2017 Leo Lecherbonnier
** Last update Tue May  2 11:04:35 2017 Nicolas Ferlet
*/

#include "my.h"

void		init_param(t_param *param)
{
  param->file = NULL;
  param->size = 8;
}

char		**build_the_tab(t_param *param)
{
  char		**new;
  int		i;
  int		j;

  if (!(new = malloc(sizeof(char *) * (param->size + 1))))
    return (NULL);
  i = 0;
  while (i != param->size)
    {
      j = 0;
      if (!(new[i] = malloc(sizeof(char) * (param->size + 1))))
	return (NULL);
      while (j != param->size)
	{
	  new[i][j] = ' ';
	  j = j + 1;
	}
      new[i][j] = '\0';
      i = i + 1;
    }
  new[i] = NULL;
  return (new);
}

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

void		put_end_phrase(t_all_word *data)
{
  my_put_nbr(data->found);
  my_putchar('/');
  my_put_nbr(data->total);
  my_putstr(" words inserted in the grid.\n");
}

int		main(int argc, char **argv)
{
  t_param	param;
  t_all_word	data;
  char		**tab;

  init_param(&param);
  if (get_param(&param, argv + 1) == -1)
    return (my_error("Bad Parameters\n", 84));
  if (get_database(&data, &param) == -1)
    return (my_error("File either can't be openned or \
has a bad character in it or has a too long word\n", 84));
  if ((tab = build_the_tab(&param)) == NULL)
    return (my_error("Malloc Fail\n", 84));
  fill_tab(tab);
  find_word(tab, &data);
  put_end_phrase(&data);
  print_tab(tab);
  free_tab(tab);
  while (data.list != NULL)
    remove_one(&(data.list), &(data.list));
  (void)argc;
  return (0);
}
