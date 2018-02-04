##
## Makefile for makefile in /root/101pong/
##
## Made by Leo Lecherbonnier
## Login   <leo.lecherbonnier@epitech.eu>
##
## Started on  Mon Nov  7 14:34:56 2016 Leo Lecherbonnier
## Last update Tue Nov  8 13:47:21 2016 Leo Lecherbonnier
##

SRC	=	speed_vector.c	\
		angle.c		\
		main_file.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-L./lib -lmy -I./include -lm

NAME	=	101pong

all:	$(NAME)

$(NAME): 	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
