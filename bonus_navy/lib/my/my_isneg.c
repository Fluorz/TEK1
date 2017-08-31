/*
** my_print_isneg.c for my is neg in /home/monty.criel/Rendu/CPool_Day07/lib/my
** 
** Made by Monty Monty
** Login   <monty.criel@epitech.net>
** 
** Started on  Wed Oct 12 08:42:56 2016 Monty Monty
** Last update Fri Oct 14 15:05:02 2016 Monty Monty
*/

void	my_putchar(char c);

int	my_isneg(int nb)
{
  if (nb < 0)
    {
      my_putchar('N');
    }
    else
      {
        my_putchar('P');
      }
  return (0);
}
