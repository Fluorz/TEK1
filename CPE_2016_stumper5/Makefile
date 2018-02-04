##
## Makefile for stumper5 in /home/monty/Documents/colle/CPE_2016_stumper5/
##
## Made by Monty Criel
## Login   <monty.criel@epitech.eu@epitech.eu>
##
## Started on  Fri May 19 13:21:12 2017 Monty Criel
## Last update Fri May 19 16:29:35 2017 Monty Criel
##

CC	=	gcc

SRC	=	./src/main.c		\
		./src/get_param.c	\
		./src/lib.c		\
		./src/print_number.c	\
		./src/first_numbers.c	\
		./src/last_numbers.c	\
		./src/helper_funcs.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -ansi -pedantic -I ./include

NAME	=	crocus

all:	$(NAME)

$(NAME): 	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
