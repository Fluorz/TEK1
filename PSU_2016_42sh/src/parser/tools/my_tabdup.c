/*
** my_tabdup.c for 42sh in /home/sid/PSU_2016_42sh/src/parser/tools/
**
** Made by Sid Djilali Saiah
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Thu Jun  1 16:19:35 2017 Sid Djilali Saiah
** Last update Thu Jun  8 16:58:34 2017 Sid Djilali Saiah
*/

#include "parser.h"

int	tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

void    freetab(char **tab)
{
    int i;

    i = 0;
    while (tab[i] != NULL)
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

int	print_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i] != NULL)
    printf("%s\n", tab[i]);
  return (0);
}

char	**tabdup(char **from, char **dest)
{
  int	i;

  i = 0;
  if ((dest = malloc(sizeof(char *) * (tablen(from) + 1))) == NULL)
    return (NULL);
  while (i != tablen(from))
    {
      dest[i] = strdup(from[i]);
      i++;
    }
  dest[i] = NULL;
  return (dest);
}

char    *my_getenv(char **env, char *str)
{
    int   y;
    int   x;

    y = 0;
    x = 0;
    while (env[y] != NULL)
    {
        x= 0;
        while (str[x] != '\0' || env[y][x] != '\0')
        {
            if (str[x] != env[y][x])
            break;
            x = x + 1;
        }
        if (str[x] == '\0')
        break ;
        y = y + 1;
    }
    if (env[y] != NULL)
        return (&env[y][strlen(str)]);
    return (NULL);
}
