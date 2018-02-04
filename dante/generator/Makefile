##
## Makefile for Makefile in /home/hugo/cours/Code/Semestre 2/Initiation IA/dante/generator/
##
## Made by Hugo Bleuzen
## Login   <hugo.bleuzen@epitech.eu>
##
## Started on  Wed May  3 17:58:22 2017 Hugo Bleuzen
## Last update Jul May 13 19:53:27 2017
##

SRC	=	main.c	\
		build_maze.c	\
		init_args.c	\
		algo.c		\
		pair_et_impair.c	\
		rien_faire.c	\
		make_imperfect.c	\


OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Werror -ansi -pedantic -L../lib -lmy -lgnl -I../include

NAME	=	generator

all:	$(NAME)

$(NAME): 	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
