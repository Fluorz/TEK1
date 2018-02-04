/*
** write_tools.c for need4stek in /home/monty/Documents/Rendu/need4stek/CPE_2016_n4s/src/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Thu Jun  1 16:11:19 2017 Monty Criel
** Last update Sun Jun  4 20:20:04 2017 Monty Criel
*/

#include <unistd.h>
#include <string.h>
#include <gnl.h>

char	*request(char *query)
{
  char	*str;

  write(1, query, strlen(query));
  str = get_next_line(0);
  return (str);
}

void	debug(char *str)
{
  write(2, str, strlen(str));
  write(2, "\n", 1);
}
