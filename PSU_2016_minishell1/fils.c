/*
** fils.c for fils.c in /root/PSU_2016_minishell1/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Mon Jan 16 16:49:24 2017 Leo Lecherbonnier
** Last update Fri Jan 20 22:58:40 2017 Leo Lecherbonnier
*/

#include "minishell1.h"

void	chlid_process(char *str, char **arg, char **env)
{
  execve(str, arg, env);
  exit(0);
}
