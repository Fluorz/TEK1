##
## Makefile for lemin in /home/monty/Documents/Rendu/lemin/CPE_2016_Lemin/bonus/
##
## Made by Monty Criel
## Login   <monty.criel@epitech.eu@epitech.eu>
##
## Started on  Wed Apr 19 14:38:22 2017 Monty Criel
## Last update Sun Apr 30 22:37:02 2017 Monty Criel
##

CC	=	gcc

SRC	=	get_next_line.c	\
		wordtab.c		\
		wordtab_funcs.c	\
		linked_list.c		\
		init_window.c		\
		init_lemin.c		\
		load_lemin.c		\
		init_ants.c		\
		launch_lemin.c	\
		draw_misc.c		\
		misc.c			\
		my_put_pixel.c	\
		my_draw_line.c	\
		extra.c		\
		main.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-L./lib -lmy -I./include -g3

LDFLAGS =	-lm -pthread -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

NAME	=	visu-hex

all:	$(NAME)

$(NAME): 	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
