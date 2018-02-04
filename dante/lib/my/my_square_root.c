/*
** my_square_root.c for my_square_root.c in /home/leo/CPool_Day05
**
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
**
** Started on  Mon Oct 10 09:15:31 2016 leo lecherbonnier
** Last update Sat Feb 11 11:29:18 2017 Leo Lecherbonnier
*/

int	my_square_root(int nb)
{
  int	i;

  i = 0;
  while ((i * i) < nb)
    {
      if ((i * i) == nb)
	{
	  return (i);
	}
      i = i + 1;
    }
  return (i);
}
