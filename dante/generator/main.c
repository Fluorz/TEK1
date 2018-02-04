/*
** main.c for main in /home/hugo/cours/Code/Semestre 2/Initiation IA/dante/generator/
**
** Made by Hugo Bleuzen
** Login   <hugo.bleuzen@epitech.eu>
**
** Started on  Fri Apr 28 13:39:16 2017 Hugo Bleuzen
** Last update Jul May 13 15:27:38 2017
*/

#include "generator.h"

int	main(int ac, char **av)
{
  t_args       args;

  srand(getpid() * time(NULL));
  if (ac < 3 || ac > 4)
    return (84);
  if (av[3] == NULL)
    av[3] = "imperfect";
  if (init_args(&args, (av[1]), (av[2]), av[3]) != 0)
    return (84);
  if ((create_maze(&args)) != 0)
    return (84);
  print_maze(&args);
  return (0);
}
