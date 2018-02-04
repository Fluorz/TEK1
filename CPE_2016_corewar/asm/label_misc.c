/*
** label_misc.c for corewar in /home/monty/Documents/Rendu/corewar/CPE_2016_corewar/ASM/monty/lib/my/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Wed Mar 29 16:59:19 2017 Monty Criel
** Last update Sat Apr  1 22:29:13 2017 Monty Criel
*/

#include <unistd.h>
#include <stdlib.h>
#include "asm.h"
#include "my.h"
#include "op.h"

char	*get_label_name(char *str)
{
  char	*name;
  int	i;

  i = 0;
  while (str[i] != LABEL_CHAR)
    i += 1;
  name = malloc(sizeof(char) * (i + 1));
  i = 0;
  while (str[i] != LABEL_CHAR)
    {
      name[i] = str[i];
      i += 1;
    }
  name[i] = '\0';
  return (name);
}

char	*get_line1_label(char **inst)
{
  int	i;
  char	*str;

  i = 0;
  while (inst[0][i] != LABEL_CHAR)
    i += 1;
  if ((str = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (inst[0][i] != LABEL_CHAR)
    {
      str[i] = inst[0][i];
      i += 1;
    }
  str[i] = LABEL_CHAR;
  str[i + 1] = '\0';
  return (str);
}

char	*get_line2_label(char **inst)
{
  char	*str;
  int	tmp;
  int	i;
  int	x;

  i = 0;
  while (inst[0][i] != LABEL_CHAR)
    i += 1;
  i += 1;
  while (inst[0][i] == ' ' || inst[0][i] == '\t')
    i += 1;
  tmp = i;
  while (inst[0][i] != '\0')
    i += 1;
  if ((str = malloc(sizeof(char) * ((i - tmp) + 1))) == NULL)
    return (NULL);
  x = 0;
  while (inst[0][tmp] != '\0')
    {
      str[x] = inst[0][tmp];
      tmp += 1;
      x += 1;
    }
  str[x] = '\0';
  return (str);
}

char	**epure_label(char **inst)
{
  int	i;
  int	x;
  char	**tab;
  char	*line1;
  char	*line2;

  i = 0;
  while (inst[0][i] != ':')
    i += 1;
  if (my_strlen(inst[0]) == i)
    return (inst);
  if ((tab = realloc_tab(inst, 1)) == NULL)
    return (NULL);
  line1 = get_line1_label(inst);
  line2 = get_line2_label(inst);
  init_epure_label(tab, line1, line2);
  i = 1;
  x = 2;
  while (inst[i] != NULL)
    {
      tab[x] = my_strdup(inst[i]);
      i += 1;
      x += 1;
    }
  return (tab);
}

int	get_label_len(char **tab, int line)
{
  int	tmp;
  int	i;

  tmp = 0;
  i = line + 1;
  while (tab[i] != NULL && (tab[i][0] == '\t' || tab[i][0] == ' '))
    {
      i += 1;
      tmp += 1;
    }
  tmp += 1;
  return (tmp);
}
