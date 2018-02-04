##
## Makefile for Makefile in /home/lecherbonnier/Bureau/bswireframe/src/
##
## Made by Leo Lecherbonnier
## Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
##
## Started on  Wed Dec  7 08:55:12 2016 Leo Lecherbonnier
## Last update Tue Jan 24 09:57:23 2017 Leo Lecherbonnier
##

SRC	=	main_file.c	\
			frame_buffer_create.c	\
			my_draw_line.c	\
			my_put_pixel.c	\
			clear_window.c	\
			background.c	\
			move_forward.c	\
			raycast.c	\
			parsing.c	\
			move.c	\
			wall.c	\
			minimap.c	\
			cross.c

OBJ	=	$(SRC:.c=.o)

CFLAG = -W -Werror -Wall -Wextra -lc_graph_prog -lm

NAME	=	wolf3d

all:	$(NAME)

$(NAME): 	$(OBJ)
		gcc $(OBJ) $(CFLAG) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
