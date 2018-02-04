/*
** fill_bin_path.c for fill_bin_path.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/my_exec/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Jun  1 16:18:23 2017 Leo Lecherbonnier
** Last update Feb Jun 12 14:58:42 2017
*/

#include "parser.h"
#include "transition.h"

char	*fill_bin_path(t_arg_transitor *new_arg, t_transitor *transitor)
{
  char	*path;
  char	**path_tab;
  char	*bin_path;

  path = my_getenv(transitor->env, "PATH=");
  path_tab = parse_before_checkaccess(path);
  bin_path = check_acess(path_tab, new_arg->argv_execve, transitor->env);
  return (bin_path);
}

char	**parse_before_checkaccess(char *str)
{
  char	**tab;

  if (!(tab = create_command_tab(str, ':')))
  	return (NULL);
  return (tab);
}

char	*check_acess(char **path, char **ptr, char **env)
{
  int	i;
  char	*str;

  i = 0;
  while (path[i] != NULL)
    {
      if (!(str = malloc(sizeof(char) * (strlen(path[i]) + strlen(ptr[0])))))
	  	return (NULL);
      str = strcat(path[i], "/");
      str = strcat(str, ptr[0]);
      if (access(str, F_OK | X_OK) == 0)
	return (str);
      i++;
    }
  str = strcat(my_getenv(env, "PWD="), "/");
  str = strcat(str, ptr[0]);
  if ((access(str, F_OK | X_OK) == 0))
    return (str);
  return (NULL);
}
