/*
** my_swap.c for my swap in /home/monty.criel/Rendu/CPool_Day04
** 
** Made by Monty Monty
** Login   <monty.criel@epitech.net>
** 
** Started on  Thu Oct  6 15:47:53 2016 Monty Monty
** Last update Fri Oct 14 15:08:31 2016 Monty Monty
*/

int	my_swap(int *a, int *b)
{
  int	swap;

  swap = *a;
  *a = *b;
  *b = swap;
}
