/*
** main_file.c for main_file.c in /root/Desktop/PSU_2016_my_ls/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Tue Nov 29 15:54:14 2016 Leo Lecherbonnier
** Last update Sun Dec  4 17:23:18 2016 Leo Lecherbonnier
*/

#include "ls.h"

void	read_repo(char* s, DIR* rep)
{
  struct dirent* ent;
  struct stat	list;

  ent = NULL;
  while ((ent = readdir(rep)) != NULL)
    {
      stat(ent->d_name, &list);
      if (ent->d_name[0] != '.')
	my_printf("%s\n", ent->d_name);
    }
  return;
}

void	check_repo(char* chemin)
{
  DIR* rep;

  rep = opendir(chemin);
  if (rep == NULL)
    {
      my_printf("Le dossier '%s' n'a pas pu etre ouvert\n", chemin);
      exit(-1);
    }
  read_repo(chemin, rep);
  closedir(rep);
}

int	main(int ac, char **av)
{
  if (ac == 1)
    check_repo("./");
  if (ac != 1)
    check_option(ac, av);
  return (0);
}
