/*
** parser_double.c for 42sh in /home/sid/PSU_2016_42sh/src/parser/organise/
**
** Made by Sid Djilali Saiah
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Wed May 31 14:45:44 2017 Sid Djilali Saiah
** Last update Wed May 31 16:31:38 2017 Sid Djilali Saiah
*/

#include "string.h"

int     double_pipe_exist(char *str)
{
    if (strstr(str, "||") != NULL)
        return (0);
    else
        return (-1);
}

int     double_and_exist(char *str)
{
    if (strstr(str, "&&") != NULL)
        return (0);
    else
        return (-1);
}

int     double_right_exist(char *str)
{
    if (strstr(str, ">>") != NULL)
        return (0);
    else
        return (-1);
}

int     double_left_exist(char *str)
{
    if (strstr(str, "<<") != NULL)
        return (0);
    else
        return (-1);
}
