##
## Makefile for Makefile in /root/PSU_2016_minishell1/
##
## Made by Leo Lecherbonnier
## Login   <leo.lecherbonnier@epitech.eu>
##
## Started on  Sat Jan 21 14:08:59 2017 Leo Lecherbonnier
## Last update Jun Apr 21 09:16:53 2017
##

SRC	=	main.c	\
		error.c	\
		lib.c	\


OBJ	=	$(SRC:.c=.o)

CFLAG = -W -Werror -Wall -Wextra 

NAME	=	fractals

all:	$(NAME)

$(NAME): 	$(OBJ)
		gcc $(OBJ) $(CFLAG) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
