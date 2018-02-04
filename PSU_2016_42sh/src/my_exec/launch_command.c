/*
** launch_command.c for launch_command.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/my_exec/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Jun  1 15:45:09 2017 Leo Lecherbonnier
** Last update Thu Jun  8 17:40:18 2017 Sid Djilali Saiah
*/

#include "transition.h"
#include "my_exec.h"

t_transitor		*what_we_do_with_arg(t_transitor *transitor,
					     t_arg_transitor *tmp)
{
  if (can_execve_simple(tmp) == 0)
    {
      transitor = execve_simple(transitor, tmp);
    }
  else if (can_execve_pipe(tmp) == 0)
    {
      transitor = execve_pipe(transitor, tmp);
    }
  else if (can_builtins_simple(tmp) == 0)
    {
      transitor = builtins_simple(transitor, tmp);
    }
  else if (can_builtins_pipe(tmp) == 0)
    {
      transitor = builtins_pipe(transitor, tmp);
    }
  else
    exit (84);
  return (transitor);
}

void	launch_command(t_transitor *transitor)
{
  t_arg_transitor	*tmp;

  if (!transitor->list)
    return;
  tmp = transitor->list;
  tmp->argv_execve = globbing_function(tmp->argv_execve);
  transitor = what_we_do_with_arg(transitor, tmp);
  if (tmp->double_pipe == true && tmp->return_value == 0)
    tmp = tmp->next;
  if (tmp->double_and == true && tmp->return_value != 0)
    tmp = tmp->next;
  tmp = tmp->next;
  while (tmp->start != true)
    {
	  tmp->argv_execve = globbing_function(tmp->argv_execve);
      transitor = what_we_do_with_arg(transitor, tmp);
      if (tmp->double_pipe == true && tmp->return_value == 0)
        tmp = tmp->next;
      if (tmp->double_and == true && tmp->return_value != 0)
		tmp = tmp->next;
      tmp = tmp->next;
    }
  return;
}
