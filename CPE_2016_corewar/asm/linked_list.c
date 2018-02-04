/*
** linked_list.c for corewar in /home/monty/Documents/Rendu/corewar/CPE_2016_corewar/ASM/monty/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Wed Mar 29 13:16:04 2017 Monty Criel
** Last update Sun Apr  2 19:46:53 2017 Monty Criel
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "linked_list.h"
#include "asm.h"
#include "my.h"

t_node		*create_node(void)
{
  t_node	*node;

  node = malloc(sizeof(t_node));
  if (node == NULL)
    return (NULL);
  node->next = NULL;
  return (node);
}

void	init_node(t_node *node, char **tab, int line)
{
  node->name = get_label_name(tab[line]);
  node->size = 0xff;
}

int		append_tail(t_list *list, t_node *node)
{
  t_node	*tmp;

  if (list->head == NULL)
    {
      list->head = node;
      return (0);
    }
  tmp = list->head;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = node;
  node->next = NULL;
  return (0);
}

t_list		*create_list()
{
  t_list	*list;
  char		*path;
  char		*file;

  if ((list = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  if (list == NULL)
    exit(84);
  list->head = NULL;
  return (list);
}

t_list		*get_labels(char *av)
{
  t_list	*labels;
  t_node	*node;
  char		*file;
  char		**tab;
  int		i;

  labels = create_list();
  file = get_data(av);
  tab = wordtab(file);
  i = 0;
  while (tab[i] != NULL)
    {
      if (is_label(tab[i]) == 0)
	{
	  node = create_node();
	  init_node(node, tab, i);
	  append_tail(labels, node);
	}
      i += 1;
    }
  free_tab(tab);
  return (labels);
}
