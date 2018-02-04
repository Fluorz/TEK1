/*
** my_revstr.c for my_revstr.c in /home/leo/CPool_Day06
** 
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
** 
** Started on  Mon Oct 10 11:17:47 2016 leo lecherbonnier
** Last update Tue Oct 11 09:28:45 2016 leo lecherbonnier
*/

static int      my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  i = i - 1;
  return (i);
}

static int      my_swap(char *a, char *b)
{
  int		c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}

char	*my_revstr(char *str)
{
  int	i;
  int	o;

  o = 0;
  i = my_strlen(str);
  while (o < i)
    {
      my_swap(str + i, str + o);
      i = i - 1;
      o = o + 1;
    }
  return (str);
}
