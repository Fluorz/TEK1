/*
** str_to_word_tab.c for str_towordtab.c in /root/PSU_2016_minishell1/src/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Mon Jan 16 13:17:27 2017 Leo Lecherbonnier
** Last update Sun Jan 22 17:13:30 2017 Leo Lecherbonnier
*/

#include "minishell1.h"

int		count_word(char *str, char separe)
{
  int		i;
  int		count;

  i = 0;
  count = 1;
  while (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
    i++;
  while (str[i])
    {
      if (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
	{
	  while (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
	    i++;
	  if (str[i])
	    count++;
	}
      if (str[i])
	i++;
    }
  return (count);
}

char		**my_str_to_wordtab(char *str, char separe)
{
  char		**tab;
  int		i;
  int		j;
  int		k;

  i = 0;
  j = 0;
  if ((tab = malloc(sizeof(*tab) * ((count_word(str, separe) + 1)))) == NULL)
    exit(-1);
  while (str[i] == '\t' || str[i] == ' ' || str[i] == separe)
    i++;
  while (str[i])
    {
      if ((tab[j] = malloc(sizeof(**tab) * (my_strlen(str) + 1))) == NULL)
	exit(-1);
      k = 0;
      while (str[i] != ' ' && str[i] != '\t' && str[i] != separe && str[i])
        tab[j][k++] = str[i++];
      tab[j++][k] = '\0';
      while (str[i] == ' ' || str[i] == '\t' || str[i] == separe)
	i++;
    }
  tab[j] = NULL;
  return (tab);
}
