##
## Makefile for Makefile in /home/monty/Documents/Projets/Elementary Programmation C/push_swap/
##
## Made by Monty Criel
## Login   <monty.criel@epitech.eu>
##
## Started on  Tue Nov  8 11:55:24 2016 Monty Criel
## Last update Fri Nov 25 15:31:00 2016 Monty Criel
##

CC	=	gcc

SRC	=	disp_my_put_address.c	\
		disp_my_put_binary.c	\
		disp_my_putchar.c	\
		disp_my_put_hex1.c	\
		disp_my_put_hex2.c	\
		disp_my_put_nbr.c	\
		disp_my_put_nbr_u.c	\
		disp_my_put_octal.c	\
		disp_my_putstr.c	\
		disp_my_putstr_S.c	\
		my_find_prime_sup.c	\
		my_getnbr.c		\
		my_isneg.c		\
		my_is_prime.c		\
		my_power_rec.c		\
		my_printf.c		\
		my_putchar.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_revstr.c		\
		my_showmem.c		\
		my_showstr.c		\
		my_sort_int_tab.c	\
		my_sqaure_root.c	\
		my_strcapitalize.c	\
		my_strcat.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_strdup.c		\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c		\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c		\
		my_strlowcase.c		\
		my_strncat.c		\
		my_strncmp.c		\
		my_strncpy.c		\
		my_strstr.c		\
		my_strupcase.c		\
		my_swap.c		\
		my_charcat.c		\
		my_str_to_wordtab.c

CFLAGS =	-I../include/ -g3

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME): 	$(OBJ)
		ar rc $(NAME) $(OBJ)
		mv libmy.a ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

re:	fclean all
