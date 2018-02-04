##
## Makefile for Makefile in /home/monty/Documents/lib/
##
## Made by Monty Criel
## Login   <monty.criel@epitech.eu>
##
## Started on  Fri Nov 25 14:31:49 2016 Monty Criel
## Last update Tue Feb 21 23:53:36 2017 Leo Lecherbonnier
##

SRC	=	main.c				\
			create_map.c	\
			player.c			\
			ia.c					\
			move_pipe.c		\
			check_end_game.c	\
			action.c					\
			handler.c			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Werror -pedantic -L./lib -lmy -I./include -lgnl

NAME	=	matchstick

all:	$(NAME)

$(NAME): 	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
