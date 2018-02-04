/*
** get_param.c for get_param in /home/ferlet_n/colle/CPE_2016_stumper2
** 
** Made by Nicolas Ferlet
** Login   <ferlet_n@epitech.net>
** 
** Started on  Tue Apr 25 07:33:14 2017 Nicolas Ferlet
** Last update Tue Apr 25 07:46:56 2017 Nicolas Ferlet
*/

#include "my.h"

int	get_width(t_param *param, char **argv, int *i)
{
  *i = *i + 1;
  if ((param->width = my_getnbr(argv[*i])) == -1 ||
      param->width > 80)
    return (-1);
  return (0);
}

int	get_height(t_param *param, char **argv, int *i)
{
  *i = *i + 1;
  if ((param->height = my_getnbr(argv[*i])) == -1 ||
      param->height > 16)
    return (-1);
  return (0);
}

int	get_avatar1(t_param *param, char **argv, int *i)
{
  *i = *i + 1;
  if (my_strlen(argv[*i]) != 1)
    return (-1);
  param->avatar1 = argv[*i][0];
  return (0);
}

int	get_avatar2(t_param *param, char **argv, int *i)
{
  *i = *i + 1;
  if (my_strlen(argv[*i]) != 1)
    return (-1);
  param->avatar2 = argv[*i][0];
  return (0);
}

int	get_referee(t_param *param, char **argv, int *i)
{
  *i = *i + 1;
  if (my_strlen(argv[*i]) != 1)
    return (-1);
  param->referee = argv[*i][0];
  return (0);
}
