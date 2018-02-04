/*
** send_signal.c for send_signal.c in /home/lecherbonnier/Projet/PSU_2016_navy/leo/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed Feb  1 18:51:14 2017 Leo Lecherbonnier
** Last update Thu Feb  9 13:28:54 2017 Leo Lecherbonnier
*/

#include "navy.h"

void	send_signal(char *str, int pid)
{
  int	caracter;
  int	number;
  int	binaire_caracter;
  int	binaire_number;

  if (my_strcmp(str, "missed") == 0)
    {
      send_hit_or_missed(str, pid);
      return;
    }
  else if (my_strcmp(str, "hit") == 0)
    {
      send_hit_or_missed(str, pid);
      return;
    }
  else if (str[0] == '\0' || str[1] == '\0')
    return;
  caracter = caracter_str(str);
  number= number_str(str);
  binaire_caracter = transform_caracter(caracter);
  binaire_number = transform_number(number);
  send_letter(binaire_caracter, pid);
  send_number(binaire_number, pid);
}

void	send_hit_or_missed(char *str, int pid)
{
  if (my_strcmp(str, "missed") == 0)
    {
      send_letter(10000, pid);
      send_number(10000, pid);
    }
  else if (my_strcmp(str, "hit") == 0)
    {
      send_letter(10100, pid);
      send_number(10000, pid);
    }
  return;
}
