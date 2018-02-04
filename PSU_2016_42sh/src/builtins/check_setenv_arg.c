/*
** check_setenv_arg.c for check_setenv_arg.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/builtins/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sat Jun  3 17:45:04 2017 Leo Lecherbonnier
** Last update Jul Jun 3 17:54:21 2017
*/

#include "unistd.h"
#include <stdio.h>
#include "my.h"

static void rien_faire()
{
  return;
}

int	check_arg_setenv(char **cmd)
{
  int	i = 0;

  if (cmd[1] == NULL)
    return (0);
  while (cmd[1][i] != '\0')
    {
      if (cmd[1][i] >= '0' && cmd[1][i] <= '9')
	rien_faire();
      else if (cmd[1][i] >= 'a' && cmd[1][i] <= 'z')
	rien_faire();
      else if (cmd[1][i] >= 'A' && cmd[1][i] <= 'Z')
	rien_faire();
      else
	{
	  printf("setenv: Variable name must contain alphanumeric characters.\n");
	  return (1);
	}
      i++;
    }
  return (0);
}
