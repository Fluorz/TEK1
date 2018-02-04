/*
** main.c for need4stek in /home/monty/Documents/Rendu/need4stek/CPE_2016_n4s/bonus/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Sun Jun  4 20:16:44 2017 Monty Criel
** Last update Sun Jun  4 20:41:26 2017 Monty Criel
*/

#include <unistd.h>
#include "controller.h"

int	check_joystick()
{
  if (sfJoystick_isConnected(0) == sfTrue)
    return (1);
  else
    return (0);
}

int			main(int argc, char **argv)
{
  //t_controller	xbox;

  if (argc != 1 || argv[0] == NULL)
    return (84);
  request("start_simulation\n");
  if (check_joystick() == 1)
    write(2, "Ok", 2);
  request("stop_simulation\n");
  return (0);
}
