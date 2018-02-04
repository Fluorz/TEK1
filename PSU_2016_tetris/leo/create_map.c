/*
** create_map.c for create_map.c in /home/lecherbonnier/Projet/PSU_2016_tetris/leo/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Wed Mar  1 14:36:44 2017 Leo Lecherbonnier
** Last update Thu Mar  2 13:21:38 2017 Leo Lecherbonnier
*/

#include "leo.h"

char	**create_map()
{
  char	**map = NULL;

  map = malloc(sizeof(char) * 40);
  map[1] = my_strdup("\033[33m**********************************\033[0m");
  return (map);
}
