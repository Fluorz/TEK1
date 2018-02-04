/*
** main.c for main.c in /root/PSU_2016_minishell1/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Mon Jan 16 13:03:03 2017 Leo Lecherbonnier
** Last update Sun Jan 22 17:21:47 2017 Leo Lecherbonnier
*/

#include "minishell1.h"

int	main(int ac, char **av, char **env)
{
  int	status;
  pid_t	pid;
  char	*string;
  char	**scan;
  char	**path_env;
  char	*good_path;

  while (42)
    {
      my_putstr("\033[32mroot@kali-\033[31m$>\033[0m");
      string = get_next_line(0);
      if (string[0] != '\0')
	{
	  scan = my_str_to_wordtab(string, ' ');
	  string = my_getenv(env, "PATH");
	  path_env = parse_before_checkaccess(string);
	  good_path = check_acess(path_env, scan, env);
	  pid = create_process();
	  if (pid == 0)
	    chlid_process(good_path, scan, env);
	  wait(&status);
	  my_status(status);
	}
    }
}

pid_t	create_process(void)
{
  pid_t pid;

  pid = fork();
  return (pid);
}

void	my_status(int status)
{
  if (WIFSIGNALED(status) == 1)
    {
      if (WTERMSIG(status) == 11)
	my_putstr("Segmentation fault (core dumped)\n");
      else if (WTERMSIG(status) == 8)
	my_putstr("floating point exception\n");
    }
}
