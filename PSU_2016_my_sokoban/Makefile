##
## Makefile for Makefile in /home/lecherbonnier/Bureau/CPE_2016_Pushswap/
##
## Made by Leo Lecherbonnier
## Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
##
## Started on  Mon Nov 21 14:45:51 2016 Leo Lecherbonnier
## Last update Tue Dec 20 19:18:21 2016 Leo Lecherbonnier
##

CFLAGS2 = 	-W -Werror -Wall -Wextra -g3 -pedantic -ansi -lncurses

SRC	= 	main.c	\
		open_file.c	\
		put_in_tab.c	\
		movements.c	\
		compting_o.c	\
		flag.c	\
		colision.c	\
		my_strlen.c

OBJ	=	$(SRC:.c=.o)


NAME	=	my_sokoban

all:	$(NAME)

$(NAME): 	$(OBJ)
		gcc $(OBJ) $(CFLAGS2) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
