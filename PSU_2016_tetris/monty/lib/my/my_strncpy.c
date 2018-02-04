/*
** my_strncpy.c for my str n cpy in /home/monty.criel/Exercices piscines beta/CPool_Day06
** 
** Made by Monty Monty
** Login   <monty.criel@epitech.net>
** 
** Started on  Mon Oct 10 10:44:41 2016 Monty Monty
** Last update Fri Oct 14 15:08:12 2016 Monty Monty
*/

int	my_strlen(char *str);

char	*my_strncpy(char *dest, char *src, int n)
{
  int   i;
  int	lenght;

  i = 0;
  lenght = my_strlen(src);
  if (n > lenght)
    {
      while (src[i] != '\0')
	{
	  dest[i] = src[i];
	  i = i + 1;
	}
      return (dest);
    }
  else
    {
      while (i < n)
	{
	  dest[i] = src[i];
	  i = i + 1;
	}
      return (dest);
    }
  return (dest);
}
