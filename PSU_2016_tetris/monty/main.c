/*
** main.c for bootstrap tetris in /home/monty/Documents/Rendu/tetris/PSU_2016_btetris/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Tue Feb 21 09:21:46 2017 Monty Criel
** Last update Fri Mar 10 17:44:00 2017 Monty Criel
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "tetris.h"
#include "my.h"

char		*get_data(char *file_name)
{
  int		file;
  char		*buffer;
  struct	stat st;
  int		size;
  int		end;

  if ((file = open(file_name, O_RDONLY)) == -1)
    return (NULL);
  if (stat(file_name, &st) == 0)
    size = st.st_size;
  if ((buffer = malloc(sizeof(char) * (size + 1))) == 0)
    return (NULL);
  end = read(file, buffer, size);
  buffer[end] = '\0';
  close(file);
  return (buffer);
}

int	main(int argc, char **argv)
{
  int	status;

  if (argc != 1)
    return (84);
  status = check_tetrimino();
  return (status);
}
