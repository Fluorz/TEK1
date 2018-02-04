##
## Makefile for Makefile in /home/monty/Documents/lib/
##
## Made by Monty Criel
## Login   <monty.criel@epitech.eu>
##
## Started on  Fri Nov 25 14:31:49 2016 Monty Criel
## Last update Sun Mar 19 19:01:45 2017 Monty Criel
##

SRC	=	main.c			\
		print_info.c		\
		init_debug.c		\
		build_debug.c		\
		flag_key.c		\
		flag_key_other.c	\
		print_debug.c		\
		parse_list.c		\
		check_key.c		\
		wordtab.c		\
		tetrimino_handler.c	\
		tetrimino_funcs.c	\
		linked_list.c		\
		linked_list_misc.c	\
		sort_list.c		\
		leo/create_map.c	\
		leo/init_map.c	\
		leo/init_windiow.c	\
		leo/main.c		\
		leo/print_map.c	\
		wordtab_funcs.c	\
		extra.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Werror -pedantic -L./lib -I./include -lgnl -lncurses -lmy

NAME	=	tetris

all:	$(NAME)

$(NAME): 	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
