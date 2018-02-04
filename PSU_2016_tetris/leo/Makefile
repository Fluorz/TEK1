##
## Makefile for Makefile in /home/monty/Documents/lib/
##
## Made by Monty Criel
## Login   <monty.criel@epitech.eu>
##
## Started on  Fri Nov 25 14:31:49 2016 Monty Criel
## Last update Thu Mar  2 22:58:49 2017 Leo Lecherbonnier
##

SRC	=	main.c				\
			create_map.c	\
			print_map.c		\
			init_map.c		\
			init_windiow.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Werror -pedantic -L./lib -lmy -I./include -lgnl -ansi -lncurses

NAME	=	map

all:	$(NAME)

$(NAME): 	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
