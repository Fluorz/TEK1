/*
** transition.c for transition.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/my_exec/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Jun  1 14:54:04 2017 Leo Lecherbonnier
** Last update Fri Jun 16 14:50:41 2017 Sid Djilali Saiah
*/

#include "transition.h"

t_transitor	*my_transitor(t_parser *parser, char **env)
{
  t_transitor	*transitor;
  t_arg		*tmp;

  if (!parser->list)
    return (NULL);
  transitor = init_transitor(env);
  tmp = parser->list;
  if ((transitor = transit_arg(tmp, transitor)) == NULL)
    return (NULL);
  tmp = tmp->next;
  while (tmp->start != true)
    {
      if ((transitor = transit_arg(tmp, transitor)) == NULL)
	return (NULL);
      tmp = tmp->next;
    }
  return (transitor);
}

t_transitor		*transit_arg(t_arg *arg, t_transitor *transitor)
{
  t_arg_transitor	*new_arg;
  static t_alias    *alias_list = NULL;

  builtin_alias(&arg, &alias_list);
  if ((new_arg = fill_arg(arg)) == NULL)
    return (NULL);
  if (check_if_builtin(new_arg) == 0)
    new_arg->builtins = true;
  else if ((new_arg->bin_path = fill_bin_path(new_arg, transitor)) == NULL)
    {
      if (strcmp(new_arg->argv_execve[0], "/bin/echo") == 0)
	{
	  new_arg->argv_execve[0] = "echo";
	  new_arg->bin_path = "/bin/echo";
	}
      else if (strcmp(new_arg->argv_execve[0], "alias") != 0)
	{
	  command_not_found(new_arg);
      g_return_value = 1;
	  return (transitor);
	}
    }
  transitor = add_node_transitor(transitor, new_arg);
  return (transitor);
}

t_transitor	*init_transitor(char **env)
{
  t_transitor	*transitor;

  if ((transitor = malloc(sizeof(t_transitor))) == NULL)
    return (NULL);
  if ((transitor->env = tabdup(env, transitor->env)) == NULL)
    return (NULL);
  transitor->list = NULL;
  pipe(transitor->pipefd);
  return (transitor);
}
