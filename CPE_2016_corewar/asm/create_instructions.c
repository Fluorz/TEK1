/*
** create_instructions.c for corewar in /home/monty/Documents/Rendu/CPE_2016_corewar/ASM/monty/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Sat Apr  1 15:10:52 2017 Monty Criel
** Last update Sun Apr  2 22:34:39 2017 Monty Criel
*/

#include <sys/types.h>
#include <unistd.h>
#include "asm.h"
#include "my.h"

int	is_instruction(char *str, char **list)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (84);
  while (list[i] != NULL)
    {
      if (my_strcmp(str, list[i]) == 0)
	return (0);
      i += 1;
    }
  return (84);
}

int	get_coding_byte(char **tab)
{
  int	code;
  char	*byte;
  int	i;

  i = 1;
  byte = "";
  while (tab[i] != NULL)
    {
      if (tab[i][0] == 'r')
	byte = my_strcat(byte, "01");
      else if (tab[i][0] == '%')
	byte = my_strcat(byte, "10");
      else
	byte = my_strcat(byte, "11");
      i += 1;
    }
  byte = my_strcat(byte, "00");
  code = binary_to_hex(byte);
  return (code);
}

int	write_coding_byte(char **instruction, int fd)
{
  int	coding_byte;

  coding_byte = get_coding_byte(instruction);
  if (my_strcmp(instruction[0], "live") == 0)
    return (84);
  if (my_strcmp(instruction[0], "zjmp") == 0)
    return (84);
  if (my_strcmp(instruction[0], "fork") == 0)
    return (84);
  if (my_strcmp(instruction[0], "lfork") == 0)
    return (84);
  write(fd, &coding_byte, 1);
  return (0);
}

int	write_instruction(t_list *labels, char **instruction, int fd)
{
  int	code;

  code = get_mnemonic(instruction[0]);
  write(fd, &code, 1);
  write_coding_byte(instruction, fd);
  write_parameters(labels, instruction, fd);
  return (0);
}

int	create_instructions(t_list *labels, char *file, char *cor_file)
{
  char	**tab;
  char	**list;
  char	**instruction;
  int	i;
  int	fd;

  if ((fd = open(cor_file, O_RDWR | O_APPEND)) == -1)
    exit(84);
  tab = wordtab(file);
  tab = do_it_tab(tab);
  list = instruction_list();
  i = 0;
  while (tab[i] != NULL)
    {
      instruction = str_to_wordtab(tab[i], ',');
      if (instruction == NULL)
	exit(84);
      if (is_instruction(instruction[0], list) == 0)
	write_instruction(labels, instruction, fd);
      free_tab(instruction);
      i += 1;
    }
  close(fd);
  return (0);
}
