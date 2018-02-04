/*
** l_option.c for l_option.c in /root/Desktop/PSU_2016_my_ls/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Wed Nov 30 09:27:05 2016 Leo Lecherbonnier
** Last update Sun Dec  4 18:32:09 2016 Leo Lecherbonnier
*/

#include "ls.h"

void            print_rights(struct stat dp)
{
  ((dp.st_mode & S_IFDIR) != 0) ? my_putstr("d") : my_putstr("-");
  ((dp.st_mode & S_IRUSR) != 0) ? my_putstr("r") : my_putstr("-");
  ((dp.st_mode & S_IWUSR) != 0) ? my_putstr("w") : my_putstr("-");
  ((dp.st_mode & S_IXUSR) != 0) ? my_putstr("x") : my_putstr("-");
  ((dp.st_mode & S_IRGRP) != 0) ? my_putstr("r") : my_putstr("-");
  ((dp.st_mode & S_IWGRP) != 0) ? my_putstr("w") : my_putstr("-");
  ((dp.st_mode & S_IXGRP) != 0) ? my_putstr("x") : my_putstr("-");
  ((dp.st_mode & S_IROTH) != 0) ? my_putstr("r") : my_putstr("-");
  ((dp.st_mode & S_IWOTH) != 0) ? my_putstr("w") : my_putstr("-");
  ((dp.st_mode & S_IXOTH) != 0) ? my_putstr("x") : my_putstr("-");
}

unsigned int	print_block_allocated(char *dir_name)
{
  unsigned int	block_allocated;
  struct stat	res_stat;
  struct dirent	*read_dir;
  char		*name_with_path;
  DIR		*dir;

  if ((dir = opendir(dir_name)) == NULL)
    return (-1);
  block_allocated = 0;
  while ((read_dir = readdir(dir)))
  {
    if ((name_with_path = my_strcat1(dir_name, read_dir->d_name)) == NULL)
      return (-1);
    if ((lstat(name_with_path, &res_stat)) == 0)
	{
	  if (read_dir->d_name[0] != '.')
	    block_allocated += res_stat.st_blocks;
	}
  }
  closedir(dir);
  my_printf("total %u\n", block_allocated / 2);
  return (0);
}

void	read_l_repo(DIR* rep, char* chemin)
{
  struct dirent* ent;
  struct stat	list;
  struct passwd	*passwd;
  struct group	*group;
  char		*tmp;

  ent = NULL;
  group = getgrgid(group);
  passwd = getpwuid(passwd);
  print_block_allocated(chemin);
  while ((ent = readdir(rep)) != NULL)
    {
      stat(ent->d_name, &list);
      if (ent->d_name[0] != '.' && ent != NULL)
	{
	  tmp = malloc(sizeof(char) * (200));
	  print_rights(list);
          my_strcpy(tmp, ctime(&list.st_mtime));
          my_printf(" %d %s %s\t%d\t", list.st_nlink, passwd->pw_name,
		 group->gr_name, list.st_size);
	  my_print_tmp(tmp);
	  my_printf("%s\n", ent->d_name);
	}
    }
}

void	my_print_tmp(char *tmp)
{
  char	*str;
  int	i;

  i = 4;
  str = my_strncpy(str, tmp, 20, 24);
  while (i != 16)
    {
      if (i <= 10)
	{
	  my_putchar(tmp[i]);
	}
      else if (i > 10)
	{
	  if (my_getnbr(str) == 2016)
	    my_putchar(tmp[i]);
	  else
	    {
	      my_printf(" %d ", my_getnbr(str));
	      return;
	    }
	}
      i++;
    }
  my_putchar(' ');
}

void	check_l_repo(char* chemin)
{
  DIR* rep;

  if (chemin == NULL)
    chemin = malloc(sizeof(char) * 3);
  rep = opendir(chemin);
  if (!rep)
    {
      my_printf("Le dossier '%s' n'a pas pu etre ouvert", chemin);
      exit(-1);
    }
  read_l_repo(rep, chemin);
  closedir(rep);
  return;
}
