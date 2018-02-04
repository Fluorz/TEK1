/*
** main.c for corewar in /home/monty/Documents/Rendu/corewar/CPE_2016_corewar/ASM/monty/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sat Mar 11 12:13:09 2017 Monty Criel
** Last update Mon Apr  3 00:06:16 2017 Sid
*/

#include "linked_list.h"
#include "asm.h"
#include "my.h"

char	*get_cor_name(char *file)
{
  int	i;
  int	len;
  char	*name;

  len = my_strlen(file) - 2;
  name = malloc(sizeof(char) * (len + 1));
  if (name == NULL)
    exit(84);
  i = 0;
  while (file[i] != '.')
    {
      name[i] = file[i];
      i += 1;
    }
  name[i] = '\0';
  name = my_strcat(name, ".cor");
  return (name);
}

int		my_asm(int argc, char **argv)
{
  char		*cor;
  char		*file;
  t_list	*labels;

  if (argc != 2)
    return (84);
  if (my_strcmp(argv[1], "-h") == 0)
    get_help();
  if (argv[1][my_strlen(argv[1]) - 2] != '.' &&
      argv[1][my_strlen(argv[1]) - 1] != 's')
    return (84);
  file = get_data(argv[1]);
  labels = get_labels(argv[1]);
  cor = get_cor_name(argv[1]);
  create_header(argv[1], cor);
  create_instructions(labels, file, cor);
  return (0);
}
