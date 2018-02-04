/*
** pl.c for pl in /root/Desktop/PSU_2016_my_ls/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Fri Dec  2 14:17:08 2016 Leo Lecherbonnier
** Last update Sun Dec  4 11:10:03 2016 Leo Lecherbonnier
*/

#include "ls.h"

void	handle_dir(struct dirent *d, char *path)
{
  char	*next_dir;

  next_dir = malloc(sizeof(char) * (my_strlen(path)
			  + my_strlen(d->d_name) + 2));
  if (next_dir == NULL)
    exit(84);
  my_strcpy(next_dir, path);
  if ((next_dir[my_strlen(next_dir)]) - 1 != '/')
    {
      my_strcat(next_dir, "/");
    }
  my_strcat(next_dir, d->d_name);
  my_ls(next_dir);
}

void	my_ls(char *path)
{
  DIR	*dir;
  struct dirent	*d;

  dir = opendir(path);
  if (dir == NULL)
    exit(84);
  if (path != NULL)
    my_printf("%s:\n", path);
  while ((d = readdir(dir)) != NULL)
    {
      if (d->d_name[0] != '.')
	{
	  my_printf("%s\n", d->d_name);
	  if (d->d_type == 4)
	    handle_dir(d, path);
	}
    }
  closedir(dir);
}
