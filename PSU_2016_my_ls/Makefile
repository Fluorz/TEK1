##
## Makefile for Makefile in /home/lecherbonnier/Bureau/CPE_2016_Pushswap/
##
## Made by Leo Lecherbonnier
## Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
##
## Started on  Mon Nov 21 14:45:51 2016 Leo Lecherbonnier
## Last update Fri Dec  2 16:32:40 2016 Leo Lecherbonnier
##

CFLAGS	=	-L./lib -lmy -I./include

CFLAGS2 = 	-W -Werror -Wall -Wextra -g3 -pedantic -ansi

SRC	= 	main_file.c	\
		check_fonction.c	\
		pl.c		\
		r_option.c	\
		l_option.c

OBJ	=	$(SRC:.c=.o)


NAME	=	my_ls

all:	$(NAME)

$(NAME): 	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS) $(CFLAGS2)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
