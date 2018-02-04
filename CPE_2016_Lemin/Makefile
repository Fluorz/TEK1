##
## Makefile for Makefile in /home/lecherbonnier/Projet/CPE_2016_Lemin/
##
## Made by Leo Lecherbonnier
## Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
##
## Started on  Sun Apr 30 10:48:18 2017 Leo Lecherbonnier
## Last update Jan Apr 30 22:31:08 2017
##

SRC	=	src/main.c			\
		src/epure_tab.c			\
		src/bad_epure_tab.c		\
		src/gestion_erreur.c		\
		src/get_file.c			\
		src/take.c			\
		src/new_game.c			\
		src/find_way.c			\
		src/road.c			\
		src/first_road.c		\
		src/second_road.c		\
		src/new_game_else.c		\
		src/else_epure_tab.c		\
		src/sort_data.c			\
		src/sort_data_bis.c		\
		src/check_before.c		\
		src/duplicate_name.c		\
		src/check_coordonate.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -pedantic -L./lib -lmy -lgnl -I./include

NAME	=	lem_in

all:	$(NAME)

$(NAME): 	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
