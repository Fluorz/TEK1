/*
** r_option.c for r_option.c in /root/Desktop/PSU_2016_my_ls/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Wed Nov 30 21:05:14 2016 Leo Lecherbonnier
** Last update Sun Dec  4 11:01:08 2016 Leo Lecherbonnier
*/

#include "ls.h"

void	read_r_repo(DIR* rep, char* chemin)
{
  struct dirent* ent;
  struct stat	list;

  ent = NULL;
  while ((ent = readdir(rep)) != NULL)
    {
      stat(ent->d_name, &list);
      if (ent->d_name[0] != '.' && ent != NULL)
	{
	  my_printf("%s\n", ent->d_name);
	}
    }
}

void	read_recursive(DIR* rep)
{
  struct dirent* ent;
  struct stat	list;
  DIR*		tmp;

  ent = NULL;
  while ((ent = readdir(rep)) != NULL)
    {
      stat(ent->d_name, &list);
      if ((list.st_mode & S_IFDIR) != 0 && ent->d_name[0] != '.')
	{
	  my_printf("%s%s\n", "./", ent->d_name);
	  tmp = opendir(ent->d_name);
	  while ((ent = readdir(tmp)) != NULL)
	   {
	      stat(ent->d_name, &list);
	      if (ent->d_name[0] != '.' && ent != NULL)
		  my_printf("%s\n", ent->d_name);
	    }
	}
    }
}

void	check_r_repo(char* chemin)
{
  DIR* rep;

  rep = opendir(chemin);
  if (!rep)
    {
      my_printf("Le dossier '%s' n'a pas pu etre ouvert", chemin);
      exit(-1);
    }
  read_r_repo(rep, chemin);
  closedir(rep);
  rep = opendir(chemin);
  read_recursive(rep);
  closedir(rep);
  return;
}
