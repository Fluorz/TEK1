/*
** change_dir.c for change_dir.c in /home/lecherbonnier/Projet/PSU_2016_minishell2/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Apr 11 09:21:41 2017 Leo Lecherbonnier
** Last update Tue Apr 11 09:22:18 2017 Leo Lecherbonnier
*/

#include "minishell1.h"

void	else_changeDir(char **str, char **env)
{
  if (chdir(str[1]) == -1)
    {
      if (errno == ENOTDIR)
	{
	  my_putstr(str[1]);
	  my_putstr(": Not a directory.\n");
	  RETURN_VALUE = 1;
	}
      if (errno == ENOENT)
	{
	  my_putstr(str[1]);
	  my_putstr(": No such file or directory.\n");
	  RETURN_VALUE = 1;
	}
    }
  else
    no_directory(str[1]);
}

void changeDir(char **str, char **env)
{
  char	cwd[1024];

  getcwd(cwd, sizeof(cwd));
  if (str[1] == NULL)
    {
      chdir(my_getenv(env, "HOME"));
      env = change_env(env, "PWD", my_getenv(env, "HOME"));
      env = change_env(env, "OLDPWD", cwd);
    }
  else if (str[1][0] == '-')
    {
      chdir(my_getenv(env, "OLDP"));
      env = change_env(env, "OLDPWD", cwd);
      getcwd(cwd, sizeof(cwd));
      env = change_env(env, "PWD", cwd);
    }
  else if (chdir(str[1]) != -1)
    {
      env = change_env(env, "OLDPWD", cwd);
      getcwd(cwd, sizeof(cwd));
      env = change_env(env, "PWD", cwd);
    }
  else
    else_changeDir(str, env);
}

void	no_directory(char *str)
{
  my_putstr(str);
  my_putstr(": No such file or directory.\n");
  RETURN_VALUE = 1;
}
