/*
** main.c for main.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Jun 12 12:28:50 2017 Leo Lecherbonnier
** Last update Fri Jun 16 14:58:53 2017 Sid Djilali Saiah
*/

#include <stdio.h>
#include <signal.h>
#include "gnl.h"
#include "my.h"
#include "transition.h"
#include "parser.h"

int g_return_value = 0;

void	sig_handler(int signo)
{
    int i = 0;
write(2, "\n\033[31m╭∩╮\033[32m(Ο_Ο)\033[31m╭∩╮ >\033[0m", 48);
  if (signo == SIGINT)
    i++;
  else
    {
      printf("Memory error detected.\n");
      exit (1);
    }
}

void		launch_42_sh(char **env)
{
  t_parser	*parser = NULL;
  t_transitor	*t_transitor = NULL;
  char		*user_command;
  int		return_parser = 0;
  static	int i = 0;

  write(2, "\033[31m╭∩╮\033[32m(Ο_Ο)\033[31m╭∩╮ >\033[0m", 47);
  while ((user_command = get_next_line(0)))
    {
      if ((parser = my_parser(user_command, &return_parser)) != NULL)
	{
	  if (i == 0)
	    {
	      if ((t_transitor = my_transitor(parser, env)) == NULL)
		exit (1);
	      i++;
	    }
	  else
	    if ((t_transitor = my_transitor(parser, t_transitor->env)) == NULL)
		exit (1);
	  launch_command(t_transitor);
	}
write(2, "\033[31m╭∩╮\033[32m(Ο_Ο)\033[31m╭∩╮ >\033[0m", 47);
    }
  if (parser == NULL || t_transitor->list == NULL)
  {
      if (g_return_value == 1)
      exit (1);
      else
      exit (return_parser);
  }
  exit (t_transitor->list->prev->return_value);
}

int	main(int ac, char **av, char **env)
{
  if (ac != 1 || av[0] == NULL || env[0] == NULL)
    return (84);
  signal(SIGSEGV, sig_handler);
  signal(SIGINT, sig_handler);
  launch_42_sh(env);
  return (0);
}
