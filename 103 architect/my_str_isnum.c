/*
** my_str_isnum.c for my_str_isnum.c in /home/lecherbonnier/103 architect/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Dec 20 14:28:22 2016 Leo Lecherbonnier
** Last update Tue Dec 20 14:28:31 2016 Leo Lecherbonnier
*/

int	my_str_isnum(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (str == 0)
    return (1);
  if (str[i] == '-')
    i++;
  while (str[i] != '\0')
    {
      if (j > 1)
	return (0);
      if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
	  if (str[i] == '.')
	    j++;
	  i++;
	}
      else
	return (0);
    }
  return (1);
}
