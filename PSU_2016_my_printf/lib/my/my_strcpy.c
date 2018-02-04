/*
** my_strcpy.c for my_strcpy.c in /home/leo/CPool_Day06
** 
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
** 
** Started on  Mon Oct 10 09:37:50 2016 leo lecherbonnier
** Last update Fri Oct 14 14:26:49 2016 leo lecherbonnier
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
  return (dest);
}
