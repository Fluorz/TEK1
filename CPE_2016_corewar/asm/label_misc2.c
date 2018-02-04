/*
** label_misc2.c for corewar in /home/monty/Documents/Rendu/corewar/CPE_2016_corewar/ASM/monty/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Thu Mar 30 16:31:03 2017 Monty Criel
** Last update Sun Apr  2 13:22:29 2017 Monty Criel
*/

#include <unistd.h>
#include <stdlib.h>
#include "asm.h"
#include "my.h"

char	**epure_instruction(char **tab)
{
  int	i;
  int	x;
  int	tmp;
  char	*str;

  i = 0;
  while (tab[i] != NULL)
    {
      x = 0;
      while (tab[i][x] == ' ' || tab[i][x] == '\t')
	x += 1;
      tmp = x;
      while (tab[i][x] != '\0')
	x += 1;
      str = malloc(sizeof(char) * ((i - tmp) + 1));
      if (str == NULL)
	return (NULL);
      str = my_strncpy(str, tab[i] + tmp, my_strlen(tab[i]) - tmp);
      tab[i] = my_strdup(str);
      i += 1;
    }
  return (tab);
}

void	init_epure_label(char **tab, char *line1, char *line2)
{
  tab[0] = line1;
  tab[1] = line2;
}

char	**get_label_instruction(char **tab, int line)
{
  int	i;
  int	x;
  int	tmp;
  char	**inst;

  tmp = get_label_len(tab, line);
  if ((inst = malloc(sizeof(char *) * (tmp + 1))) == NULL)
    return (NULL);
  i = line;
  x = 0;
  while (x != tmp)
    {
      if ((inst[x] = my_strdup(tab[i])) == NULL)
	return (NULL);
      x += 1;
      i += 1;
    }
  inst[x] = NULL;
  inst = epure_label(inst);
  inst = epure_instruction(inst);
  return (inst);
}

int		find_label_value(t_list *labels, char *label)
{
  t_node	*tmp;
  int		val;

  tmp = labels->head;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->name, label) == 0)
	val = tmp->size;
      tmp = tmp->next;
    }
  return (val);
}
