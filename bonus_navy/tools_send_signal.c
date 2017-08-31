/*
** tools_send_signal.c for tools_send_signal.c in /home/lecherbonnier/Projet/PSU_2016_navy/leo/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed Feb  1 19:42:02 2017 Leo Lecherbonnier
** Last update Mon Feb 13 11:31:48 2017 Leo Lecherbonnier
*/

#include "navy.h"

void	send_letter(int	binaire, int pid)
{
  int	one = binaire % 10;
  int	two = binaire / 10 % 10;
  int	tee = binaire / 100 % 10;
  int	fur = binaire / 1000 % 10;

  if (fur == 1)
    kill(pid, SIGUSR1);
  else
    kill(pid, SIGUSR2);
  sleep(0);
  if (tee == 1)
    kill(pid, SIGUSR1);
  else
    kill(pid, SIGUSR2);
  sleep(0);
  if (two == 1)
    kill(pid, SIGUSR1);
  else
    kill(pid, SIGUSR2);
  sleep(0);
  if (one == 1)
    kill(pid, SIGUSR1);
  else
    kill(pid, SIGUSR2);
}

void	send_number(int binaire, int pid)
{
  int	one = binaire % 10;
  int	two = binaire / 10 % 10;
  int	tee = binaire / 100 % 10;
  int	fur = binaire / 1000 % 10;

  sleep(0);
  if (fur == 1)
    kill(pid, SIGUSR1);
  else
    kill(pid, SIGUSR2);
  sleep(0);
  if (tee == 1)
    kill(pid, SIGUSR1);
  else
    kill(pid, SIGUSR2);
  sleep(0);
  if (two == 1)
    kill(pid, SIGUSR1);
  else
    kill(pid, SIGUSR2);
  sleep(0);
  if (one == 1)
    kill(pid, SIGUSR1);
  else
    kill(pid, SIGUSR2);
}

int	transform_caracter(int caracter)
{
  if (caracter == 'A')
    return (10001);
  if (caracter == 'B')
    return (10011);
  if (caracter == 'C')
    return (10111);
  if (caracter == 'D')
    return (11111);
  if (caracter == 'E')
    return (11110);
  if (caracter == 'F')
    return (11100);
  if (caracter == 'G')
    return (11000);
  if (caracter == 'H')
    return (11001);
  else
    return (84);
}

int	transform_number(int	number)
{
  if (number == 1)
    return (10001);
  if (number == 2)
    return (10011);
  if (number == 3)
    return (10111);
  if (number == 4)
    return (11111);
  if (number == 5)
    return (11110);
  if (number == 6)
    return (11100);
  if (number == 7)
    return (11000);
  if (number == 8)
    return (11001);
  else
    return (84);
}
