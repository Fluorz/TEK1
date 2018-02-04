/*
** my_str_to_wordtab.c for my str to wordtab in /home/monty/Documents/Rendu/minishell/PSU_2016_minishell1/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Wed Jan 18 14:27:27 2017 Monty Criel
** Last update Fri Jun  2 22:36:06 2017 Monty Criel
*/

#include <stdlib.h>

int	count_words(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && (str[i++] == ' ' || str[i] == '\t'));
      while (str[i] != '\0' && (str[i] != ' ' && str[i] != '\t'))
	i = i + 1;
      if (str[i - 1] != ' ' && str[i - 1] != '\t')
	count =  count + 1;
    }
  return (count);
}

void	*add_tab_line(char *str, int *idx)
{
  int	count;
  char	*line;
  int	i;

  while ((str[*idx] == ' ' || str[*idx] == '\t') && str[*idx] != '\0')
    *idx = *idx + 1;
  i = *idx;
  while (str[i] != '\0' && (str[i] != ' ' && str[i] != '\t'))
    i = i + 1;
  count = i - *idx;
  line = malloc(sizeof(char) * (count + 1));
  if (line == NULL)
    exit(84);
  i = 0;
  while ((str[*idx] != ' ' && str[*idx] != '\t') && str[*idx] != '\0')
    {
      line[i] = str[*idx];
      i = i + 1;
      *idx = *idx + 1;
    }
  line[i] = '\0';
  return (line);
}

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	x;
  int	count;
  char	**tab;

  i = 0;
  x = 0;
  count  = count_words(str);
  tab = malloc(sizeof(char *) * (count + 1));
  if (tab == NULL)
    exit(84);
  while (x != count)
    {
      tab[x] = add_tab_line(str, &i);
      if (tab[x] == NULL)
	exit(84);
      x = x + 1;
    }
  tab[x] = NULL;
  return (tab);
}

void	free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (tab[i] != NULL)
	free(tab[i]);
      i += 1;
    }
  free(tab);
}
