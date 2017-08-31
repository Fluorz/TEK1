/*
** my_strcpy.c for my str cpy in /home/monty.criel/Exercices piscines beta/CPool_Day06
** 
** Made by Monty Monty
** Login   <monty.criel@epitech.net>
** 
** Started on  Mon Oct 10 08:06:59 2016 Monty Monty
** Last update Fri Oct 14 15:07:55 2016 Monty Monty
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
