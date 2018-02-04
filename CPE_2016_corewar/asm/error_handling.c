/*
** main.c for asm in /home/sid/Corewar
**
** Made by Sid
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Sat Mar 11 12:49:02 2017 Sid
** Last update Sun Apr  2 23:57:22 2017 Sid
*/

#include "my.h"
#include "error.h"

void	display_help(char *name)
{
  my_printf("USAGE\n\t%s file_name[.s]\n\nDESCRIPTION\n\tfile_name\t", name);
  my_printf("file in assembly language to be ");
  my_printf("converted into file_name.cor, an\n");
  my_printf("\t\t\texecutable in the Virtual Machine.\n");
}

t_error	error_handling(t_error error, char **av)
{
  int	i;
  char **instruction;

  i = 2;
  error.file_name = av[1];
  error.file = my_reader(error.file_name);
  error.labels = labels_tab(error.file, av[1]);
  if (check_name(error.file[0], error.file_name) != 0)
    exit(84);
  else if (check_comment(error.file[1], error.file_name) < 0)
    exit(84);
  else if (check_comment(error.file[1], error.file_name) == 1)
    i = 1;
  while (error.file[i] != NULL)
    {
      if ((instruction = find_instruction(error.file[i])) != NULL)
      	{
      	  if (check_instruct(instruction, error.labels,
      			     error.file[i], error.file_name) != 0)
      	    exit(84);
      	}
      i++;
    }
  return (error);
}
