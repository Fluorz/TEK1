##
## Makefile for l in /home/sid/CPE_2016_corewar/asm
## 
## Made by Sid
## Login   <sid.djilali-saiah@epitech.eu>
## 
## Started on  Mon Apr  3 00:25:06 2017 Sid
## Last update Mon Apr  3 00:25:08 2017 Sid
##

NAME	= asm

CC	= gcc

RM	= rm -f

SRCS	= ./asm.c \
	  ./asm_funcs.c \
	  ./asm_header.c \
	  ./asm_params.c \
	  ./asm_parsing.c \
	  ./asm_values.c \
	  ./create_instructions.c \
	  ./error_handling.c \
	  ./instruction_name.c \
	  ./instruction_tab.c \
	  ./label.c \
	  ./label_misc.c \
	  ./label_misc2.c \
	  ./linked_list.c \
	  ./linked_list_misc.c \
	  ./misc.c \
	  ./name_comment.c \
	  ./op.c \
	  ./open_read.c \
	  ./str_to_wordtab.c \
	  ./wordtab.c \
	  ./wordtab_funcs.c \
	  ./wordtab_misc.c 	\
	  ./gnl/gnl.c 	\
	  ./main.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I. -L./lib -lmy

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
