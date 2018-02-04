/*
** my.h for my.h in /home/monty.criel/Rendu/CPool_Day09/task02
**
** Made by Monty Monty
** Login   <monty.criel@epitech.net>
**
** Started on  Thu Oct 13 23:32:40 2016 Monty Monty
** Last update Sun Apr  2 23:40:41 2017 Sid Djilali Saiah
*/

#ifndef MY_H
#define MY_H

#include "func_struc.h"

void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_sqaure_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
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
int     my_str_isnum(char *str);
int     my_str_islower(char *str);
int     my_str_isupper(char *str);
int     my_str_isprintable(char *str);
int     my_showstr(char *str);
int     my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_charcat(char *dest, char src);
char	*my_strncat(char *dest, char *src, int nb);
char    *my_strdup(char *src);
int	my_printf(const char *format, ...);
char	*get_next_line(const int fd);
int	my_strcmp(char *str1, char *str2);
char	**my_str_to_wordtab(char *str);

#endif /*MY_H*/
