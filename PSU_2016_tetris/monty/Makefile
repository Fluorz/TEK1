##
## Makefile for Makefile in /home/monty/Documents/lib/
##
## Made by Monty Criel
## Login   <monty.criel@epitech.eu>
##
## Started on  Fri Nov 25 14:31:49 2016 Monty Criel
## Last update Fri Mar 10 17:50:54 2017 Monty Criel
##

SRC	=	main.c			\
		wordtab.c		\
		tetrimino_handler.c	\
		tetrimino_funcs.c	\
		linked_list.c		\
		sort_list.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-L./lib -lmy -I./include -lgnl -g3

NAME	=	check_tetrimino

all:	$(NAME)

$(NAME): 	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
