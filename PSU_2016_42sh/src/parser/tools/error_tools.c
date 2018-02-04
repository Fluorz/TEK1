/*
** error_tools.c for 42sh in /home/sid/PSU_2016_42sh/src/parser/tools/
**
** Made by Sid Djilali Saiah
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Sat Jun  3 14:08:24 2017 Sid Djilali Saiah
** Last update Sat Jun  3 18:56:50 2017 Sid Djilali Saiah
*/

#include "parser.h"

int     invalid_pipe(char **tab, int i)
{
    if (i == 0)
        return (printf("Invalid null command.\n"), 0);
    else if (tab[i + 1] == NULL)
        return (printf("Invalid null command.\n"), 0);
    else if (strcmp(tab[i + 1], "|") == 0)
        return (printf("Invalid null command.\n"), 0);
    return (-1);
}

int     invalid_redirect(char **tab, int i)
{
    if (i == 0 && tab[i + 1] == NULL)
        return (printf("Missing name for redirect.\n"), 0);
    else if (i == 0)
        return (printf("Invalid null command.\n"), 0);
    else if (tab[i + 1] == NULL)
        return (printf("Missing name for redirect.\n"), 0);
    else if (strcmp(tab[i], ">") == 0 &&
            (strcmp(tab[i + 1], ">") == 0 || strcmp(tab[i + 1], "|") == 0))
        return (printf("Missing name for redirect.\n"), 0);
    else if (strcmp(tab[i], "<") == 0 &&
            (strcmp(tab[i + 1], "<") == 0 || strcmp(tab[i + 1], "|") == 0))
        return (printf("Missing name for redirect.\n"), 0);
    else if (strcmp(tab[i], "<") == 0 && strcmp(tab[i + 1], ">") == 0)
        return (printf("Missing name for redirect.\n"), 0);
    else if (strcmp(tab[i], ">") == 0 && strcmp(tab[i + 1], "<") == 0)
        return (printf("Missing name for redirect.\n"), 0);
    return (-1);
}

int     invalid_double_redirect(char **tab, int i)
{
    if (i == 0 && tab[i + 1] == NULL)
        return (printf("Missing name for redirect.\n"), 0);
    else if (tab[i + 1] == NULL)
        return (printf("Missing name for redirect.\n"), 0);
    else if (strcmp(tab[i], ">>") == 0 && strcmp(tab[i + 1], ">>") == 0)
        return (printf("Missing name for redirect.\n"), 0);
    else if (strcmp(tab[i], "<<") == 0 && strcmp(tab[i + 1], "<<") == 0)
        return (printf("Missing name for redirect.\n"), 0);
    return (-1);
}

int     invalid_double_pipe(char **tab, int i)
{
    if (i == 0)
        return (printf("Invalid null command.\n"), 0);
    else if (tab[i + 1] == NULL)
        return (printf("Invalid null command.\n"), 0);
    else if (strcmp(tab[i + 1], "||") == 0)
        return (printf("Invalid null command.\n"), 0);
    return (-1);
}

int     invalid_double_and(char **tab, int i)
{
    if (i != 0 && tab[i + 1] == NULL)
        return (printf("Invalid null command.\n"), 0);
    return (-1);
}
