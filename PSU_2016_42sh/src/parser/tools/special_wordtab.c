/*
** special_wordtab.c for 42sh in /home/sid/PSU_2016_42sh/src/parser/tools/
**
** Made by Sid Djilali Saiah
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Wed May 31 16:23:07 2017 Sid Djilali Saiah
** Last update May Jun 1 14:36:08 2017
*/

#include "parser.h"

int	s_nb_lines(char *str, char *sep)
{
  int	i;
  int	lines;

  i = 0;
  lines = 1;
  while (str[i] != '\0')
    {
      if (str[i] == sep[0] && str[i + 1] == sep[1])
	{
	  i += 2;
	  lines++;
	}
      if (str[i] != '\0')
	i++;
    }
  return (lines);
}

char	**create_special_wordtab(char *str, char *sep)
{
  int	i = 0;
  int	j = -1;
  int	k;
  char	**tab;

  if ((tab = malloc(sizeof(char *) * (s_nb_lines(str, sep) + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0' && ++j != s_nb_lines(str, sep))
    {
      if ((tab[j] = malloc(sizeof(char) * (strlen(str) + 1))) == NULL)
	return (NULL);
      k = -1;
      while (str[i] != '\0')
	{
	  if (str[i] == sep[0] && str[i + 1] == sep[1])
	    break ;
	  tab[j][++k] = str[i];
	  tab[j][k + 1] = '\0';
	  i++;
	}
      if (str[i] !=  '\0' || (str[i] == sep[0] && str[i + 1] == sep[1]))
	i = i + 2;
    }
  return (tab[s_nb_lines(str, sep)] = NULL, tab);
}

char	**special_wordtab(char *str, char *sep)
{
  char **tab;
  int i;

  i = 0;
  if (!(tab = create_special_wordtab(str, sep)))
    return (NULL);
  while (tab[i] != NULL)
    {
      tab[i] = epur_str(tab[i]);
      i++;
    }
  return (tab);
}
