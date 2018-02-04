/*
** name_comment.c for corewar in /home/sid/Corewar
**
** Made by Sid
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Tue Mar 28 13:04:53 2017 Sid
** Last update Sun Apr  2 23:51:34 2017 Sid
*/

#include "error.h"

int	check_braket(char **tab, char *name)
{
  int	y;
  int	x;

  y = 1;
  x = 0;
  if (tab[1][0] != '"')
    {
      my_printf("Error : %s Syntax error in name or comment.\n", name);
      return (-1);
    }
  while (tab[y] != NULL)
    y++;
  while (tab[y - 1][x] != '\0')
    x++;
  if (tab[y - 1][x - 1] != '"')
    {
      my_printf("Error : %s: Syntax error in name or comment.\n", name);
      return (-1);
    }
  return (0);
}

int	check_name(char	*str, char *av)
{
  char	**tab;
  int	i;
  int	len;

  i = 0;
  len = 0;
  tab = NULL;
  tab = str_to_wordtab(str, '^');
  if (tab[0] == NULL || my_strcmp(NAME_CMD_STRING, tab[i]) != 0)
    {
      my_printf("Error: %s: No name specified.\n", av);
      return (-1);
    }
  while (tab[++i] != NULL)
    len += my_strlen(tab[i]);
  if ((len - 2) > PROG_NAME_LENGTH)
    {
      my_printf("Error: %s: The program name is too long.\n", av);
      return (-1);
    }
  return (check_braket(tab, av));
}

int	check_comment(char *str, char *av)
{
  char	**tab;
  int	i;
  int	len;

  i = 0;
  len = 0;
  tab = str_to_wordtab(str, ' ');
  if (tab[0] == NULL || my_strcmp(COMMENT_CMD_STRING, tab[i]) != 0)
    {
      my_printf("Warning: %s: No comment specified.\n", av);
      return (1);
    }
  while (tab[++i] != NULL)
    len += my_strlen(tab[i]);
  if ((len - 2) > COMMENT_LENGTH)
    {
      my_printf("Error: %s: The comment is too long.\n", av);
      return (-1);
    }
  return (check_braket(tab, av));
}

int	check_instruct(char **instruction, char **labels,
		       char *line, char *file_name)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (find_label(line) == 0)
    j = 1;
  if (instruction[j] == NULL)
    return (0);
  while (op_tab[i].mnemonique != 0)
    {
      if (my_strcmp(op_tab[i].mnemonique, instruction[j]) == 0)
	break;
      i++;
    }
  if (op_tab[i].code == 0)
    {
      my_printf("Error : %s: wrong instruction : %s\n",
		file_name, instruction[j]);
      return (-1);
    }
    if (check_nbr_arg(instruction, line, file_name, i) == -1)
      return (-1);
    return (0);
}
