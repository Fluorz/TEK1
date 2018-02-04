/*
** which_exec.c for 42sh in /home/sid/PSU_2016_42sh/src/my_exec/
**
** Made by Sid Djilali Saiah
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Thu Jun  1 17:04:31 2017 Sid Djilali Saiah
** Last update Jan Jun 4 20:44:13 2017
*/

#include "transition.h"

int     can_execve_simple(t_arg_transitor *tmp)
{
    if (tmp->builtins == false && tmp->pipe_in == false
        && tmp->pipe_out == false && tmp->r_right == false
        && tmp->r_left == false && tmp->r_double_right == false
        && tmp->r_double_left == false)
        return (0);
    return (-1);
}

int     check_or_and_after(t_arg_transitor *tmp)
{
    if (tmp->double_pipe == true || tmp->double_and == true)
        return (0);
    return (-1);
}

int     can_execve_pipe(t_arg_transitor *tmp)
{
    if (tmp->builtins == false &&
        (tmp->pipe_in == true || tmp->pipe_out == true
            || tmp->r_right == true || tmp->r_left == true
            || tmp->r_double_right == true || tmp->r_double_left == true))
        return (0);
    return (-1);
}

int     can_builtins_pipe(t_arg_transitor *tmp)
{
    if (tmp->builtins == true &&
        (tmp->pipe_in == true || tmp->pipe_out == true
            || tmp->r_right == true || tmp->r_left == true
            || tmp->r_double_right == true || tmp->r_double_left == true))
        return (0);
    return (-1);
}

int     can_builtins_simple(t_arg_transitor *tmp)
{
    if (tmp->builtins == true &&
        (tmp->pipe_in == false && tmp->pipe_out == false))
        return (0);
    return (-1);
}
