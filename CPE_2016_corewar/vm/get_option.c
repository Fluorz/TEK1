/*
** get_option.c for get_option.c in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sun Mar 12 16:05:30 2017 Leo Lecherbonnier
** Last update Sun Apr  2 17:59:10 2017 Leo Lecherbonnier
*/

#include "vm.h"

/*
init_option
*/

t_option	init_option()
{
  t_option option;

  option.dump = 1000;
  option.prog_number = FALSE;
  option.load_address = FALSE;
  return (option);
}

/*
handler des parametre
*/

int	get_option(char **av, t_option *option)
{
  int	i = 0;

  *option = init_option();
  while (av[i])
    {
      if (av[i + 1] != NULL)
	{
	  if (my_strcmp(av[i], "-dump") == 0)
	    option->dump = my_getnbr(av[i + 1]);
	  if (my_strcmp(av[i], "-n") == 0)
	    option->prog_number = my_getnbr(av[i + 1]);
	  if (my_strcmp(av[i], "-a") == 0)
	    option->load_address = my_getnbr(av[i + 1]);
	}
	  i++;
	}
  return (SUCCESS);
}
