/*
** misc.c for lemin in /home/monty/Documents/Rendu/lemin/CPE_2016_Lemin/bonus/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Mon Apr 24 13:03:05 2017 Monty Criel
** Last update Sun Apr 30 12:19:32 2017 Monty Criel
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "lemin.h"
#include "my.h"

char	*int_to_str(int nb)
{
  char	*str;
  char	tmpc;
  int	tmp;
  int	i;

  tmp = nb;
  while (tmp > 0)
    {
      tmp = tmp / 10;
      i = i + 1;
    }
  if ((str = malloc(sizeof(char) * i + 1)) == NULL)
    return (NULL);
  i = 0;
  while (nb > 0)
    {
      str[i] = (nb % 10) + '0';
      nb = nb / 10;
      i = i + 1;
    }
  str[i] = '\0';
  tmpc = str[1];
  str[1] = str[0];
  str[0] = tmpc;
  return (str);
}

int	exit_event(t_gui *gui, t_lemin *lemin)
{
  if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
    {
      sfRenderWindow_destroy(gui->window);
      sfSprite_destroy(gui->sprite);
      sfTexture_destroy(gui->texture);
      return (1);
    }
  else
    return (0);
}

char	**get_data(char *file_name)
{
  int	file;
  char	*buff[64];
  char	*buffer;
  char	**tab;
  int	count;
  int	end;

  file = open(file_name, O_RDONLY);
  count = 0;
  while (read(file, buff, 1))
    count = count + 1;
  close(file);
  file = open(file_name, O_RDONLY);
  buffer = malloc(sizeof(char) * (count + 1));
  end = read(file, buffer, count);
  buffer[end] = '\0';
  close(file);
  tab = wordtab(buffer);
  free(buffer);
  return (tab);
}

int	is_number(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if ((str[i] >= '0') && (str[i] <= '9'))
	i += 1;
      else
	return (84);
    }
  return (0);
}

char	*copy_line(char *line)
{
  char	*str;
  int	size;
  int	i;

  size = my_strlen(line);
  str = malloc(sizeof(char) * (size + 1));
  if (str == NULL)
    return (NULL);
  i = 0;
  while (line[i] != '\0')
    {
      str[i] = line[i];
      i += 1;
    }
  str[i] = '\0';
  return (str);
}
