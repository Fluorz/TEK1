##
## Makefile for Makefile in /home/lecherbonnier/Projet/dante/breadth/
##
## Made by Leo Lecherbonnier
## Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
##
## Started on  Wed May 10 15:43:41 2017 Leo Lecherbonnier
## Last update Jul May 13 19:59:50 2017
##

SRC	=	new_main.c		\
		new_algo.c		\
		new_parser.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -ansi -O3 -pedantic -L../lib -lmy -lgnl -I../include

NAME	=	solver

all:	$(NAME)

$(NAME): 	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
