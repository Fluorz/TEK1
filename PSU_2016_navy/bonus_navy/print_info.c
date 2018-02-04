/*
** print_info.c for print_info.c in /home/lecherbonnier/Projet/PSU_2016_navy/leo/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed Feb  1 15:43:55 2017 Leo Lecherbonnier
** Last update Mon Feb 13 11:25:27 2017 Leo Lecherbonnier
*/

#include "navy.h"

void	print_info(void)
{
  my_printf("USAGE\n");
  my_printf("\t./navy [first_player_pid] navy_positions\n\n");
  my_printf("DESCRIPTION\n");
  my_printf("\tfirst_player_pid\tonly for the 2nd player. ");
  my_printf("pid of the first player.\n");
  my_printf("\tnavy_positions\t\tfile ");
  my_printf("representing the positions of the ships.\n");
  return;
}
