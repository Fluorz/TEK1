/*
** asm_header.c for corewar in /home/monty/Documents/Rendu/corewar/CPE_2016_corewar/ASM/monty/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sat Mar 11 12:53:43 2017 Monty Criel
** Last update Mon Apr  3 00:26:53 2017 Sid
*/

#include "asm.h"
#include "op.h"

char	**do_it_tab(char **tab)
{
  tab = seperate_label_tab(tab);
  tab = epure_wordtab(tab);
  tab = second_epure(tab);
  return (tab);
}

void	my_memset(void *tab, int val, int size)
{
  int	i;
  char	*str;

  i = 0;
  str = tab;
  while (i < size)
    {
      str[i] = val;
      i += 1;
    }
}

int		create_header(char *av, char *cor_file)
{
  int		fd;
  char		*file;
  header_t	header;

  my_memset(&header, 0, sizeof(header_t));
  fd = open(cor_file, O_CREAT | O_RDWR | O_TRUNC, 0664);
  file = get_data(av);
  get_prog_name(file, header.prog_name);
  get_prog_comment(file, header.comment);
  header.magic = change_endian(COREWAR_EXEC_MAGIC);
  write(fd, &header, sizeof(header_t));
  close(fd);
  return (0);
}
