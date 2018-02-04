/*
** alias.c for 42sh in /home/sid/PSU_2016_42sh/src/builtins/
**
** Made by Sid Djilali Saiah
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Sun Jun  4 16:49:06 2017 Sid Djilali Saiah
** Last update Tue Jun  6 10:06:40 2017 Sid Djilali Saiah
*/

#include "parser.h"
#include "transition.h"

void        builtin_alias(t_arg **arg, t_alias **list)
{
    char    **command;

    if (!(command = create_command_tab((*arg)->command, ' ')))
        exit(printf("Error Malloc: Builtin alias"));
    if (strcmp(command[0], "alias") == 0 && tablen(command) == 1)
    {
        freetab(command);
        return;
    }
    else if (strcmp(command[0], "alias") == 0)
    {
        (*list) = add_in_alias_list((*list), command);
        freetab(command);
    }
    else
    {
        command = replace_alias_in_cmd((*list), command);
        free((*arg)->command);
        (*arg)->command = alias_command(command);
        freetab(command);
    }
}
