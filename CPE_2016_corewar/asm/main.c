/*
** main.c for corewar in /home/monty/Documents/Rendu/corewar/CPE_2016_corewar/ASM/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sun Apr  2 23:01:41 2017 Monty Criel
** Last update Sun Apr  2 23:51:15 2017 Sid
*/

#include "asm.h"
#include "error.h"

int		main(int ac, char **av)
{
  t_error	error;

  if (ac == 2 && (my_strcmp(av[1], "-h") == 0))
    {
      display_help(av[0]);
      return (0);
    }
  else if (ac != 2)
    {
      display_help(av[0]);
      return (84);
    }
  error = error_handling(error, av);
  if (my_asm(ac, av) != 0)
    return (84);
  return (0);
}
