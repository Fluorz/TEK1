/*
** cd_command.c for 42sh in /home/monty/Documents/Rendu/minishell/PSU_2016_42sh/src/builtins/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Fri Jun  2 15:13:07 2017 Monty Criel
** Last update Mon Jun 12 11:29:53 2017 Monty Criel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	x;
  int	i;
  int	len;
  char	*new_str;

  x = 0;
  i = 0;
  len = strlen(dest) + strlen(src);
  new_str = malloc(sizeof(char) * (len + 1));
  if (new_str == NULL)
    exit(84);
  while (dest[x] != '\0')
    new_str[i++] = dest[x++];
  x = 0;
  while (src[x] != '\0')
    {
      new_str[i] = src[x];
      x = x + 1;
      i = i + 1;
    }
  new_str[i] = '\0';
  return (new_str);
}

char	**update_cwd(char **env, char *new_pwd, char *old_pwd)
{
  int	status;
  char	**cmd;
  char	*pwd;

  pwd = my_copy("setenv OLDPWD ");
  pwd = my_strcat(pwd, old_pwd);
  cmd = wordtab(pwd);
  free(pwd);
  free_tab(cmd);
  pwd = my_copy("setenv PWD ");
  pwd = my_strcat(pwd, new_pwd);
  cmd = wordtab(pwd);
  env = set_env(env, cmd, &status);
  free(pwd);
  free_tab(cmd);
  return (env);
}

int	check_home(char **cmd_name, char **env)
{
  if (strcmp(cmd_name[0], "cd") == 0 && cmd_name[1] == NULL)
    {
      update_cwd(env, get_env_var(env, "HOME"), get_env_var(env, "PWD"));
      return (0);
    }
  if (strcmp(cmd_name[1], "--") == 0 && cmd_name[2] == NULL)
    {
      update_cwd(env, get_env_var(env, "HOME"), get_env_var(env, "PWD"));
      return (0);
    }
  if (strcmp(cmd_name[1], "~/") == 0 && cmd_name[2] == NULL)
    {
      update_cwd(env, get_env_var(env, "HOME"), get_env_var(env, "PWD"));
      return (0);
    }
  if (strcmp(cmd_name[1], "home") == 0 && cmd_name[2] == NULL)
    {
      write(1, "~\n", 2);
      update_cwd(env, get_env_var(env, "HOME"), get_env_var(env, "PWD"));
      return (0);
    }
  else
    return (-1);
}

char	**go_to_home(char **env)
{
  char	*path;

  path = get_env_var(env, "HOME");
  chdir(path);
  free(path);
  return (env);
}

char	**change_directory(char **cmd_name, char **env, int *status)
{
  if (strcmp(cmd_name[0], "cd") != 0)
    return (*status = -1, env);
  if (check_home(cmd_name, env) == 0)
    {
      env = go_to_home(env);
      return (*status = 0, env);
    }
  if (strcmp(cmd_name[1], "-") == 0 || strcmp(cmd_name[1], "..") == 0
      || strcmp(cmd_name[1], ".") == 0)
    {
      env = change_dir_special(cmd_name, env, status);
      return (*status = 0, env);
    }
  if (strcmp(cmd_name[0], "cd") == 0 && cmd_name[2] == NULL)
    {
      if (access(cmd_name[1], F_OK | X_OK) != 0)
	printf("%s: No such file or directory.\n", cmd_name[1]);
      else if (chdir(cmd_name[1]) == 0)
	env = change_dir(env, cmd_name[1]);
      else
	printf("%s: Not a directory.\n", cmd_name[1]);
      return (*status = 1, env);
    }
  return (*status = -1, env);
}
