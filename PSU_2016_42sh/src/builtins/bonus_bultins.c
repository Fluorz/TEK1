/*
** bonus_bultins.c for builtins_bonus.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/builtins/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Sat Jun  3 19:59:04 2017 Leo Lecherbonnier
** Last update Thu Jun  8 17:31:53 2017 Sid Djilali Saiah
*/

#include "my_exec.h"

int	check_bonus_builtins(char **cmd, char **env)
{
  if (strcmp(cmd[0], "exit") == 0)
    my_exit(cmd);
  else if (strcmp(cmd[0], "echo") == 0)
    my_echo(cmd);
  else if (strcmp(cmd[0], "where") == 0)
    {
      if (cmd[1] == NULL)
	{
	  printf("%s: Too few arguments.\n", cmd[0]);
	  return (1);
	}
      return (where(cmd, env));
    }
  else if (strcmp(cmd[0], "which") == 0)
    {
      if (cmd[1] == NULL)
	{
	  printf("%s: Too few arguments.\n", cmd[0]);
	  return (1);
	}
      return (which(cmd, env));
    }
  else return (1);
  return (0);
}

void	my_exit(char **cmd)
{
  printf("exit\n");
  if (cmd[1] == NULL)
    exit (0);
  exit (atoi(cmd[1]));
}

void	my_echo(char **cmd)
{
  int	i;

  i = 1;
  if (cmd[1] == NULL)
    printf("\n");
  else if (cmd[2] != NULL && strcmp(cmd[1], "-n") == 0)
    printf("%s", cmd[2]);
  else if (cmd[2] != NULL && strcmp(cmd[1], "-n") != 0)
    {
      while (cmd[i])
	{
	  if (cmd[i + 1] != NULL)
	    printf("%s ", cmd[i]);
	  else
	    printf("%s", cmd[i]);
	  i++;
	}
      printf("\n");
    }
  else if (cmd[2] == NULL)
    printf("%s\n", cmd[1]);
}
