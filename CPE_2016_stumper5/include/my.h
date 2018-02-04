/*
** my.h for my.h in /home/lecherbonnier/Projet/CPE_2016_stumper5/
**
** Made by Leo Lecherbonnier
** Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
**
** Started on  Fri May 19 13:17:32 2017 Leo Lecherbonnier
** Last update Jun May 19 16:41:05 2017
*/

#include <unistd.h>
#include <stdlib.h>

# define FAILURE -1
# define SUCCESS 0

# define TRUE 0
# define FALSE 1

typedef struct s_param
{
  int	number;
  char	*str_number;
  char	*swag;
}		t_param;

typedef struct	s_func
{
  char			*(*ptrfunc)(int swag, char c);
  char 		key;
}			t_func;

int	print_nb_leo(char *nbr, char *swag);

/*param*/
t_param		*get_param(char **av);
t_param	*check_before_return(t_param *param, int boole);

/*brut*/
char	*str_zero(int swag, char c);
char	*str_one(int swag, char c);
char	*str_two(int swag, char c);
char	*str_three(int swag, char c);
char	*str_four(int swag, char c);
char	*str_five(int swag, char c);
char	*str_six(int swag, char c);
char	*str_seven(int swag, char c);
char	*str_eight(int swag, char c);
char	*str_nine(int swag, char c);

/*lib.c*/
int	print_number(char *nb, char *swag);

char	*copy(char *string);
int	insert_swag(char *str, char c);
int	my_strcmp(char *str, char *dest);
int	my_str_is_num(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
char	*my_strcat(char *str, char *dest);
