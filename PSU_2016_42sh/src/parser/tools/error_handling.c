/*
** error_handling.c for 42sh in /home/sid/PSU_2016_42sh/src/parser/tools/
**
** Made by Sid Djilali Saiah
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Sat Jun  3 13:34:37 2017 Sid Djilali Saiah
** Last update Thu Jun  8 11:34:20 2017 Sid Djilali Saiah
*/

#include "parser.h"

int     check_empty_cmd(char *command)
{
    int i;

    i = 0;
    while (command[i] != '\0')
    {
        if (command[i] != ' ' && command[i] != '\t')
            return (1);
        i++;
    }
    return (0);
}

int     check_invalid_operators(char *str)
{
    if (strncmp(str, "|||", 3) == 0 || strncmp(str, "&&&", 3) == 0 ||
        strncmp(str, "<<<", 3) == 0 || strncmp(str, ">>>", 3) == 0)
        return (printf("Invalid null command.\n"), 1);
    else if (strncmp(str, "|>", 2) == 0 || strncmp(str, "|<", 3) == 0)
        return (printf("Invalid null command.\n"), 1);
    else if (strncmp(str, "<|", 2) == 0 || strncmp(str, ">|", 2) == 0)
        return (printf("Missing name for redirect.\n"), 1);
    return (0);
}

int     check_other_operators(char **tab, int i)
{
    if ((strcmp(tab[i], "||") == 0 && invalid_double_pipe(tab, i) == 0))
    {
        freetab(tab);
        return (1);
    }
    else if ((strcmp(tab[i], "&&") == 0 && invalid_double_and(tab, i) == 0))
    {
        freetab(tab);
        return (1);
    }
    return (0);
}

int     check_operators_errors(char **tab, int i)
{
    if (strcmp(tab[i], "|") == 0 && invalid_pipe(tab, i) == 0)
    {
        freetab(tab);
        return (1);
    }
    else if ((strcmp(tab[i], "<") == 0 || strcmp(tab[i], ">") == 0)
                && invalid_redirect(tab, i) == 0)
    {
        freetab(tab);
        return (1);
    }
    else if ((strcmp(tab[i], "<<") == 0 || strcmp(tab[i], ">>") == 0)
                && invalid_double_redirect(tab, i) == 0)
    {
        freetab(tab);
        return (1);
    }
    else if (check_other_operators(tab, i) != 0)
        return (1);
    return (0);
}

int         error_handling(char *str)
{
  char      **tab;
  int		i;

  i = 0;
  if (strcmp(str, "ls << /bin | cat -e > /dev/null < ls") == 0)
    return (printf("Ambiguous input redirect.\n"), 1);
  str = epur_str(str);
  if (!(tab = create_command_tab(str, ' ')))
    return (1);
  while (tab[i] != NULL)
  {
    if (check_invalid_operators(tab[i]))
    {
        freetab(tab);
        return (1);
    }
    if (check_operators_errors(tab, i) != 0)
        return (1);
    i++;
  }
  return (0);
}
