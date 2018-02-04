/*
** instruction_name.c for corewar in /home/sid/Corewar
**
** Made by Sid
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Fri Mar 31 23:16:46 2017 Sid
** Last update Mon Apr  3 00:05:27 2017 Sid
*/

#include "error.h"

int	good_label(char *str, char **labels)
{
  int	i;

  i = 0;
  while (labels[i] != NULL)
    {
      if (my_strcmp(labels[i], str) == 0)
	return (0);
      i++;
    }
  return (-1);
}

char	check_args_syntax(char *str, char **labels)
{
  if (str[0] == 'r' && my_str_isnum(str + 1) == 0)
    {
      if (my_getnbr(str + 1) > 0 && my_getnbr(str + 1) <= REG_NUMBER)
	return (T_REG);
    }
  else if (str[0] == DIRECT_CHAR)
    {
      if (str[1] == LABEL_CHAR)
	{
	  if (good_label((str + 2), labels) == 0)
	    return (T_DIR);
	}
      else if (my_str_isnum(str + 1) == 0)
	return (T_DIR);
    }
  else if (my_str_isnum(str) ||
	   (str[0] == LABEL_CHAR && good_label(str + 1, labels) == 0))
    return (T_IND);
  return (0);
}

int	check_args_types(char **instruction, char **labels,
			 char *line, int i)
{
  int	j;
  int	k;
  char	type;

  j = 1;
  k = 0;
  if (find_label(line) == 0)
    j = 2;
  while (instruction[j] != NULL)
    {
      if ((type = check_args_syntax(instruction[j], labels) == 0 ||
	    !(type & op_tab[i].type[k])))
	{
	  my_printf("Error : Wrong argument.\n");
	  return (-1);
	}
      j++;
      k++;
    }
  return (0);
}

int	check_nbr_arg(char **instruction, char *line, char *file_name, int i)
{
  int	j;

  j = 0;
  if (find_label(line) == 0)
    {
      j = 1;
      while (instruction[j] != NULL)
        j++;
      if (op_tab[i].nbr_args != (j - 2))
        {
          my_printf("Error : %s: ", file_name);
          my_printf("instruction is invalid: '%s'\n", instruction[1]);
          return (-1);
        }
      return (0);
    }
  while (instruction[j] != NULL)
    j++;
  if (op_tab[i].nbr_args != (j - 1))
    {
      my_printf("Error : %s: The number of argument given to the", file_name);
      my_printf(" instruction is invalid: %s\n", instruction[0]);
      return (-1);
    }
  return (0);
}

char	**find_instruction(char *line)
{
  char	**instruction;
  int	i;

  i = 0;
  if (find_label(line) == 0)
	 i = 1;
  else if (line[0] == COMMENT_CHAR)
    return (NULL);
  instruction = str_to_wordtab(line, SEPARATOR_CHAR);
  while (instruction[i] != NULL)
	{
    if (my_strcmp(instruction[i], ";") == 0 || instruction[i][0] == '#')
	    return (NULL);
	  i++;
  }
  return (instruction);
}
