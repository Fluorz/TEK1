/*
** linked_list.c for 42sh in /home/sid/PSU_2016_42sh/src/builtins/
**
** Made by Sid Djilali Saiah
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Sun Jun  4 17:53:34 2017 Sid Djilali Saiah
** Last update Tue Jun  6 09:32:15 2017 Sid Djilali Saiah
*/

#include "parser.h"
#include "transition.h"

char        *alias_command(char **command)
{
    int     i = -1;
    int     len = 0;
    char    *cmd;

    while (command[++i] != NULL)
        len += (strlen(command[i]) + 1);
    if (!(cmd = malloc(sizeof(char) * (len + 1))))
        return (NULL);
    cmd = strcpy(cmd, command[0]);
    cmd = strcat(cmd, " ");
    i = 1;
    while (command[i] != NULL)
    {
        cmd = strcat(cmd, command[i]);
        cmd = strcat(cmd, " ");
        i++;
    }
    cmd[len - 1] = '\0';
    return (cmd);
}

t_alias     *create_alias(t_alias *node, char **command)
{
    if (!(node->alias = strdup(command[1])))
        exit(printf("Error Malloc: create_alias"));
    if (!(node->command = alias_command(command + 2)))
        exit(printf("Error Malloc: create_alias"));
    return (node);
}

char        **replace_alias_in_cmd(t_alias *list, char **command)
{
    int     i;
    t_alias *tmp;

    i = 0;
    while (command[i] != NULL)
    {
        tmp = list;
        while (tmp != NULL)
        {
            if (strcmp(command[i], tmp->alias) == 0)
            {
                free(command[i]);
                if (!(command[i] = strdup(tmp->command)))
                    exit(printf("Error Malloc : replace_alias_in_cmd.\n"));
            }
            tmp = tmp->next;
        }
        i++;
    }
    return (command);
}

bool            change_alias(t_alias **list, char **command)
{
    t_alias     *tmp;

    tmp = (*list);
    while (tmp != NULL)
    {
        if (strcmp(tmp->alias, command[1]) == 0)
        {
            free(tmp->command);
            if (!(tmp->command = alias_command(command + 2)))
                exit(printf("Error Malloc: change_alias"));
            return (true);
        }
        tmp = tmp->next;
    }
    return (false);
}
