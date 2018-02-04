/*
** env_tools.c for 42sh in /home/monty/Documents/Rendu/minishell/PSU_2016_42sh/src/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Wed May 31 11:58:24 2017 Monty Criel
** Last update Fri Jun  2 22:45:42 2017 Monty Criel
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char	*copy_env_var(char *str)
{
  int	i;
  int	x;
  int	len;
  char	*var;

  i = 0;
  while (str[i++] != '=');
  len = strlen(str) - (i + 1);
  var = malloc(sizeof(char) * (len + 2));
  if (var == NULL)
    exit(84);
  x = 0;
  while (str[i] != '\0')
    {
      var[x] = str[i];
      x += 1;
      i += 1;
    }
  var[x] = '\0';
  return (var);
}

char	*get_env_var(char **env, char *str)
{
  int	y;
  int	x;
  char	*var;

  y = 0;
  while (env[y] != NULL)
    {
      x = 0;
      while (env[y][x++] != '=');
      if ((var = malloc(sizeof(char) * (x + 1))) == NULL)
	exit(84);
      strncpy(var, env[y], x - 1);
      var[x - 1] = '\0';
      if (strcmp(str, var) == 0)
	{
	  free(var);
	  var = copy_env_var(env[y]);
	  return (var);
	}
      free(var);
      y += 1;
    }
  return (NULL);
}

void	print_env(char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      printf("%s\n", env[i]);
      i += 1;
    }
}
