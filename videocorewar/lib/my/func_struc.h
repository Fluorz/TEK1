/*
** func_struc.h for function structure in /home/monty/Documents/Projets/Système Unix/PSU_2016_my_printf/
**
** Made by Monty Criel
** Login   <monty.criel@epitech.eu>
**
** Started on  Tue Nov 15 13:54:33 2016 Monty Criel
** Last update Fri Nov 25 16:16:39 2016 Monty Criel
*/

#ifndef FUNC_STRUC_H

#define FUNC_STRUC_H
#include <stdarg.h>
typedef	struct	s_func
{
  void		(*ptrfunc)(va_list);
  char 		key_word;
}		t_func;

void	disp_my_putchar(va_list);
void	disp_my_putstr(va_list);
void	disp_my_put_nbr(va_list);
void	disp_my_put_octal(va_list);
void	disp_my_put_hex1(va_list);
void	disp_my_put_hex2(va_list);
void	disp_my_put_binary(va_list);
void	disp_my_put_address(va_list);
void	disp_my_put_nbr_u(va_list);
void	disp_my_putstr_S(va_list);

#endif /*FUNC_STRUC_H*/
