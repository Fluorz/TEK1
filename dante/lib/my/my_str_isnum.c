/*
** my_str_isnum.c for my_str_isnum.c in /home/leo/CPool_Day07/lib/my
**
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
**
** Started on  Tue Oct 11 13:46:51 2016 leo lecherbonnier
** Last update Jun Apr 28 17:28:09 2017
*/

int	my_str_isnum(char *str)
{
  int	i = 0;

  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (1);
      i++;
    }
  return (0);
}
