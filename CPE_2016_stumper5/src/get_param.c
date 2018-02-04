/*
** get_param.c for get_param.c in /home/lecherbonnier/Projet/CPE_2016_stumper5/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri May 19 13:18:04 2017 Leo Lecherbonnier
** Last update Jun May 19 14:23:34 2017
*/

#include "my.h"

t_param		*init_param()
{
  t_param	*param;

  if ((param = malloc(sizeof(t_param) * 1)) == NULL)
    return (NULL);
  param->number = -1;
  param->str_number = NULL;
  param->swag = NULL;
  return (param);
}

t_param		*get_param(char **av)
{
  t_param	*param;
  int		i;
  int		boole;

  i = 0;
  boole = 0;
  if ((param = init_param()) == NULL)
    return (NULL);
  while (av[i])
    {
      if (my_strcmp(av[i], "-n") == 0 && av[i + 1] != NULL
	  && my_str_is_num(av[i + 1]) == 0)
	{
	  param->number = my_getnbr(av[i + 1]);
	  param->str_number = av[i + 1];
	  boole += 10;
	}
      else if (my_strcmp(av[i], "-s") == 0 && av[i + 1] != NULL)
	{
	  param->swag = av[i + 1];
	  boole += 1;
	}
      i++;
    }
  return (check_before_return(param, boole));
}

t_param	*check_before_return(t_param *param, int boole)
{
  if (param->number < 0)
    return (NULL);
  if (boole > 11 && boole < 10)
    return (NULL);
  return (param);
}
