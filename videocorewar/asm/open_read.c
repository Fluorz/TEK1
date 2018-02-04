/*
** open.c for corewar in /home/sid/Corewar/binaires-champ-corewar
**
** Made by Sid
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Mon Mar 27 15:14:03 2017 Sid
** Last update Sun Apr  2 23:36:51 2017 Sid Djilali Saiah
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "error.h"

int	my_opener(char *str)
{
  int	fd;
  int	i;

  i = my_strlen(str);
  if (i < 3 || str[i - 1] != 's' || str[i - 2] != '.')
    {
      display_help(str);
      exit(84);
    }
  if ((fd = open(str, O_RDONLY)) < 0)
    {
      my_printf("Error in function open: No such file or directory.\n");
      exit(84);
    }
  return (fd);
}

int	nb_lines(char *file_name)
{
  int	fd;
  char  buff[2];
  int	lines;

  fd = my_opener(file_name);
  lines = 0;
  while (read(fd, buff, 1))
    {
      if (buff[0] == '\n')
	lines++;
    }
  close(fd);
  return (lines);
}

char	**my_reader(char *file_name)
{
  char	**tab;
  char	*str;
  int	lines;
  int	fd;
  int	i;

  i = 0;
  lines = nb_lines(file_name);
  if ((tab = malloc(sizeof(char *) * lines + 1)) == NULL)
    exit(84);
  fd = my_opener(file_name);
  while ((str = get_next_line(fd)) != NULL)
    {
      if (str[0] != '\0' && str[0] != '#')
	{
	  tab[i] = my_str_dup(tab[i], str);
	  i++;
	}
    }
  tab[i] = NULL;
  close(fd);
  return (tab);
}
