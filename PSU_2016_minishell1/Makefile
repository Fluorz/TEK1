##
## Makefile for Makefile in /root/PSU_2016_minishell1/
##
## Made by Leo Lecherbonnier
## Login   <leo.lecherbonnier@epitech.eu>
##
## Started on  Sat Jan 21 14:08:59 2017 Leo Lecherbonnier
## Last update Wed Mar  1 08:55:40 2017 Leo Lecherbonnier
##

SRC	=	main.c	\
		check_access.c	\
		my_getenv.c	\
		my_strcat.c	\
		str_to_word_tab.c	\
		lib.c	\
		fils.c	\
		env.c	\
		special_case.c	\
		my_getnbr.c			\


OBJ	=	$(SRC:.c=.o)

CFLAG = -W -Werror -Wall -Wextra -lgnl -L.

NAME	=	mysh

all:	$(NAME)

$(NAME): 	$(OBJ)
		gcc $(OBJ) $(CFLAG) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
