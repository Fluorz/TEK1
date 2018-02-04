/*
** main.c for ok in /home/abdel/global
**
** Made by abdel cherkaoui
** Login   <abdel@epitech.net>
**
** Started on  Mon Jun  5 13:51:04 2017 abdel cherkaoui
** Last update Fri Jun  9 09:12:40 2017 Sid Djilali Saiah
*/

#include <glob.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "parser.h"

static void	init_add(int *a, int *b, int *c, int *d)
{
  *a = -1;
  *b = -1;
  *c = 0;
  *d = 0;
  return;
}

static char	**add_table(char **tab1, char **tab2, int pos, char **newtab)
{
  int	i;
  int	i2;
  int	i3;
  int	size;

  init_add(&i, &i2, &i3, &size);
  size = tablen(tab1) + tablen(tab2);
  if ((newtab = malloc(sizeof(char *) * (size + 1))) == NULL)
    exit(1);
  while (++i != (size - 1))
    if (i != pos && tab1[i3] != NULL)
      {
	newtab[i] = strdup(tab1[i3]);
	i3++;
      }
    else if (++i3 != pos)
      {
	while (tab2[++i2] != NULL)
	  {
	    newtab[i] = strdup(tab2[i2]);
	    i++;
	  }
	i--;
      }
  return (newtab[i] = NULL, newtab);
}

static char		**globing(char	*str, char **tab, int idx, char **newtab)
{
  glob_t	paths;
  int		ret;

  paths.gl_pathc = 0;
  paths.gl_pathv = NULL;
  paths.gl_offs = 0;
  ret = glob(str, GLOB_NOCHECK | GLOB_NOSORT, NULL, &paths);
  if (ret == 0)
    {
      newtab = add_table(tab, paths.gl_pathv, idx, newtab);
      globfree(&paths);
      return (newtab);
    }
  return (tab);
}

char	**globbing_function(char **tab)
{
  int	i;
  char	**newtab;

  i = -1;
  while (tab[++i] != NULL)
    {
      if (strncmp("*", tab[i], 1) == 0)
	{
	  if ((newtab = globing(tab[i], tab, i, newtab)) == NULL)
	    return (tab);
	  tab = tabdup(newtab , tab);
	  freetab(newtab);
	}
    }
  return (tab);
}
