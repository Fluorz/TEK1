/*
** wordtab_misc.c for corewar in /home/monty/Documents/Rendu/CPE_2016_corewar/ASM/monty/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Sat Apr  1 21:55:23 2017 Monty Criel
** Last update Sun Apr  2 21:26:07 2017 Monty Criel
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"
#include "op.h"

char	*line1_label(char *label)
{
  int	i;
  int	x;
  char	*str;

  i = 0;
  while (label[i] != LABEL_CHAR)
    i += 1;
  i += 1;
  str = malloc(sizeof(char) * (i + 1));
  if (str == NULL)
    exit(84);
  x = 0;
  while (x != i)
    {
      str[x] = label[x];
      x += 1;
    }
  str[x] = '\0';
  return (str);
}

char	*line2_label(char *label)
{
  char	*str;
  int	tmp;
  int	i;
  int	x;

  i = 0;
  while (label[i] != LABEL_CHAR)
    i += 1;
  i += 1;
  while (label[i] == ' ' || label[i] == '\t')
    i += 1;
  tmp = i;
  while (label[i] != '\0')
    i += 1;
  if ((str = malloc(sizeof(char) * ((i - tmp) + 1))) == NULL)
    exit(84);
  x = 0;
  while (label[tmp] != '\0')
    {
      str[x] = label[tmp];
      tmp += 1;
      x += 1;
    }
  str[x] = '\0';
  return (str);
}

char	**seperate_label_tab(char **tab)
{
  char	**new;
  char	**tmp;
  char	*str1;
  char	*str2;
  int	i;

  i = 0;
  new = NULL;
  while (tab[i] != NULL)
    {
      tmp = wordtab_asm(tab[i]);
      if (is_label(tmp[0]) == 0)
	{
	  str1 = line1_label(tab[i]);
	  str2 = line2_label(tab[i]);
         new = tab_append_tail(new, str1);
	  new = tab_append_tail(new, str2);
	}
      else
	new = tab_append_tail(new, tab[i]);
      free_tab(tmp);
      i += 1;
    }
  return (new);
}
