/*
** my_writer.c for my_writer.C in /home/lecherbonnier/Projet/PSU_2016_navy/leo/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Thu Feb  2 13:40:32 2017 Leo Lecherbonnier
** Last update Mon Feb  6 14:29:31 2017 Leo Lecherbonnier
*/

#include "navy.h"

void		my_writer(int bin)
{
  static char c[10];
  static int	i = 0;

  if (i == 7)
    {
      c[i] = bin + 48;
      c[8] = '\0';
      i = 0;
      convert_binaire(c);
      convert_binaire_number(c);
    }
  else
    {
      c[i] = bin + 48;
      i++;
    }
}

void	convert_binaire(char *c)
{
  if (c[0] == '0' && c[1] == '0' && c[2] == '0' && c[3] == '1')
    g_player.position_envoye[0] = 'A';
  if (c[0] == '0' && c[1] == '0' && c[2] == '1' && c[3] == '1')
    g_player.position_envoye[0] = 'B';
  if (c[0] == '0' && c[1] == '1' && c[2] == '1' && c[3] == '1')
    g_player.position_envoye[0] = 'C';
  if (c[0] == '1' && c[1] == '1' && c[2] == '1' && c[3] == '1')
    g_player.position_envoye[0] = 'D';
  if (c[0] == '1' && c[1] == '1' && c[2] == '1' && c[3] == '0')
    g_player.position_envoye[0] = 'E';
  if (c[0] == '1' && c[1] == '1' && c[2] == '0' && c[3] == '0')
    g_player.position_envoye[0] = 'F';
  if (c[0] == '1' && c[1] == '0' && c[2] == '0' && c[3] == '0')
    g_player.position_envoye[0] = 'G';
  if (c[0] == '1' && c[1] == '0' && c[2] == '0' && c[3] == '1')
    g_player.position_envoye[0] = 'H';
  if (c[0] == '0' && c[1] == '0' && c[2] == '0' && c[3] == '0')
    g_player.position_envoye[0] = 'M';
  if (c[0] == '0' && c[1] == '1' && c[2] == '0' && c[3] == '0')
    g_player.position_envoye[0] = 'H';
  return;
}

void	convert_binaire_number(char *c)
{
  if (c[4] == '0' && c[5] == '0' && c[6] == '0' && c[7] == '1')
    g_player.position_envoye[1] = '1';
  if (c[4] == '0' && c[5] == '0' && c[6] == '1' && c[7] == '1')
    g_player.position_envoye[1] = '2';
  if (c[4] == '0' && c[5] == '1' && c[6] == '1' && c[7] == '1')
    g_player.position_envoye[1] = '3';
  if (c[4] == '1' && c[5] == '1' && c[6] == '1' && c[7] == '1')
    g_player.position_envoye[1] = '4';
  if (c[4] == '1' && c[5] == '1' && c[6] == '1' && c[7] == '0')
    g_player.position_envoye[1] = '5';
  if (c[4] == '1' && c[5] == '1' && c[6] == '0' && c[7] == '0')
    g_player.position_envoye[1] = '6';
  if (c[4] == '1' && c[5] == '0' && c[6] == '0' && c[7] == '0')
    g_player.position_envoye[1] = '7';
  if (c[4] == '1' && c[5] == '0' && c[6] == '0' && c[7] == '1')
    g_player.position_envoye[1] = '8';
  if (c[4] == '0' && c[5] == '0' && c[6] == '0' && c[7] == '0')
    g_player.position_envoye[1] = 'I';
}
