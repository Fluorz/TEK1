/*
** my_swap.c for my swap in /home/monty.criel/Rendu/CPool_Day04
**
** Made by Monty Monty
** Login   <monty.criel@epitech.net>
**
** Started on  Thu Oct  6 15:47:53 2016 Monty Monty
** Last update Sun Apr  2 12:33:04 2017 Monty Criel
*/

int	my_swap(int *a, int *b)
{
  int	swap;

  swap = *a;
  *a = *b;
  *b = swap;
  return (0);
}
