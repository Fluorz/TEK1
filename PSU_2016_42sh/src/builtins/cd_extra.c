/*
** cd_extra.c for 42sh in /home/monty/Documents/Rendu/minishell/PSU_2016_42sh/src/builtins/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Fri Jun  2 15:15:44 2017 Monty Criel
** Last update Mon Jun 12 11:31:03 2017 Monty Criel
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "my.h"

char	*my_copy(char *string)
{
  char	*str;
  int	i;

  i = 0;
  str = malloc(sizeof(char) * (strlen(string) + 1));
  if (str == NULL)
    exit(84);
  while (string[i] != '\0')
    {
      str[i] = string[i];
      i += 1;
    }
  return (str);
}

char	**change_dir(char **env, char *dir_name)
{
  char	cwd[1024];

  chdir(dir_name);
  getcwd(cwd, sizeof(cwd));
  env = update_cwd(env, cwd, get_env_var(env, "PWD"));
  return (env);
}

char	**change_dir_special(char **cmd, char **env, int *status)
{
  char	cwd[1024];
  char	*old_dir;

  if (strcmp(cmd[1], "-") == 0)
    {
      old_dir = get_env_var(env, "OLDPWD");
      chdir(old_dir);
      env = update_cwd(env, old_dir, get_env_var(env, "PWD"));
      free(old_dir);
      return (*status = 0, env);
    }
  if (strcmp(cmd[1], ".") == 0)
    return (*status = 0, env);
  else
    {
      chdir("..");
      getcwd(cwd, sizeof(cwd));
      env = update_cwd(env, cwd, get_env_var(env, "PWD"));
    }
  return (*status = 0, env);
}
