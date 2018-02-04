/*
** where_which.c for 42sh in /home/sid/PSU_2016_42sh/src/builtins/
**
** Made by Sid Djilali Saiah
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Thu Jun  8 16:38:30 2017 Sid Djilali Saiah
** Last update Thu Jun  8 16:42:15 2017 Sid Djilali Saiah
*/

#include "my_exec.h"

static int	check_if_builtin_for_where(char *str)
{
  if (((strcmp(str, "exit") == 0))
      || ((strcmp(str, "unsetenv") == 0))
      || ((strcmp(str, "setenv") == 0))
      || ((strcmp(str, "echo") == 0))
      || ((strcmp(str, "which") == 0))
      || ((strcmp(str, "where") == 0))
      || ((strcmp(str, "env") == 0))
      || ((strcmp(str, "cd") == 0))
      || ((strcmp(str, "pwd") == 0)))
      return (0);
  return (1);
}

int     where(char **cmd, char **env)
{
  int	i = 1;
  char	*path;
  char	**path_tab;
  char	*bin_path;

  while (cmd[i])
    {
      if (check_if_builtin_for_where(cmd[i]) == 0)
	  printf("%s is a shell built-in\n", cmd[i]);
      path = my_getenv(env, "PATH=");
      path_tab = parse_before_checkaccess(path);
      bin_path = check_acess(path_tab, cmd + i, env);
      if (bin_path != NULL)
	printf("%s\n", bin_path);
      if (bin_path == NULL && check_if_builtin_for_where(cmd[i]) != 0)
	return (1);
      i++;
    }
  return (0);
}

int     which(char **cmd, char **env)
{
  int	i = 1;
  char	*path;
  char	**path_tab;
  char	*bin_path;
  int	return_value = 0;

  while (cmd[i])
    {
      if (check_if_builtin_for_where(cmd[i]) == 0)
	    printf("%s: shell built-in command.\n", cmd[i]);
      else if (check_if_builtin_for_where(cmd[i]) != 0)
	{
	  path = my_getenv(env, "PATH=");
	  path_tab = parse_before_checkaccess(path);
	  bin_path = check_acess(path_tab, cmd + i, env);
	  if (bin_path == NULL)
	    {
	      printf("%s: Command not found.\n", cmd[i]);
	      return_value = 1;
	    }
	  else printf("%s\n", bin_path);
	}
      i++;
    }
  return (return_value);
}
