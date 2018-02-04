/*
** print_info.c for print_info.c in /home/lecherbonnier/Projet/PSU_2016_tetris/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Tue Feb 21 10:08:26 2017 Leo Lecherbonnier
** Last update Mon Mar 13 09:58:20 2017 Leo Lecherbonnier
*/

#include "tetris.h"

int	print_info(char **av)
{
  my_printf("Usage:\t %s [options]\n", av[0]);
  my_printf("Options:\n");
  my_printf("\t--help\t\t\tDisplay this help\n");
  my_printf("\t-l --level={num}\tStart Tetris at level num (def: 1)\n");
  my_printf("\t-kl --key-left={K}\tMove the tetrimino LEFT using the");
  my_printf(" K key (def: left arrow)\n");
  my_printf("\t-kr --key-right={K\tMove the tetrimino RIGHT");
  my_printf(" using the K key (def: right arrow)\n");
  my_printf("\t-kt --key-turn={K}\tTURN the tetrimino");
  my_printf(" clockwise 90d using the K key (def: top arrow)\n");
  my_printf("\t-kd --key-drop={K}\tDROP the tetrimino");
  my_printf(" using the K key (def: down arrow)\n");
  my_printf("\t-kq --key-quit={K}\t");
  my_printf("QUIT the game using the K key (def: ’Q’ key)\n");
  my_printf("\t-kp --key-pause={K}\tPAUSE/RESTART the ");
  my_printf("game using the K key (def: space bar)\n");
  my_printf("\t--map-size={row,col}\tSet the numbers of rows ");
  my_printf("and columns of the map (def: 20,10)\n");
  my_printf("\t--w --without-next\tHide next tetrimino (def: false)\n");
  my_printf("\t-d --debug\t\tDebug mode (def: false)\n");
  return (0);
}
