/*
** get_next_line.c for gnl in /home/abdel/CPE_2016_getnextline
** 
** Made by Abderrahim CHERKAOUI
** Login   <abdel@epitech.net>
** 
** Started on  Sat Jan 14 18:22:04 2017 Abderrahim CHERKAOUI
** Last update Wed Mar  1 11:58:49 2017 Cherkaoui
*/

#include "gnl.h"
#include "../my.h"

void	my_free(char *l)
{
  if (l)
    free(l);
}

static int	my_static_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

static char	*my_copy(char *d, char *str, int n)
{
  int		i;

  i = 0;
  while (str[i] != '\0' && i < n)
    {
      d[i] = str[i];
      i = i + 1;
    }
  if (n < i)
    d[i] = '\0';
  return (d);
}

static char	*plus(char *l, int t, char *b, int *s)
{
  char		*nl;
  int		o;
  int		v;

  if (l != 0)
    o = my_static_strlen(l);
  else
    o = 0;
  nl = malloc((o + t + 1) * sizeof(*nl));
  if (nl == NULL)
    return (NULL);
  if (l != 0)
    my_copy(nl, l, o);
  else
    my_copy(nl, "", o);
  v = o + t;
  nl[v] = 0;
  my_copy(nl + o, b + *s, t);
  my_free(l);
    *s = *s + (t + 1);
  return (nl);
}

char		*get_next_line(const int fd)
{
  static char	buff[READ_SIZE];
  static int	i = 0;
  static int	s;
  t_my_gnl	gn;

  gn.line = 0;
  gn.treat = 0;
  while (1 == 1)
    {
      if (i <= s)
	{
	  s = 0;
	  if (!(i = read(fd, buff, READ_SIZE)))
	    return (gn.line);
	  if (i == -1)
	    return (NULL);
	  gn.treat = 0;
	}
      if (buff[s + gn.treat] == '\n')
	return (gn.line = plus(gn.line, gn.treat, buff, &s));
      if (s + gn.treat == i - 1)
	gn.line = plus(gn.line, gn.treat + 1, buff, &s);
      gn.treat = gn.treat + 1;
    }
}
