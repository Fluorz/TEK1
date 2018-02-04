##
## Makefile for Makefile in /root/PSU_2016_my_printf/
##
## Made by Leo Lecherbonnier
## Login   <leo.lecherbonnier@epitech.eu>
##
## Started on  Mon Nov 14 10:17:19 2016 Leo Lecherbonnier
## Last update Mon Nov 21 14:40:37 2016 Lecherbonnier
##

SRC	=	my/my_printf.c	\
		my/flag.c		\
		my/my_put_nbr.c	\
		my/base.c		\
		my/my_put_nbr1.c	\
		my/flag1.c		\
		my/flag2.c		\
		my/my_putstr.c	\
		my/my_putstr1.c	\
		my/my_showmem.c	\
		my/my_showstr.c	\
		my/my_sort_int_tab.c	\
		my/my_square_root.c	\
		my/my_strcapitalize.c \
		my/my_strcat.c			\
		my/my_strcmp.c		\
		my/my_strcpy.c			\
		my/my_strlen.c		\
		my/my_revstr.c	\
		my/my_putchar.c	\
		my/my_find_prime_sup.c	\
		my/my_getnbr.c					\
		my/my_isneg.c			\
		my/my_is_prime.c	\
		my/my_power_rec.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-L./lib -lmy -I./include

NAME	=	libmy.a

all:	$(NAME)

$(NAME): 	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
