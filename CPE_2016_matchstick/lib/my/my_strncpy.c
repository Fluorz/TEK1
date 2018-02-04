/*
** my_strncpy.c for my_strcpy.c in /home/leo/CPool_Day06
** 
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
** 
** Started on  Mon Oct 10 11:07:39 2016 leo lecherbonnier
** Last update Tue Oct 11 09:31:43 2016 leo lecherbonnier
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
