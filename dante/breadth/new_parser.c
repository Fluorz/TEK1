/*
** new_parser.c for new_parser.c in /home/lecherbonnier/Projet/dante/astar/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu May 11 13:11:47 2017 Leo Lecherbonnier
** Last update Jul May 13 20:02:34 2017
*/

#include "profondeur.h"

void	rien_faire()
{
  return;
}

char	*fs_open_file(char* filepath)
{
  char  *str = NULL;
  int	fd = 0;
  struct stat	buf;

  stat(filepath, &buf);
  if (buf.st_size == 0)
    exit (-1);
  if ((fd = open(filepath, O_RDONLY)) <= 0)
    exit(-1);
  if ((str = malloc(sizeof(char) * buf.st_size + 2)) == NULL)
    exit(-1);
  if ((read(fd, str, buf.st_size)) < 0)
    rien_faire();
  str[buf.st_size] = '\0';
  close(fd);
  return (str);
}
