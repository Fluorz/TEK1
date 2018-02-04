/*
** str_to_wordtab.c for PSU_2016_minishell1 in /home/sid/PSU_2016_minishell1
**
** Made by Sid Djilali Saiah
** Login   <sid@epitech.net>
**
** Started on  Tue Jan 17 21:12:16 2017 Sid Djilali Saiah
** Last update Sun Apr  2 22:13:07 2017 Monty
*/

#include <stdlib.h>
#include "my.h"

char    *my_parse_str(int s, int e, char *str)
{
  int   i;
  int   j;
  char  *new_str;

  i = s - 1;
  j = 0;
  new_str = malloc(sizeof(char) * (e - s) + 1);
  if (new_str == NULL)
    return (NULL);
  while (++i != e)
    {
      new_str[j] = str[i];
      j++;
    }
  new_str[j] = '\0';
  return (new_str);
}

char    *my_str_dup(char *dest, char *src)
{
  int   i;

  i = 0;
  dest = malloc(sizeof(char) * my_strlen(src) + 1);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

int	nb_line(char *str, char c)
{
  int	i;
  int	lines;

  i = 0;
  lines = 1;
  while (str[i] == ' ' || str[i] == '\t' || str[i] == c)
    i++;
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t' || str[i] == c)
	{
	  while (str[i] == ' ' || str[i] == '\t' || str[i] == c)
	    i++;
	  if (str[i])
	    lines++;
	}
      if (str[i])
	i++;
    }
  return (lines);
}

char	**str_to_wordtab(char *str, char c)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  if ((tab = malloc(sizeof(char *) * ((nb_line(str, c) + 1)))) == NULL)
    return (NULL);
  while (str[i] == '\t' || str[i] == ' ' || str[i] == c)
    i++;
  while (str[i] != '\0')
    {
      if ((tab[j] = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
	return (NULL);
      k = 0;
      while (str[i] != ' ' && str[i] != '\t' && str[i] != c && str[i])
	tab[j][k++] = str[i++];
      tab[j++][k] = '\0';
      while (str[i] == ' ' || str[i] == '\t' || str[i] == c)
	i++;
    }
  tab[j] = NULL;
  return (tab);
}
