/*
** main.c for ok in /home/abdel/42SH/PSU_2016_42sh/src
**
** Made by abdel cherkaoui
** Login   <abdel@epitech.net>
**
** Started on  Tue May 30 12:55:05 2017 abdel cherkaoui
** Last update Wed May 31 17:55:02 2017 Monty Criel
*/

#include <signal.h>
#include <string.h>
#include <stdio.h>
#include "gnl.h"
#include "my.h"

void	sigint_handler(int sig_num)
{
  write(1, "\n$>", 3);
}

int	shell_exit(t_shell *shell)
{
  if (strcmp(shell->cmd, "exit") == 0)
    {
      write(1, "exit\n", 5);
      free(shell->cmd);
      free_tab(shell->bin_paths);
      exit(0);
    }
  return (0);
}

int		main(int argc, char **argv, char **env)
{
  t_shell	shell;

  if (argc < 1 || env[0] == NULL)
    return (84);
  signal(SIGINT, sigint_handler);
  init_shell(&shell, env);
  if (isatty(0) == 1)
    write(1, "$>", 2);
  while ((shell.cmd = get_next_line(0)))
    {
      shell_exit(&shell);
      my_builtin(&shell);
      if (isatty(0) == 1)
	write(1, "$>", 2);
      free(shell.cmd);
    }
  return (0);
}
