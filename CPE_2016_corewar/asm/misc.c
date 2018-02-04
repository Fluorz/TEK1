/*
** misc.c for corewar in /home/monty/Documents/Rendu/corewar/CPE_2016_corewar/ASM/monty/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Wed Mar 29 12:29:57 2017 Monty Criel
** Last update Sun Apr  2 15:23:15 2017 Monty Criel
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char	*get_data(char *file_name)
{
  int	file;
  char	*buff[1024];
  char	*buffer;
  int	count;
  int	end;

  if ((file = open(file_name, O_RDONLY)) == -1)
    exit(84);
  count = 0;
  while (read(file, buff, 1))
    count = count + 1;
  close(file);
  file = open(file_name, O_RDONLY);
  buffer = malloc(sizeof(char) * (count + 1));
  end = read(file, buffer, count);
  buffer[end] = '\0';
  close(file);
  return (buffer);
}

int	get_help(void)
{
  my_putstr("USAGE\n");
  my_putstr("\t./asm file_name[.s]\n\n");
  my_putstr("DESCRIPTION\n");
  my_putstr("\tfile_name\t");
  my_putstr("file in assembly language to be converted into file_name.cor, ");
  my_putstr("an\n\t\t\texecutable in the Virtual Machine.\n");
  return (0);
}

int	binary_to_hex(char *str)
{
  int	byte;
  int	i;
  int	pos;

  i = 0;
  pos = 7;
  byte = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '1')
	byte |= 1 << pos;
      i += 1;
      pos -= 1;
    }
  return (byte);
}

char	*revstr_bin(char *str)
{
  char	*new;
  int	i;
  int	x;

  new = malloc(sizeof(char) * (my_strlen(str) + 1));
  if (new  == NULL)
    exit(84);
  x = 0;
  i = my_strlen(str) - 1;
  while (i != -1)
    {
      new[x] = str[i];
      i -= 1;
      x += 1;
    }
  new[x] = '\0';
  if (my_strlen(new) < 8)
    {
      while (my_strlen(new) != 8)
	new = my_strcat("0", new);
    }
  return (new);
}

char	*convert_bin(int nb)
{
  char	*bin;
  int	rest;
  int	tmp;
  int	size;

  size = 0;
  tmp = nb;
  while (nb > 0)
    {
      rest = nb % 2;
      nb = nb / 2;
      size += 1;
    }
  bin = malloc(sizeof(char) * (size + 1));
  nb = tmp;
  tmp = 0;
  while (nb != 0)
    {
      rest = nb % 2;
      nb = nb / 2;
      bin[tmp] = rest + '0';
      tmp += 1;
    }
  bin[tmp] = '\0';
  return (bin);
}
