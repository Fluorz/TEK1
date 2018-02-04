##
## Makefile for Makefile in /home/monty/Documents/lib/
##
## Made by Monty Criel
## Login   <monty.criel@epitech.eu>
##
## Started on  Fri Nov 25 14:31:49 2016 Monty Criel
## Last update Wed Feb  8 11:18:33 2017 Monty Criel
##

SRC	=	main.c				\
		sig_handler.c			\
		connection.c			\
		print_info.c			\
		send_signal.c			\
		tools_send_signal.c		\
		tools_send_signal_2.c	\
		my_writer.c			\
		player_1.c			\
		player_2.c			\
		attack_ship.c			\
		create_board.c		\
		board_options.c		\
		coord_handler.c		\
		place_ships.c			\
		check_str.c			\
		main_option.c			\
		init_player.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Werror -pedantic -L./lib -lmy -I./include -lgnl

NAME	=	navy

all:	$(NAME)

$(NAME): 	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
