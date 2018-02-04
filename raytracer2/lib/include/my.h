/*
** my.h for my.h in /home/pierre/work/Unix_System/PSU_2016_my_printf/
**
** Made by Pierre Narcisi
** Login   <pierre.narcisi@epitech.eu>
**
** Started on  Wed Nov  9 12:44:08 2016 Pierre Narcisi
** Last update Sun Feb 26 21:47:00 2017 John Doe
*/

#ifndef __MY__
# define __MY__
#include <stdarg.h>
#include <stdio.h>

typedef struct	s_params
{
  char		c;
  void		(*disp)(va_list pa, int *m);
}		t_params;

typedef struct s_f
{
  int i;
  int n;
  int m;
}             t_f;

int	my_printf(char *str, ...);
void	my_putstrS(char *str, int *m);
void	my_putstr(char *str, int *m);
void	my_putchar(char c, int *m);
void	my_put_nbr(int nb, int *m);
void	my_put_nbr_base(unsigned int nb, char *base, int *m);
void	disp_char(va_list pa, int *m);
void	disp_str(va_list pa, int *m);
void	disp_int(va_list pa, int *m);
void	disp_X(va_list pa, int *m);
void	disp_u(va_list pa, int *m);
void	disp_x(va_list pa, int *m);
void	disp_o(va_list pa, int *m);
void	disp_b(va_list pa, int *m);
void	disp_S(va_list pa, int *m);
void	disp_p(va_list pa, int *m);
int	my_strlen(char *str);

#endif
