/*
** my.h for lib in /home/leo/CPool_Day09/include
**
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
**
** Started on  Thu Oct 13 15:10:07 2016 leo lecherbonnier
** Last update Wed Nov 23 18:29:51 2016 Leo Lecherbonnier
*/

#ifndef _PROTOTYPE

# define _PROTOTYPE

# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_flag
{
  	char	arr;
  	void	(*s_flag)(va_list);
}		t_flag;

typedef struct s_hex
{

  	char	arr;
  	void	(*s_hex);
}		t_hex;

typedef struct s_hex1
{

  	char	arr;
  	void	(*s_hex1);
}		t_hex1;

typedef struct s_oct
{

  	char	arr;
  	void	(*s_oct);
}		t_oct;

typedef struct s_binary
{

  	char	arr;
  	void	(*s_binary);
}		t_binary;

typedef struct s_list
{
  int					data;
  struct			s_list *next;
  struct			s_list *prev;
}							t_list;

void	flag_d(va_list valist);
void	flag_c(va_list valist);
void	flag_i(va_list valist);
void	flag_s(va_list valist);
void	flag_S(va_list valist);
void	flag_x(va_list valist);
void	flag_X(va_list valist);
void	flag_p(va_list valist);
void	flag_b(va_list valist);
void	flag_o(va_list valist);
void	flag_u(va_list valist);
void	print_percentage(va_list valist);
void	flag_P(va_list valist);
void	my_putchar(char c);
int	delete(int ac, char **av);
int	same_size1(char *s1, char *s2, char *result);
int	size1(char *s1, char *s2);
void	test(char *s1, char *op, int *i, int *m);
void	minus(char *s2, char *op, char *result);
void	print1(char *result, char *s2, char *op);
int	soustraction(char *s2, char *op, char *result);
void	print(char *result, int i, int r);
int	my_putstr1(char *str);
int	same_size(char *s1, char *s2, char *result);
void	add(char *s2, char *op, char *result);
int	my_isneg(int nb);
void	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nombre);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	len(int c);
char	*int_to_str(int c);
void	print_time(char *c);
int	check_after_percentage(char *str, int i);
int	check_base(int ac, char **av);
int	transform_10(int ac, char **av);
int	transform_less(int j);
int	check_last(char *somme, int ac, char **av);
int	transform_more(int j);
int	transform_more1(int j);
int	transform_less1(int j);
void	my_put_nbr1(unsigned int nb);
int	my_printf(char *str, ...);

#endif
