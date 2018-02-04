##
## Makefile for need4stek in /home/monty/Documents/Rendu/need4stek/CPE_2016_n4s/
##
## Made by Monty Criel
## Login   <monty.criel@epitech.eu@epitech.eu>
##
## Started on  Thu Jun  1 14:06:55 2017 Monty Criel
## Last update Sun Jun  4 20:38:43 2017 Monty Criel
##

CC	=	gcc

SRC	=	main.c				\
		gnl.c				\
		write_tools.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -W -Werror -Wall -lm

LDFLAGS =	-lm -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

NAME	=	ai

all:	$(NAME)

$(NAME): 	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
