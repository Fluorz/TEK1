/*
** create_map.c for create_map.c in /home/lecherbonnier/Projet/CPE_2016_matchstick/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Mon Feb 13 13:21:22 2017 Leo Lecherbonnier
** Last update Thu Feb 16 11:41:52 2017 Leo Lecherbonnier
*/

#include "matchstick.h"

char	**create_map(int nombre_ligne)
{
  int		nombre_caractere = 0;
  int		i = 0;
  char	**map;

  nombre_caractere = (nombre_ligne * 2) - 1 + 2;
  map = xmalloc(sizeof(char) * nombre_ligne * 10);
  map[0] = xmalloc(sizeof(char) * nombre_caractere + 2);
  map[nombre_ligne + 1] = xmalloc(sizeof(char) * nombre_caractere + 2);
  while (i != nombre_caractere)
    {
      map[0][i] = '*';
      i++;
    }
  i = 1;
  while (i != nombre_ligne + 1)
    {
      map[i] = load_str(i - 1, nombre_ligne, nombre_caractere);
      i++;
    }
  map[0][nombre_caractere] = '\n';
  map[nombre_ligne + 1] = my_strcpy(map[nombre_ligne + 1], map[0]);
  map[nombre_ligne + 1][nombre_caractere] = '\n';
  map[nombre_ligne + 1][nombre_caractere + 1] = '\0';
  return (map);
}

char	*load_str(int	line, int nombre_ligne, int nombre_caractere)
{
  char	*str = NULL;
  int		first_pipe = 0;
  int		last_pipe = 0;
  int		i = 1;

  str = xmalloc(sizeof(char) * nombre_caractere + 2);
  str[0] = '*';
  first_pipe = nombre_caractere / 2 - line;
  last_pipe = nombre_caractere / 2 + line;
  while (i != nombre_caractere)
    {
      if (i >= first_pipe && i <= last_pipe)
	str[i] = '|';
      else
	str[i] = ' ';
      i++;
    }
  str[nombre_caractere - 1] = '*';
  str[nombre_caractere] = '\n';
  return (str);
}

void	print_map(char **map, int len)
{
  int	j = 0;

  while (j != len)
    {
      my_printf("%s", map[j]);
      j++;
    }
}
