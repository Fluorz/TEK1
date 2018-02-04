/*
** my_putstr1.c for pustr modified in /root/CPool_infinadd/lib/my/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Tue Oct 25 14:54:54 2016 Leo Lecherbonnier
** Last update Tue Oct 25 14:55:33 2016 Leo Lecherbonnier
*/

void    my_putchar(char c);

int	my_putstr1(char *str)
{
  int	i;

  i = 1;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
