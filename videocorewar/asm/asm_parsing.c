/*
** asm_parsing.c for corewar.c in /home/monty/Documents/Rendu/corewar/CPE_2016_corewar/ASM/monty/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sat Mar 11 13:31:51 2017 Monty Criel
** Last update Sun Apr  2 21:10:10 2017 Monty Criel
*/

#include <unistd.h>
#include "asm.h"
#include "my.h"

int	get_prog_name(char *file, char *name)
{
  int	size;
  int	i;
  int	x;

  i = 7;
  x = 0;
  while (file[i] != '"')
    {
      name[x] = file[i];
      i += 1;
      x += 1;
    }
  name[x] = '\0';
  return (0);
}

int	get_prog_comment(char *file, char *comment)
{
  int	size;
  int	i;
  int	x;

  i = 0;
  x = 0;
  while (file[i] != '\n')
    i += 1;
  i += 11;
  while (file[i] != '"')
    {
      comment[x] = file[i];
      i += 1;
      x += 1;
    }
  comment[x] = '\0';
  return (0);
}

char	**instruction_list(void)
{
  char	**tab;

  if ((tab = malloc(sizeof(char *) * 17)) == NULL)
    exit(84);
  tab[0] = my_strdup("live");
  tab[1] = malloc(sizeof(char) * 3);
  tab[1][0] = 'l';
  tab[1][1] = 'd';
  tab[1][2] = '\0';
  tab[2] = my_strdup("st");
  tab[3] = my_strdup("add");
  tab[4] = my_strdup("sub");
  tab[5] = my_strdup("and");
  tab[6] = my_strdup("or");
  tab[7] = my_strdup("xor");
  tab[8] = my_strdup("zjmp");
  tab[9] = my_strdup("ldi");
  tab[10] = my_strdup("sti");
  tab[11] = my_strdup("fork");
  tab[12] = my_strdup("lld");
  tab[13] = my_strdup("lldi");
  tab[14] = my_strdup("lfork");
  tab[15] = my_strdup("aff");
  tab[16] = NULL;
  return (tab);
}

char	*mnemonic_list(void)
{
  char	*tab;

  tab = malloc(sizeof(char) * 17);
  if (tab == NULL)
    exit(84);
  tab[0] = 0x01;
  tab[1] = 0x02;
  tab[2] = 0x03;
  tab[3] = 0x04;
  tab[4] = 0x05;
  tab[5] = 0x06;
  tab[6] = 0x07;
  tab[7] = 0x08;
  tab[8] = 0x09;
  tab[9] = 0x0a;
  tab[10] = 0x0b;
  tab[11] = 0x0c;
  tab[12] = 0x0d;
  tab[13] = 0x0e;
  tab[14] = 0x0f;
  tab[15] = 0x10;
  tab[16] = '\0';
  return (tab);
}

char	get_mnemonic(char *inst)
{
  char	**list;
  char	*tab;
  char	code;
  int	i;

  i = 0;
  tab = mnemonic_list();
  list = instruction_list();
  while (list[i] != NULL)
    {
      if (my_strcmp(inst, list[i]) == 0)
	{
	  code = tab[i];
	  free(tab);
	  free_tab(list);
	  return (code);
	}
      i += 1;
    }
  exit(84);
}
