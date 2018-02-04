/*
** asm_params.c for corewar in /home/monty/Documents/Rendu/CPE_2016_corewar/ASM/monty/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Sun Apr  2 03:21:41 2017 Monty Criel
** Last update Sun Apr  2 22:32:22 2017 Monty Criel
*/

#include <unistd.h>
#include "linked_list.h"
#include "asm.h"
#include "my.h"

int	decimal_to_hex(int nb)
{
  char	*bin;
  int	hex;

  bin = convert_bin(nb);
  bin = revstr_bin(bin);
  hex = binary_to_hex(bin);
  return (hex);
}

int	fill_param_bytes(char *inst, char *param, int fd)
{
  int	size;
  int	byte;
  int	i;

  if (param[0] == 'r')
    size = 1;
  else if (param[0] == '%')
    size = 10;
  else
    size = 2;
  if ((my_strcmp(inst, "sti") == 0 || my_strcmp(inst, "ldi") == 0 ||
       my_strcmp(inst, "lldi") == 0) && param[0] == '%')
    size = 2;
  byte = 0x00;
  i = 1;
  while (i != size)
    {
      write(fd, &byte, 1);
      i += 1;
    }
  return (0);
}

int	get_param_value(char *param, t_list *labels)
{
  int	val;

  if (param[0] == 'r')
    val = get_register_value(param);
  else if (param[0] == '%' && is_label(param) == 0)
    val = get_label_value(param, labels, "DIR");
  else if (param[0] != '%' && is_label(param) == 0)
    val = get_label_value(param, labels, "IND");
  else if (param[0] == '%' && is_label(param) != 0)
    val = get_dir_value(param);
  else
    val = get_ind_value(param);
  return (val);
}

int	write_parameters(t_list *labels, char **instruction, int fd)
{
  int	i;
  int	val;

  i = 1;
  while (instruction[i] != NULL)
    {
      fill_param_bytes(instruction[0], instruction[i], fd);
      val = get_param_value(instruction[i], labels);
      write(fd, &val, 1);
      i += 1;
    }
  return (0);
}
