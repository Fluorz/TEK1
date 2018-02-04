/*
** main.c for main in /home/ferlet_n/colle/CPE_2016_stumper2
** 
** Made by Nicolas Ferlet
** Login   <ferlet_n@epitech.net>
** 
** Started on  Tue Apr 25 07:12:07 2017 Nicolas Ferlet
** Last update Tue Apr 25 10:42:43 2017 Nicolas Ferlet
*/

#include "my.h"

void		print_end(int keep, t_param *param)
{
  if (keep == 0)
    my_putstr("It's a tie, nobody wins.\n");
  else if (keep == 1)
    {
      my_putstr("Congrats, player ");
      my_putchar(param->avatar1);
      my_putstr(" won!\n");
    }
  else if (keep == 2)
    {
      my_putstr("Congrats, player ");
      my_putchar(param->avatar2);
      my_putstr(" won!\n");
    }
}

int		main(int argc, char **argv)
{
  t_param	param;
  char		**tab;
  int		keep;

  init_param(&param);
  if (get_param(&param, argv + 1) == 84)
    return (84);
  if (check_param(&param) == 84)
    return (84);
  tab = create_bord(param);
  tab = put_space(tab, param);
  keep = game(&param, tab);
  print_end(keep, &param);
  (void)argc;
  return (0);
}
