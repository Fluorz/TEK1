/*
** my_power_rec.c for my power rec in /home/monty.criel/Exercices piscines beta/CPool_Day05
** 
** Made by Monty Monty
** Login   <monty.criel@epitech.net>
** 
** Started on  Fri Oct  7 15:43:25 2016 Monty Monty
** Last update Fri Oct 14 15:07:21 2016 Monty Monty
*/

int	my_power_rec(int nb, int p)
{
  int	result;

  if (p == 0)
    return (1);
  if (p < 0)
    return (0);
  result = nb * my_power_rec(nb, p - 1);
  return (result);
}
