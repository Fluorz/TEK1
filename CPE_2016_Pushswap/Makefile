##
## Makefile for Makefile in /home/lecherbonnier/Bureau/CPE_2016_Pushswap/
##
## Made by Leo Lecherbonnier
## Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
##
## Started on  Mon Nov 21 14:45:51 2016 Leo Lecherbonnier
## Last update Sat Nov 26 11:11:54 2016 Leo Lecherbonnier
##

SRC	= 	main_file.c	\
		suite.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-L./lib -lmy -I./include

CFLAGS2 = -W -Werror -Wall -Wextra -g3

NAME	=	push_swap

all:	$(NAME)

$(NAME): 	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS) $(CFLAGS2)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
