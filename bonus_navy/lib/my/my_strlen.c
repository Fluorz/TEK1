/*
** my_strlen.c for my strlen in /home/monty.criel/Rendu/CPool_Day04
** 
** Made by Monty Monty
** Login   <monty.criel@epitech.net>
** 
** Started on  Thu Oct  6 20:52:39 2016 Monty Monty
** Last update Fri Oct 14 10:05:04 2016 Monty Monty
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	letter;

  letter = 0;
  while (str[letter] != '\0')
    {
      letter = letter + 1;
    }
  return (letter);
}
