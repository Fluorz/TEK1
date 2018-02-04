/*
** my_str_to_wordtab.c for 42sh in /home/sid/PSU_2016_42sh/src/parser/tools
**
** Made by Sid
** Login   <sid.djilali-saiah@epitech.eu>
**
** Started on  Tue May 30 16:15:05 2017 Sid
** Last update Thu Jun  8 11:33:53 2017 Sid Djilali Saiah
*/

#include "parser.h"

int     check_command_chars(char *str)
{
  int   i;
  int   j;
  bool  good_char;

  i = 0;
  while (str[i] != '\0')
    {
      j = -1;
      good_char = false;
      while (ALPHA_CHARS[++j] != '\0')
	{
	  if (ALPHA_CHARS[j] == str[i])
	    good_char = true;
	}
      j = -1;
      while (NUME_CHARS[++j] != '\0')
	{
	  if (NUME_CHARS[j] == str[i])
	    good_char = true;
	}
      if (good_char == false)
	return (-1);
      i++;
    }
  return (0);
}

char	*epur_str(char *str)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (str[++i] != '\0' && str != NULL)
    {
      if (str[i] != ' ' && str[i] != '\t')
	{
	  str[j] = str[i];
	  j++;
	  if (str[i + 1] == ' ' || str[i + 1] == '\t')
	    {
	      str[j] = ' ';
	      j++;
	    }
	}
    }
  str[j] = '\0';
  if (str[j - 1] == ' ')
    str[j - 1] = '\0';
  return (str);
}

int	nb_lines(char *str, char c)
{
  int	i;
  int	lines;

  i = 0;
  lines = 1;
  while (str[i] == c)
    i++;
  while (str[i])
    {
      if (str[i] == c)
	{
	  while (str[i] == c)
	    i++;
	  if (str[i])
	    lines++;
	}
      if (str[i])
	i++;
    }
  return (lines);
}

char	**my_str_to_wordtab(char *str, char c)
{
  char	**tab;
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  if ((tab = malloc(sizeof(char *) * ((nb_lines(str, c) + 1)))) == NULL)
    return (NULL);
  while (str[i] == c)
    i++;
  while (str[i])
    {
      if ((tab[j] = malloc(sizeof(char) * (strlen(str) + 1))) == NULL)
	return (NULL);
      k = 0;
      while (str[i] != c && str[i])
	tab[j][k++] = str[i++];
      tab[j++][k] = '\0';
      while (str[i] == c)
	i++;
    }
  tab[j] = NULL;
  return (tab);
}

char	**create_command_tab(char *str, char c)
{
  char	**tab;
  int	i;

  i = -1;
  if (check_command_chars(str) != 0)
    return (NULL);
  if (!(tab = my_str_to_wordtab(str, c)))
    return (NULL);
  while (tab[++i])
    tab[i] = epur_str(tab[i]);
  return (tab);
}
