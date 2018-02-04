/*
** print_nb.c for stumper5 in /home/monty/Documents/colle/CPE_2016_stumper5/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu@epitech.eu>
**
** Started on  Fri May 19 13:50:57 2017 Monty Criel
** Last update Fri May 19 16:15:26 2017 Monty Criel
*/

#include "my.h"

t_func flag_list[11] =
{
  {&str_zero, '0'},
  {&str_one, '1'},
  {&str_two, '2'},
  {&str_three, '3'},
  {&str_four, '4'},
  {&str_five, '5'},
  {&str_six, '6'},
  {&str_seven, '7'},
  {&str_eight, '8'},
  {&str_nine, '9'},
  {NULL, -1}
};

int	get_swag(char nb, char *swag, char *c)
{
  int	idx;

  idx = nb - '0';
  if (swag == NULL)
    {
      *c = '0';
      return (-1);
    }
  if ((idx > (my_strlen(swag) - 1)) || (idx < 0))
    {
      *c = '0';
      return (-1);
    }
  *c = swag[idx];
  return (0);
}

char	*find_number(char nb, char *swag)
{
  int	status;
  char	*str;
  int  i;
  char	c;

  i = 0;
  status = get_swag(nb, swag, &c);
  while (flag_list[i].key != -1)
    {
      if (flag_list[i].key == nb)
	{
	  if (status == 0)
	    str = flag_list[i].ptrfunc(TRUE, c);
	  else
	    str = flag_list[i].ptrfunc(FALSE, c);
	  return (str);
	}
      i = i + 1;
    }
  return (NULL);
}

void	print_line(char *str, int line)
{
  int	i;
  char	c;

  if (line == 0)
    i = 0;
  else
    i = (line * 5) + line;
  while (str[i] != '\n')
    {
      c = str[i];
      write(1, &c, 1);
      i += 1;
    }
}

int	print_number(char *nb, char *swag)
{
  int	x;
  int	i;
  char	*str;

  x = 0;
  while (x != 5)
    {
      i = 0;
      while (nb[i] != '\0')
	{
	  str = find_number(nb[i], swag);
	  print_line(str, x);
	  if (nb[i + 1] != '\0')
	    write(1, " ", 1);
	  i += 1;
	  free(str);
	}
      write(1, "\n", 1);
      x += 1;
    }
  return (0);
}
