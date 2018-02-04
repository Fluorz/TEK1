/*
** param.c for param in /home/ferlet_n/colle/CPE_2016_stumper3
** 
** Made by Nicolas Ferlet
** Login   <ferlet_n@epitech.net>
** 
** Started on  Tue May  2 07:30:03 2017 Nicolas Ferlet
** Last update Tue May  2 07:51:35 2017 Nicolas Ferlet
*/

#include "my.h"

int	get_the_file(t_param *param, char **argv, int *i)
{
  *i = *i + 1;
  param->file = argv[*i];
  if (argv[*i] == NULL)
    return (-1);
  return (0);
}

int	get_the_size(t_param *param, char **argv, int *i)
{
  *i = *i + 1;
  if (argv[*i] == NULL)
    return (-1);
  if ((param->size = my_get_nbr(argv[*i])) <= 0)
    return (-1);
  return (0);
}

int	get_param(t_param *param, char **argv)
{
  int	i;
  int	error;

  i = 0;
  while (argv[i] != NULL)
    {
      error = 0;
      if (my_strcmp(argv[i], "-f") == 1)
	error = get_the_file(param, argv, &i);
      else if (my_strcmp(argv[i], "-s") == 1)
	error = get_the_size(param, argv, &i);
      else
	return (-1);
      if (error == -1)
	return (-1);
      i = i + 1;
    }
  if (param->file == NULL)
    return (-1);
  return (0);
}
