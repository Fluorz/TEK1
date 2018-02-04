/*
** main.c for main.c in /home/lecherbonnier/Projet/CPE_2016_stumper4/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue May  9 11:16:29 2017 Leo Lecherbonnier
** Last update Mar May 9 12:28:50 2017
*/

#include "my.h"

char		get_new_one(char **tab, int j, int i, int nb)
{
  if (j - 1 >= 0 && tab[j - 1][i] == '*')
    nb = nb + 1;
  if (j - 1 >= 0 && tab[j - 1][i + 1] == '*')
    nb = nb + 1;
  if (tab[j][i + 1] == '*')
    nb = nb + 1;
  if (tab[j + 1] != NULL && tab[j + 1][i + 1] == '*')
    nb = nb + 1;
  if (tab[j + 1] != NULL && tab[j + 1][i] == '*')
    nb = nb + 1;
  if (tab[j + 1] != NULL && i - 1 >= 0 && tab[j + 1][i - 1] == '*')
    nb = nb + 1;
  if (i - 1 >= 0 && tab[j][i - 1] == '*')
    nb = nb + 1;
  if (j - 1 >= 0 && i - 1 >= 0 && tab[j - 1][i - 1] == '*')
    nb = nb + 1;
  if (tab[j][i] == '.' && nb == 3)
    return ('*');
  else if (nb == 0 || nb == 1)
    return ('.');
  else if (nb >= 4)
    return ('.');
  return (tab[j][i]);
}

char		**one_iter(char **tab, int size, int i, int j)
{
  char		**new;

  if (!(new = malloc(sizeof(char *) * (my_tablen(tab) + 1))))
    return (NULL);
  while (tab[i] != NULL)
    {
      if (!(new[i] = malloc(sizeof(char) * (size + 1))))
	return (NULL);
      i = i + 1;
    }
  new[i] = NULL;
  while (tab[j] != NULL)
    {
      i = 0;
      while (tab[j][i] != '\0')
	{
	  new[j][i] = get_new_one(tab, j, i, 0);
	  i = i + 1;
	}
      new[j][i] = '\0';
      j = j + 1;
    }
  free_tab(tab);
  return (new);
}

void		game_of_life(t_param *param)
{
  int		i;

  i = 0;
  if (param->tab[0] == NULL)
    return ;
  while (i != param->nb)
    {
      if (!(param->tab = one_iter(param->tab,
				  my_strlen(param->tab[0]), 0, 0)))
	{
	  my_error("Malloc Fail\n", 84);
	  return ;
	}
      i = i + 1;
    }
  i = 0;
  while (param->tab[i] != NULL)
    {
      my_putstr(param->tab[i]);
      my_putchar('\n');
      i = i + 1;
    }
  free_tab(param->tab);
}

int		main(int argc, char **argv)
{
  t_param	param;

  if (get_param(&param, argv) == 84)
    return (84);
  if (check_file(param.file) == 84)
    return (84);
  if ((param.tab = get_file(param.file)) == NULL)
    return (my_error("Malloc Fail.\n", 84));
  if (check_tab(param.tab) == 84)
    return (84);
  game_of_life(&param);
  (void)argc;
  return (0);
}
