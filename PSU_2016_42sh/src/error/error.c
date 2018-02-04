/*
** error.c for error.c in /home/lecherbonnier/Projet/PSU_2016_42sh/src/error/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue May 30 17:38:25 2017 Leo Lecherbonnier
** Last update Mar May 30 17:39:19 2017
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	my_error(char *str, int nb)
{
  printf("%s\n", str);
  exit (nb);
}
