/*
** tools_send_signal_2.c for tolls_send_signal_2.c in /home/lecherbonnier/Projet/PSU_2016_navy/leo/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed Feb  1 19:54:38 2017 Leo Lecherbonnier
** Last update Wed Feb  1 21:10:59 2017 Leo Lecherbonnier
*/

#include "navy.h"

int	caracter_str(char *str)
{
  int	lettre = 0;
  char	c = 'A';

  while (lettre == 0)
    {
      if (str[0] == c)
	lettre = c;
      c++;
    }
  return (lettre);
}

int	number_str(char *str)
{
  int	chiffre = 0;
  int	nombre = 1;

  while (chiffre == 0)
    {
      if (str[1] == nombre + 48)
	chiffre = nombre;
      nombre++;
    }
  return (chiffre);
}
