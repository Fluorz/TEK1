##
## Makefile for Makefile in /home/lecherbonnier/Projet/CPE_2016_Lemin/leo/
##
## Made by Leo Lecherbonnier
## Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
##
## Started on  Thu Apr 20 13:04:35 2017 Leo Lecherbonnier
## Last update Jun Apr 28 16:55:13 2017
##

SRC	=	src/main.c			\
		src/epure_tab.c			\
		src/gestion_erreur.c		\
		src/get_file.c			\
		src/create_room.c		\
		src/take.c			\
		src/new_game.c			\
		src/way.c			\
		src/my_road.c			\
		src/check_road.c		\
		src/one_road.c			\
		src/two_road.c			\
		src/add_to_end.c		\
		src/error.c			\
		src/link_road.c			\
		src/comp.c			\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -ansi -pedantic -L./lib -lmy -lgnl -I./include

NAME	=	lem_in

all:	$(NAME)

$(NAME): 	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
