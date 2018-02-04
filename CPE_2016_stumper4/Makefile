##
## Makefile for makefile in /home/ferlet_n/colle/CPE_2016_stumper4
##
## Made by Nicolas Ferlet
## Login   <ferlet_n@epitech.net>
##
## Started on  Tue May  9 07:04:58 2017 Nicolas Ferlet
## Last update Tue May  9 11:39:03 2017 Leo Lecherbonnier
## Last update Tue May  9 08:53:49 2017 Nicolas Ferlet
##

UTILS = ./src/utils/

PARAM = ./src/param/

CC = gcc

RM = rm -f

CFLAGS = -W -Wall -Wextra -Werror -I./include

SRC = src/main.c \
	$(PARAM)param.c \
	$(PARAM)get_file.c \
	$(UTILS)lib.c \
	$(UTILS)lib2.c \
	$(UTILS)my_get_nbr.c \
	$(UTILS)my_get_next_line.c \
	$(UTILS)tab.c

OBJS = $(SRC:.c=.o)

NAME = gameoflife


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
