##
## Makefile for Makefile in /home/lecherbonnier/Projet/CPE_2016_corewar/VM/
##
## Made by Leo Lecherbonnier
## Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
##
## Started on  Sat Mar 11 11:55:04 2017 Leo Lecherbonnier
## Last update Sun Apr  2 19:28:59 2017 Cherkaoui
##

SRC	=	./main.c			\
		./utils/fc_base.c		\
		./utils/int_to_str.c		\
		./init_champ.c			\
		./init_arena.c			\
		./print_help.c			\
		./game.c			\
		./get_option.c			\
		./convert_indian.c		\
		./execution.c			\
		./init_else.c			\
		./op.c				\
		./take.c			\
		./debug.c			\
		./instruction.c			\
		./struct_op.c			\
		./live.c			\
		./ld.c				\
		./fork.c			\
		./st.c				\
		./add.c				\
		./start_battle.c		\
		./graph/graph_core.c		\
		./graph/create_framebuffer.c	\
		./graph/draw_square.c		\
		./graph/init_interface.c	\
		./graph/core_menu.c		\
		./graph/Pop_item.c		\
		./end_game.c

OBJ	=	$(SRC:.c=.o)

# CFLAGS	=	-Wall -Werror -pedantic -L./lib -lmy -I./include -lgnl

NAME	=	vm

all:	$(NAME)

$(NAME): 	$(OBJ)
		gcc $(OBJ) -lmy -lm -O3 -lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-graphics -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
