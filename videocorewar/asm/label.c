/*
** label.c for corewar in /home/sid/Corewar
**
** Made by Sid
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Thu Mar 30 03:32:08 2017 Sid
** Last update Mon Apr  3 00:03:35 2017 Sid
*/

#include "error.h"

int   	check_label_chars(char *str, char *file)
{
  int	i;
  int	j;
  int	x;

  i = 0;
  while (str[i] != LABEL_CHAR && str[i] != '\0')
    {
      j = -1;
      x = 1;
      while (LABEL_CHARS[++j] != '\0')
	{
	  if (LABEL_CHARS[j] == str[i])
	    x = 0;
	}
      if (x == 1)
	{
	  my_printf("Error: %s: Forbidden character in label.\n", file);
	  exit(84);
	}
      i++;
    }
  return (i);
}

char	*check_label(char *str, char *file)
{
  int	i;
  char	*label;

  label = NULL;
  i = check_label_chars(str, file);
  if (i == 0)
    {
      my_printf("Error: %s Undefined label.\n", file);
      exit(84);
    }
  else if (str[i] == ':' &&
	   (str[i + 1] != ' ' && str[i + 1] != '\t' && str[i + 1] != '\0'))
    {
      my_printf("Error: %s: Invalid instruction.\n", file);
      exit(84);
    }
  else
    label = my_str_dup(label, my_parse_str(0, i, str));
  return (label);
}

int	find_label(char *str)
{
  int	i;

  i = 0;
  if (str[i] == COMMENT_CHAR || str[i + 1] == COMMENT_CHAR)
    return (-1);
  while (str[i] != '\0')
    {
      if (str[i] == LABEL_CHAR && str[i - 1] != '%')
	return (0);
      i++;
    }
  return (-1);
}

int	check_labels_tab(char **labels)
{
  int	i;
  int	j;

  i = 0;
  while (labels [i] != NULL)
    {
      j = -1;
      while (labels[++j] != NULL)
	{
	  if (my_strcmp(labels[i], labels[j]) == 0 && i != j)
	    {
	      my_printf("Error : Label declared twice or more.\n");
	      exit(84);
	    }
	}
    }
  i++;
  return (0);
}

char	**labels_tab(char **tab, char *file)
{
  char	**labels;
  int	i;
  int	j;
  int	len;
  char	*str;

  i = -1;
  len = 0;
  while (tab[++i] != NULL)
    if (find_label(tab[i]) == 0 && (check_label(tab[i], file) != NULL))
      len++;
  if ((labels = malloc(sizeof(char*) * len + 1)) == NULL)
    return (NULL);
  i = j = 0;
  while (tab[++i] != NULL)
    {
      if (find_label(tab[i]) == 0 &&
	  ((str = check_label(tab[i], file)) != NULL))
	{
	  labels[j] = my_str_dup(labels[j], str);
	  j++;
	}
    }
  labels[j - 1] = NULL;
  return (labels);
}
