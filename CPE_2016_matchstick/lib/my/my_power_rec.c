/*
** my_power_rec.c for my_power_rec.c in /home/leo/CPool_Day05
**
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
**
** Started on  Fri Oct  7 17:30:25 2016 leo lecherbonnier
** Last update Sat Feb 11 11:30:06 2017 Leo Lecherbonnier
*/

int	my_power_rec(int nb, int p)
{
  int	result;

  if (p == 0)
    {
      result = 1;
      return (result);
    }
  if (p < 0)
    {
      result = 0;
      return (result);
    }
  if (nb > 0 && p > 1)
    {
      return (result = nb * my_power_rec(nb, (p - 1)));
      result = nb;
      return (result);
    }
  return (84);
}
