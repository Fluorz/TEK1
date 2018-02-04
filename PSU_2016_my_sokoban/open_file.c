/*
** open_file.c for open_file.c in /root/Desktop/CPE/CPE_2016_BSQ/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Mon Dec 12 08:20:25 2016 Leo Lecherbonnier
** Last update Tue Dec 20 17:42:21 2016 Leo Lecherbonnier
*/

#include <sokoban.h>

char	*fs_open_file(char* filepath, int *ligne)
{
  char	c;
  char  *str;
  int	fd;
  int	i;
  struct stat	buf;

  stat(filepath, &buf);
  if (buf.st_size == 0)
    exit (-1);
  if ((fd = open(filepath, O_RDONLY)) <= 0)
    exit(-1);
  if ((str = malloc(sizeof(char) * buf.st_size + 2)) == NULL)
    exit(-1);
  i = 0;
  while (read(fd, &c, 1) != 0)
    {
      str[i] = c;
      if (str[i] == '\n')
	*ligne = *ligne + 1;
      i++;
    }
  str[i] = '\0';
  i = 0;
  close(fd);
  return (str);
}
