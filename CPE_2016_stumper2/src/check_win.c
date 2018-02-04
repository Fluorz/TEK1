/*
** check_win.c for check_win in /home/ferlet_n/colle/CPE_2016_stumper2
** 
** Made by Nicolas Ferlet
** Login   <ferlet_n@epitech.net>
** 
** Started on  Tue Apr 25 09:41:31 2017 Nicolas Ferlet
** Last update Tue Apr 25 10:38:40 2017 Nicolas Ferlet
*/

#include "my.h"

int	recur(char **tab, t_param *param, t_pos pos, char init)
{
  if (pos.x + pos.dec_x >= 0 &&
      pos.x + pos.dec_x < param->width &&
      pos.y + pos.dec_y >= 0 &&
      pos.y + pos.dec_y < param->height &&
      tab[pos.y + pos.dec_y][pos.x + pos.dec_x] == init)
    {
      if (pos.nb == 3)
	return (1);
      else
	return (recur(tab, param, (t_pos){pos.x + pos.dec_x,
		pos.y + pos.dec_y, pos.dec_x, pos.dec_y, pos.nb + 1},
	    init));
    }
  return (-1);
}

t_pos	check_all(char **tab, t_param *param, int i, int j)
{
  if (recur(tab, param, (t_pos){i, j, 1, 0, 1}, tab[j][i]) == 1)
    return ((t_pos){i, j, 1, 0, 0});
  if (recur(tab, param, (t_pos){i, j, -1, 0, 1}, tab[j][i]) == 1)
    return ((t_pos){i, j, -1, 0, 0});
  if (recur(tab, param, (t_pos){i, j, 0, 1, 1}, tab[j][i]) == 1)
    return ((t_pos){i, j, 0, 1, 0});
  if (recur(tab, param, (t_pos){i, j, 0, -1, 1}, tab[j][i]) == 1)
    return ((t_pos){i, j, 0, -1, 0});
  if (recur(tab, param, (t_pos){i, j, 1, 1, 1}, tab[j][i]) == 1)
    return ((t_pos){i, j, 1, 1, 0});
  if (recur(tab, param, (t_pos){i, j, 1, -1, 1}, tab[j][i]) == 1)
    return ((t_pos){i, j, 1, -1, 0});
  if (recur(tab, param, (t_pos){i, j, -1, 1, 1}, tab[j][i]) == 1)
    return ((t_pos){i, j, -1, 1, 0});
  if (recur(tab, param, (t_pos){i, j, -1, -1, 1}, tab[j][i]) == 1)
    return ((t_pos){i, j, -1, -1, 0});
  return ((t_pos){-1, -1, -1, -1, -1});
}

int		fill_it(char **tab, t_coord coord, t_pos pos, t_param *param)
{
  int		nb;
  char		need;

  nb = 0;
  need = tab[coord.j][coord.i];
  tab[coord.j][coord.i] = param->referee;
  while (nb != 3)
    {
      coord.j += pos.dec_y;
      coord.i += pos.dec_x;
      tab[coord.j][coord.i] = param->referee;
      nb = nb + 1;
    }
  return (need == param->avatar1 ? 1 :
	  need == param->avatar2 ? 2 :
	  0);
}

int		check_winner(char **tab, t_param *param)
{
  int		i;
  int		j;
  t_pos		keep;

  j = 0;
  while (j != param->height)
    {
      i = 0;
      while (i != param->width)
	{
	  if (tab[j][i] != ' ' &&
	      (keep = check_all(tab, param, i, j)).x != -1)
	    return (fill_it(tab, (t_coord){i, j}, keep, param));
	  i = i + 1;
	}
      j = j + 1;
    }
  return (0);
}
