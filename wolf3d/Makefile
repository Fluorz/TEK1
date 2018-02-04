##
## Makefile for Makefile in /home/lecherbonnier/Bureau/bswireframe/src/
##
## Made by Leo Lecherbonnier
## Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
##
## Started on  Wed Dec  7 08:55:12 2016 Leo Lecherbonnier
## Last update Wed Mar  8 10:27:17 2017 Leo Lecherbonnier
##

SRC	=	bonus/main_file.c	\
			bonus/frame_buffer_create.c	\
			bonus/my_draw_line.c	\
			bonus/my_put_pixel.c	\
			bonus/clear_window.c	\
			bonus/background.c	\
			bonus/move_forward.c	\
			bonus/raycast.c	\
			bonus/parsing.c	\
			bonus/move.c	\
			bonus/wall.c	\
			bonus/minimap.c	\
			bonus/cross.c

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
