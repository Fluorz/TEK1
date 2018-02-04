/*
** my_strlen.c for my strlen.c in /home/leo/CPool_Day04
** 
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
** 
** Started on  Thu Oct  6 17:48:47 2016 leo lecherbonnier
** Last update Thu Oct  6 22:41:00 2016 leo lecherbonnier
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
