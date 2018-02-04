/*
** game.c for game in /home/ferlet_n/colle/CPE_2016_stumper2
** 
** Made by Nicolas Ferlet
** Login   <ferlet_n@epitech.net>
** 
** Started on  Tue Apr 25 08:04:06 2017 Nicolas Ferlet
** Last update Tue Apr 25 10:44:16 2017 Nicolas Ferlet
*/

#include "my.h"

void	print_first_last(t_param *param)
{
  int	i;

  i = 0;
  my_putchar('+');
  while (i != param->width)
    {
      my_putchar('-');
      i = i + 1;
    }
  my_putchar('+');
  my_putchar('\n');
}

void	print_the_tab(char **tab, t_param *param)
{
  int	j;
  int	i;

  j = 0;
  print_first_last(param);
  while (j != param->height)
    {
      i = 0;
      my_putchar('|');
      while (i != param->width)
	{
	  my_putchar(tab[j][i]);
	  i = i + 1;
	}
      my_putchar('|');
      my_putchar('\n');
      j = j + 1;
    }
  print_first_last(param);
}

int	get_entry(t_param *param, int turn, char **tab)
{
  int	nb;
  char	*str;

  nb = -1;
  while (nb == -1)
    {
      my_putstr("Player ");
      if (turn == 0)
	my_putchar(param->avatar1);
      else
	my_putchar(param->avatar2);
      my_putstr(", where do you want to play: ");
      if ((str = get_next_line(0)) == NULL)
	return (-1);
      nb = my_getnbr(str);
      if (nb < 1 || nb > param->width)
	nb = -1;
      else if (nb > 0 && tab[0][nb - 1] != ' ')
	nb = -1;
      free(str);
    }
  return (nb);
}

int	game(t_param *param, char **tab)
{
  int	turn;
  int	nb;
  int	display;
  int	check;

  turn = 0;
  check = 0;
  display = 0;
  while ((check = check_winner(tab, param)) == 0 && full_map(tab) == 0)
    {
      if (display == 1)
	print_the_tab(tab, param);
      display = 1;
      if ((nb = get_entry(param, turn, tab)) == -1)
	return (-1);
      put_in_tab(tab, turn, *param, nb);
      turn = (turn + 1) % 2;
    }
  print_the_tab(tab, param);
  return (check);
}
