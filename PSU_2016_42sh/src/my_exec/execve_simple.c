/*
** execve_simple.c for execve_simple.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/my_exec/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri Jun  2 09:55:51 2017 Leo Lecherbonnier
** Last update May Jun 8 09:33:42 2017
*/

#include "my_exec.h"

t_transitor	*execve_simple(t_transitor *transitor, t_arg_transitor *arg)
{
  int 		pid;
  int		status;

  pid = create_process();
  if (pid == 0)
    chlid_process(arg->bin_path, arg->argv_execve, transitor->env);
  wait(&status);
  arg = my_status(status, arg);
  return (transitor);
}

void	chlid_process(char *str, char **arg, char **env)
{
  int	return_value = 0;

  if ((execve(str, arg, env)) == 0)
    exit (0);
  if (errno == ENOEXEC)
    {
      write(2, arg[0], strlen(arg[0]));
      write(2, ": ", 2);
      write(2, "Exec format error. Binary file not executable.", 48);
      return_value = 1;
    }
  else if (errno == EACCES)
    {
      write(2, arg[0], strlen(arg[0]));
      write(2, ": ", 2);
      write(2, "Permission denied.\n", strlen("Permission denied.\n"));
      return_value = 1;
    }
  exit (return_value);
}

pid_t	create_process(void)
{
  pid_t pid;

  pid = fork();
  return (pid);
}
