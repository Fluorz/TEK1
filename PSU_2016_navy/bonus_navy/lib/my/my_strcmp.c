/*
** my_strcmp.c for my str cmp in /home/monty.criel/Rendu/CPool_Day07/lib/my
**
** Made by Monty Monty
** Login   <monty.criel@epitech.net>
**
** Started on  Tue Oct 11 09:42:12 2016 Monty Monty
** Last update Sun Jan 22 15:26:08 2017 Monty Criel
*/

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while ((str1[i] == str2[i]) && (str1[i] != '\0') && (str2[i] != '\0'))
    i = i + 1;
  return (str1[i] - str2[i]);
}
