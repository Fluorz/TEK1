##
## Makefile for Makefile in /root/PSU_2016_my_printf/
##
## Made by Leo Lecherbonnier
## Login   <leo.lecherbonnier@epitech.eu>
##
## Started on  Mon Nov 14 10:17:19 2016 Leo Lecherbonnier
## Last update Thu Nov 17 10:42:22 2016 Leo Lecherbonnier
##

SRC	=	main_file.c	\
		flag.c		\
		my_put_nbr.c	\
		base.c		\
		my_put_nbr1.c	\
		flag1.c		\
		flag2.c		\
		lib/my/my_putstr.c	\
		lib/my/my_revstr.c	\
		lib/my/my_putchar.c

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
