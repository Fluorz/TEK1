/*
** my_strlen.c for y putstr in /home/monty.criel/Rendu/CPool_Day04
** 
** Made by Monty Monty
** Login   <monty.criel@epitech.net>
** 
** Started on  Thu Oct  6 18:29:16 2016 Monty Monty
** Last update Fri Oct 14 10:04:43 2016 Monty Monty
*/

void	my_putchar(char c);

int	my_putstr(char *str)
{
  int	letter;

  letter = 0;
  while (str[letter] != '\0')
    {
      my_putchar(str[letter]);
      letter = letter + 1;
    }
  return (letter);
}
