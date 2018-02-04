/*
** my_swap.c for my_swap.c in /home/leo/CPool_Day04
** 
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
** 
** Started on  Thu Oct  6 09:35:33 2016 leo lecherbonnier
** Last update Tue Oct 11 20:26:25 2016 leo lecherbonnier
*/

int	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
  return (0);
}
