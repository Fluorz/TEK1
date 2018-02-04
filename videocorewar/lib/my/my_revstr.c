/*
** my_revstr.c for my rev str in /home/monty.criel/Exercices piscines beta/CPool_Day06
** 
** Made by Monty Monty
** Login   <monty.criel@epitech.net>
** 
** Started on  Mon Oct 10 16:41:10 2016 Monty Monty
** Last update Wed Oct 12 09:44:54 2016 Monty Monty
*/

int	my_strlen(char *str);

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}

char	*my_revstr(char *str)
{
  char	tmp;
  int	max;
  int	lenght;
  int	i;

  i = 0;
  lenght = my_strlen(str);
  max = lenght - 1;
  while (i < (lenght - 1) / 2)
    {
      tmp = str[max];
      str[max] = str[i];
      str[i] = tmp;
      max = max - 1;
      i = i + 1;
    }
  return (str);
}
