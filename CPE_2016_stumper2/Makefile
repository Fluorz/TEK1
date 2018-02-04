##
## Makefile for Makefile in /home/ferlet_n/colle/CPE_2016_stumper2
## 
## Made by Nicolas Ferlet
## Login   <ferlet_n@epitech.net>
## 
## Started on  Tue Apr 25 07:03:33 2017 Nicolas Ferlet
## Last update Tue Apr 25 10:56:15 2017 Nicolas Ferlet
##

SOURCE = ./src/

TOOLS = ./src/tools/

CC = gcc

RM = rm -f

CFLAGS = -W -Wall -Werror -Wextra -I./src/include

SRC = $(SOURCE)main.c \
	$(SOURCE)lib.c \
	$(SOURCE)create_bord.c \
	$(SOURCE)get_next_line.c \
	$(SOURCE)game.c \
	$(SOURCE)param.c \
	$(SOURCE)get_param.c \
	$(SOURCE)full_map.c \
	$(SOURCE)check_win.c \
	$(TOOLS)strlen.c \
	$(TOOLS)getnbr.c \
	$(TOOLS)strcmp.c \
	$(TOOLS)soft_display.c

OBJS = $(SRC:.c=.o)

NAME = connect4


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
