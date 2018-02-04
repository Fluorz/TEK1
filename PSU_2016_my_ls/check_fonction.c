/*
** check_fonction.c for check_fonction.c in /root/Desktop/PSU_2016_my_ls/lib/my/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Tue Nov 29 18:08:43 2016 Leo Lecherbonnier
** Last update Sun Dec  4 17:19:54 2016 Leo Lecherbonnier
*/

#include "ls.h"

int	get_option(char *av)
{
  if (av[1] == 'R')
    return (2);
  if (av[1] == 'l')
    return (1);
  else
    exit (-1);
}

int	do_option(char *path, int option)
{
  if (option == 0)
    check_repo(path);
  if (option == 1)
    {
      if (path == NULL)
	{
	  check_l_repo("./");
	  return (0);
	}
      check_l_repo(path);
      return (0);
    }
  if (option == 2)
    {
      if (path == NULL)
	{
	  my_ls("./");
	  exit(0);
	}
      my_ls(path);
    }
  if (option == 3)
    {
      return (0);
    }
}

int	check_option(int ac, char **av)
{
  int	i;
  int	option;
  char	*path;

  i = 1;
  option = 0;
  while (i < ac)
    {
      if (av[i][0] == '-')
	{
	  option = option + get_option(av[i]);
	  i++;
	}
      else
	{
	  path = malloc(sizeof(char) * (ac + 1));
	  my_strcpy(path, av[i]);
          i++;
	}
    }
  do_option(path, option);
  return (0);
}
