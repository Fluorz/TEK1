/*
** instruction_tab.c for corewar in /home/monty/Documents/Rendu/corewar/CPE_2016_corewar/ASM/monty/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Thu Mar 30 17:21:37 2017 Monty Criel
** Last update Sun Apr  2 16:20:29 2017 Monty Criel
*/

#include <stdlib.h>
#include "my.h"

int	count_words_asm(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] != '\0')
    {
      while (str[i] != '\0' && (str[i++] == ' ' || str[i] == '\t' ||
				str[i] == ','));
      while (str[i] != '\0' && (str[i] != ' ' && str[i] != '\t' &&
				str[i] != ','))
	i = i + 1;
      if (str[i - 1] != ' ' && str[i - 1] != '\t' && str[i - 1] != ',')
	count =  count + 1;
    }
  return (count);
}

void	*add_tab_line_asm(char *str, int *idx)
{
  int	count;
  char	*line;
  int	i;

  while ((str[*idx] == ' ' || str[*idx] == '\t' ||
	  str[*idx] == ',') && str[*idx] != '\0')
    *idx = *idx + 1;
  i = *idx;
  while (str[i] != '\0' && (str[i] != ' ' && str[i] != '\t' && str[i] != ','))
    i = i + 1;
  count = i - *idx;
  line = malloc(sizeof(char) * (count + 1));
  i = 0;
  while ((str[*idx] != ' ' && str[*idx] != '\t' && str[*idx] != ',') &&
	 str[*idx] != '\0')
    {
      line[i] = str[*idx];
      i = i + 1;
      *idx = *idx + 1;
    }
  line[i] = '\0';
  return (line);
}

char	**wordtab_asm(char *str)
{
  int	i;
  int	x;
  int	count;
  char	**tab;

  i = 0;
  x = 0;
  count = count_words_asm(str);
  tab = malloc(sizeof(char *) * (count + 1));
  while (x != count)
    {
      tab[x] = add_tab_line_asm(str, &i);
      x = x + 1;
    }
  tab[x] = NULL;
  return (tab);
}
