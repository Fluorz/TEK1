/*
** alias_other_tools.c for 42sh in /home/sid/PSU_2016_42sh/src/builtins/
**
** Made by Sid Djilali Saiah
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Mon Jun  5 16:02:28 2017 Sid Djilali Saiah
** Last update Mon Jun  5 17:02:06 2017 Sid Djilali Saiah
*/

#include "parser.h"
#include "transition.h"

t_alias     *add_in_alias_list(t_alias *liste, char **command)
{
    t_alias *new_node;
    t_alias *temp;

    temp = liste;
    if (!(new_node = malloc(sizeof(t_alias))))
        return (NULL);
    new_node = create_alias(new_node, command);
    new_node->next = NULL;
    if (liste == NULL)
        return (new_node);
    else if (change_alias(&liste, command) == true)
        return (liste);
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        return (liste);
    }
}

void        print_alias_list(t_alias *list)
{
    t_alias *tmp;

    tmp = list;
    while (tmp != NULL)
    {
        printf("alias: [%s] [%s]\n", tmp->alias, tmp->command);
        tmp = tmp->next;
    }
}

void    free_alias(t_alias *node)
{
    free(node->alias);
    free(node->command);
    free(node);
}

t_alias     *remove_alias(t_alias *list, char *to_remove)
{
    t_alias *tmp;

    tmp = list;
	if (list == NULL)
		return (NULL);
	while  (tmp->next->next != NULL)
    {
        if (strcmp(tmp->next->alias, to_remove) == 0)
            {
                tmp->next = tmp->next->next;
                free_alias(tmp->next);
                return (list);
            }
        tmp = tmp->next;
    }
    return (list);
}
