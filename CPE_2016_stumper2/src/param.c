/*
** param.c for param in /home/ferlet_n/colle/CPE_2016_stumper2
** 
** Made by Nicolas Ferlet
** Login   <ferlet_n@epitech.net>
** 
** Started on  Tue Apr 25 07:15:00 2017 Nicolas Ferlet
** Last update Tue Apr 25 07:56:57 2017 Nicolas Ferlet
*/

#include "my.h"

void	init_param(t_param *param)
{
  param->width = 7;
  param->height = 6;
  param->avatar1 = 'X';
  param->avatar2 = 'O';
  param->referee = '#';
}

int	get_param(t_param *param, char **argv)
{
  int	i;
  int	error;

  i = 0;
  error = 0;
  while (argv[i] != NULL)
    {
      if (my_strcmp(argv[i], "-w") == 1)
	error = get_width(param, argv, &i);
      else if (my_strcmp(argv[i], "-h") == 1)
      error = get_height(param, argv, &i);
      else if (my_strcmp(argv[i], "-p1") == 1)
	error = get_avatar1(param, argv, &i);
      else if (my_strcmp(argv[i], "-p2") == 1)
	error = get_avatar2(param, argv, &i);
      else if (my_strcmp(argv[i], "-a") == 1)
	error = get_referee(param, argv, &i);
      else
	return (my_error("Bad Parameters\n", 84));
      if (error == -1)
	return (my_error("Bad Parameters\n", 84));
      i = i + 1;
    }
  return (0);
}

int	check_param(t_param *param)
{
  if (param->avatar1 == param->avatar2 ||
      param->avatar2 == param->referee ||
      param->referee == param->avatar1)
    return (my_error("Avatar and/or referee must not be similar\n",
		     84));
  else if (param->width * param->height < 20)
    return (my_error("Not enough slots\n", 84));
  return (0);
}
