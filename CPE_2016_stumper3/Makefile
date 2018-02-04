##
## Makefile for makefile in /home/ferlet_n/colle/CPE_2016_stumper3
## 
## Made by Nicolas Ferlet
## Login   <ferlet_n@epitech.net>
## 
## Started on  Tue May  2 07:16:21 2017 Nicolas Ferlet
## Last update Tue May  2 11:03:02 2017 Nicolas Ferlet
##

USE = ./utils/

CC = gcc

RM = rm -f

CFLAGS = -W -Wall -Wextra -Werror -I./include

SRC = $(USE)my_get_nbr.c \
	$(USE)my_get_next_line.c \
	$(USE)lib.c \
	$(USE)my_put_nbr.c \
	$(USE)my_strcpy.c \
	main.c \
	param.c \
	list.c \
	database.c \
	tab.c \
	find.c \
	my_strcmp2.c

OBJS = $(SRC:.c=.o)

NAME = mixword


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
