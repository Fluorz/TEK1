##
## Makefile for 103 in /home/lecherbonnier/103 architect/
##
## Made by Leo Lecherbonnier
## Login   <leo.lecherbonnier@epitech.eu@epitech.eu>
##
## Started on  Tue Dec 20 14:24:28 2016 Leo Lecherbonnier
## Last update Tue Dec 20 14:24:34 2016 Leo Lecherbonnier
##

CC	= gcc

RM	= rm -f

CFLAGS	= -g -lm -W -Wall -Wextra -lm

NAME	= 103architecte

SRC=	main.c \
	calc.c \
	matrice.c \
	option.c \
	str.c \
	my_str_isnum.c

OBJ	= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
