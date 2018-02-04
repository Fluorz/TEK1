/*
** param.c for param in /home/ferlet_n/colle/CPE_2016_stumper4/src/param
** 
** Made by Nicolas Ferlet
** Login   <ferlet_n@epitech.net>
** 
** Started on  Tue May  9 07:21:17 2017 Nicolas Ferlet
** Last update Tue May  9 07:50:46 2017 Nicolas Ferlet
*/

#include "my.h"

int	check_file(char *file)
{
  int	fd;

  if ((fd = open(file, O_RDONLY)) < 0)
    return (my_error("Can't open the file\n", 84));
  close(fd);
  return (0);
}

int	get_param(t_param *param, char **argv)
{
  if (argv[1] == NULL || argv[2] == NULL)
    return (my_error("Wrong number of parameters, need 2.\n", 84));
  param->file = argv[1];
  if ((param->nb = my_get_nbr(argv[2])) == -1)
    return (my_error("Bad parameters, 2nd arg must be >= 0\n", 84));
  return (0);
}
