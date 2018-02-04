##
## Makefile for Makefile in /root/PSU_2016_minishell1/
##
## Made by Leo Lecherbonnier
## Login   <leo.lecherbonnier@epitech.eu>
##
## Started on  Sat Jan 21 14:08:59 2017 Leo Lecherbonnier
## Last update Tue Apr 11 09:25:45 2017 Leo Lecherbonnier
##

CC	= gcc

SRC	=	src/main.c					\
			src/check_access.c	\
			src/env.c						\
			src/fils.c					\
			src/lib.c						\
			src/my_getenv.c			\
			src/my_getnbr.c			\
			src/my_strcat.c			\
			src/special_case.c	\
			src/str_to_word_tab.c	\
			src/change_env.c			\
			src/setenv.c				\
			src/status.c				\
			src/parsing_setenv.c	\
			src/change_dir.c		\

OBJ	=	$(SRC:.c=.o)

CFLAG		=	-Wall -Werror -W -pedantic -ansi

CFLAGS	=	-L./lib -I./include -lc_graph_prog -lgnl

NAME	=	mysh

all:	$(NAME)

$(NAME): 	$(OBJ)
			gcc $(OBJ) -o $(NAME) $(CFLAGS) $(CFLAG)

clean:
		rm -f $(OBJ)

fclean: clean
			rm -f $(NAME)

re:	fclean all
