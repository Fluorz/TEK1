/*
** my.h for lib in /home/leo/CPool_Day09/include
**
** Made by leo lecherbonnier
** Login   <leo@epitech.net>
**
** Started on  Thu Oct 13 15:10:07 2016 leo lecherbonnier
** Last update Tue Nov  8 14:53:58 2016 Leo Lecherbonnier
*/

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
int	my_put_nbr(int nb);
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
int	print_speed(void);
float	speed_x0(int ac, char **av);
float	speed_y0(int ac, char **av);
float	speed_z0(int ac, char **av);
float	x0_t(int ac, char **av);
float	y0_t(int ac, char **av);
float	z0_t(int ac, char **av);
float	calc_angle(int ac, char **av);
