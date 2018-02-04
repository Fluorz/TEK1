/*
** wordtab.c for need4stek in /home/monty/Documents/Rendu/need4stek/CPE_2016_n4s/src/tools/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Thu Jun  1 17:10:30 2017 Monty Criel
** Last update Sat Jun  3 17:53:07 2017 Monty Criel
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	count_words(char *str, char c)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && (str[i++] == ' ' || str[i] == c));
      while (str[i] != '\0' && (str[i] != ' ' && str[i] != c))
	i = i + 1;
      if (str[i - 1] != ' ' && str[i - 1] != c)
	count =  count + 1;
    }
  if (count == 0)
    count = 1;
  return (count);
}

void	*add_tab_line(char *str, int *idx, char c)
{
  int	count;
  char	*line;
  int	i;

  while ((str[*idx] == ' ' || str[*idx] == c) && str[*idx] != '\0')
    *idx = *idx + 1;
  i = *idx;
  while (str[i] != '\0' && (str[i] != ' ' && str[i] != c))
    i = i + 1;
  count = i - *idx;
  line = malloc(sizeof(char) * (count + 1));
  if (line == NULL)
    exit(84);
  i = 0;
  while ((str[*idx] != ' ' && str[*idx] != c) && str[*idx] != '\0')
    {
      line[i] = str[*idx];
      i = i + 1;
      *idx = *idx + 1;
    }
  line[i] = '\0';
  return (line);
}

char	**wordtab(char *str, char c)
{
  int	i, x;
  int	count;
  char	**tab;

  i = 0;
  x = 0;
  count = count_words(str, c);
  if (count == 1)
    {
      if ((tab = malloc(sizeof(char *) * 2)) == NULL)
	exit(42);
      tab[0] = strdup(str);
      tab[1] = NULL;
      return (tab);
    }
  if ((tab = malloc(sizeof(char *) * (count + 1))) == NULL)
    exit(84);
  while (x != count)
    {
      if ((tab[x] = add_tab_line(str, &i, c)) == NULL)
	exit(84);
      x = x + 1;
    }
  tab[x] = NULL;
  return (tab);
}

void	print_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      write(2, tab[i], strlen(tab[i]));
      write(2, "\n", 1);
      i += 1;
    }
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
