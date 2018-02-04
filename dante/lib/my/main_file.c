/*
** main_file.c for main_file in /root/PSU_2016_my_printf/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu>
**
** Started on  Mon Nov 14 10:17:03 2016 Leo Lecherbonnier
** Last update Sat Feb 11 13:17:49 2017 Leo Lecherbonnier
*/

#include "my.h"

g_flag	flags[] =
{
  	{'d', &flag_d},
  	{'c', &flag_c},
  	{'i', &flag_i},
  	{'s', &flag_s},
  	{'S', &flag_S},
  	{'x', &flag_x},
  	{'X', &flag_X},
  	{'p', &flag_p},
  	{'b', &flag_b},
  	{'o', &flag_o},
  	{'u', &flag_u},
	{'%', &print_percentage},
	{'P', &flag_P},
  	{0, NULL}
};

int	my_printf(char *str, ...)
{
  va_list valist;
  int	i = 0;
  int	m = 0;

  va_start(valist, str);
  if (str[i] != '\0')
    {
      while (str[i] != '\0')
	{
	  m = 0;
	  if (str[i] == '%' && check_after_percentage(str, i + 1) == 1)
	    {
	      while (flags[m].arr != str[i + 1])
		m++;
	      flags[m].s_flag(valist);
	      i++;
	    }
	  else
	    my_putchar(str[i]);
	  i++;
	}
    }
  va_end(valist);
  return (0);
}

int	check_after_percentage(char *str, int i)
{
  if (str[i] == 'd' || str[i] == 'c' || str[i] == 'i' ||
      str[i] == 's' || str[i] == 'S' || str[i] == 'x' ||
      str[i] == 'X' || str[i] == 'p' || str[i] == 'b' ||
      str[i] == 'o' || str[i] == 'u' || str[i] == '%' ||
      str[i] == 'P')
    return (1);
return (84);
}
