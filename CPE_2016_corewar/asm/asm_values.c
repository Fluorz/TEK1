/*
** asm_values.c for corewar in /home/monty/Documents/Rendu/corewar/CPE_2016_corewar/ASM/monty/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sun Apr  2 12:10:51 2017 Monty Criel
** Last update Sun Apr  2 23:27:37 2017 Sid
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"

int	get_register_value(char *reg)
{
  int	val;
  int	nb;
  char	*str;
  char	*list;
  int	i;
  int	x;

  i = 1;
  x = 0;
  list = mnemonic_list();
  str = malloc(sizeof(char) * (my_strlen(reg)));
  if (str == NULL)
    exit(84);
  while (reg[i] != '\0')
    {
      str[x] = reg[i];
      x += 1;
      i += 1;
    }
  str[x] = '\0';
  nb = my_getnbr(str);
  val = list[nb - 1];
  free(list);
  return (val);
}

int	get_label_value(char *param, t_list *labels, char *option)
{
  int	val;
  char	*label;

  label = my_find_label(param);
  if (my_strcmp(option, "DIR") == 0)
    val = find_label_value(labels, label);
  else
    {
      val = find_label_value(labels, label);
    }
  return (val);
}

int	get_dir_value(char *param)
{
  char	*str;
  int	val;
  int	nb;
  int	i;
  int	x;

  i = 1;
  x = 0;
  str = malloc(sizeof(char) * (my_strlen(param)));
  while (param[i] != '\0')
    {
      str[x] = param[i];
      x += 1;
      i += 1;
    }
  str[x] = '\0';
  nb = my_getnbr(str);
  val = decimal_to_hex(nb);
  return (val);
}

int	get_ind_value(char *param)
{
  int	val;
  int	nb;

  nb = my_getnbr(param);
  val = decimal_to_hex(nb);
  return (val);
}
