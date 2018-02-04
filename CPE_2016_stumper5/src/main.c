/*
** main.c for main.c in /home/lecherbonnier/Projet/CPE_2016_stumper5/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri May 19 13:16:39 2017 Leo Lecherbonnier
** Last update Fri May 19 16:27:56 2017 Monty Criel
*/

#include "my.h"

void	free_param(t_param *param)
{
  free(param);
}

int	main(int ac, char **av)
{
  t_param	*param;

  if (ac < 3)
    return (84);
  if ((param = get_param(av)) == NULL)
    return (84);
  if (print_number(param->str_number, param->swag) != 0)
    return (84);
  free_param(param);
  return (0);
}
