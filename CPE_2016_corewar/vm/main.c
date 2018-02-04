/*
** test.c for test.c in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sat Mar 11 11:58:29 2017 Leo Lecherbonnier
** Last update Sun Apr  2 18:10:38 2017 Leo Lecherbonnier
*/

#include "vm.h"

void		print_arena(char *str, int len)
{
  int		i = -1;

  while (++i < len)
    my_putchar(map[i]);
  my_putchar('\n');
}

int		main(int ac, char **av)
{
  t_champ	*ch = NULL;
  t_arena	arena;
  t_option option;

  if (ac < 2 || ac > 5)
    return (84);
  if (my_strcmp(av[1], "-h") == 0)
    print_help();
  if (get_option(av, &option) == FAILURE)
    return (84);
  if ((ch = put_champs(ch, &av[1], ac)) == NULL)
    return (84);
  if ((ch = init_else_champ(ch)) == NULL)
    return (84);
  arena = init_arena(ac, ch);
  start_battle(ch, arena, option);
  return (0);
}
