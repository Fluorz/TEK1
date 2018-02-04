##
## Makefile for Makefile in /home/lecherbonnier/Bureau/bswireframe/src/
##
## Made by Leo Lecherbonnier
## Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
##
## Started on  Wed Dec  7 08:55:12 2016 Leo Lecherbonnier
## Last update Fri Mar 17 15:18:40 2017 Leo Lecherbonnier
##

SRC	=	source/main_file.c	\
			source/frame_buffer_create.c	\
			source/my_draw_line.c	\
			source/my_put_pixel.c	\
			source/clear_window.c	\
			source/background.c	\
			source/move_forward.c	\
			source/raycast.c	\
			source/parsing.c	\
			source/wall.c	\
			source/minimap.c	\
			source/cross.c	\
			src/calc_dir_vector.c \
			src/cone.c	\
			src/cylinder.c	\
			src/plane.c	\
			src/rotate.c	\
			src/sphere.c	\
			src/translate.c	\
			source/lib.c	\
			src/light.c	\

OBJ	=	$(SRC:.c=.o)

CFLAG		=	-Wall -Werror -W -pedantic -ansi

CFLAGS	=	-L./lib -I./include -lc_graph_prog -lm

NAME	=	raytracer1

all:	$(NAME)

$(NAME): 	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS) $(CFLAG)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
