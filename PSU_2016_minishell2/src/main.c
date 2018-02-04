/*
** main.c for main.c in /root/PSU_2016_minishell1/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Mon Jan 16 13:03:03 2017 Leo Lecherbonnier
** Last update Apr Apr 12 17:35:18 2017
*/

#include "minishell1.h"

int RETURN_VALUE = 0;

void	sig_handler(int signo)
{
  return;
}

int	loop(t_parse *p)
{
  while ((p->string = get_next_line(0)))
    {
      p->scan = my_str_to_wordtab(p->string, ' ');
      if (p->string[0] != '\0')
	{
	  RETURN_VALUE = 0;
	  p->string = my_getenv(p->env, "PATH");
	  p->path_env = parse_before_checkaccess(p->string);
	  p->good_path = check_acess(p->path_env, p->scan, p);
	  p->pid = create_process();
	  if (p->pid == 0)
	    chlid_process(p->good_path, p->scan, p->env);
	  wait(&p->status);
	  my_status(p->status);
	}
    }
  return (RETURN_VALUE);
}

int	main(int ac, char **av, char **env)
{
  t_parse	*p;

  signal(SIGINT, sig_handler);
  p = init_parse(env);
  return (loop(p));
}

t_parse *init_parse(char **env)
{
  t_parse *p;

  if ((p = malloc(sizeof(t_parse) * 1)) == NULL)
    return (NULL);
  p->env = env;
  return (p);
}

pid_t	create_process(void)
{
  pid_t pid;

  pid = fork();
  return (pid);
}
