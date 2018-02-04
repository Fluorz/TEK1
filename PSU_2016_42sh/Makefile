##
## Makefile for 42sh in /home/sid/PSU_2016_42sh
##
## Made by Sid
## Login   <sid.djilali-saiah@epitech.eu>
##
## Started on  Fri Jun  2 15:07:16 2017 Sid
## Last update May Jun 8 17:52:59 2017
##

NAME	= 42sh

CC	= gcc

RM	= rm -f

SRCS	= ./src/gnl/gnl.c \
	  ./src/main.c \
	  ./src/my_exec/builtins_simple.c \
	  ./src/my_exec/apply_pipe.c \
	  ./src/my_exec/apply_redirection.c \
	  ./src/my_exec/command_not_found.c \
	  ./src/my_exec/special_pipe_case.c \
	  ./src/my_exec/execve_pipe.c \
	  ./src/my_exec/execve_simple.c \
	  ./src/my_exec/fill_bin_path.c \
	  ./src/my_exec/launch_command.c \
	  ./src/my_exec/my_status.c \
	  ./src/my_exec/struct_transitor.c \
	  ./src/my_exec/transition.c \
	  ./src/my_exec/fill_arg_transitor.c \
	  ./src/my_exec/which_exec.c \
	  ./src/parser/organise/double_pipe_and.c \
	  ./src/parser/organise/handler_redirection.c \
	  ./src/parser/organise/organise.c \
	  ./src/parser/organise/parser_double.c \
	  ./src/parser/organise/parser_pipe.c \
	  ./src/parser/organise/parser_redirection.c \
	  ./src/parser/organise/pipe_redirection_exist.c \
	  ./src/parser/organise/simple_command.c \
	  ./src/parser/parser.c \
	  ./src/parser/tools/clean.c \
	  ./src/parser/tools/error_handling.c \
	  ./src/parser/tools/error_tools.c \
	  ./src/parser/tools/init_parser.c \
	  ./src/parser/tools/my_tabdup.c \
	  ./src/parser/tools/special_wordtab.c \
	  ./src/parser/tools/struct.c \
	  ./src/builtins/cd_command.c \
	  ./src/builtins/cd_extra.c \
	  ./src/builtins/env_command.c \
	  ./src/builtins/bonus_bultins.c \
	  ./src/builtins/env_tools.c \
	  ./src/builtins/my_builtins.c \
	  ./src/builtins/check_setenv_arg.c \
	  ./src/builtins/change_env.c \
	  ./src/builtins/where_which.c \
	  ./src/misc/wordtab.c \
	  ./src/misc/wordtab_funcs.c \
	  ./src/bonus/alias.c \
	  ./src/bonus/alias_other_tools.c \
	  ./src/bonus/alias_tools.c \
	  ./src/bonus/globing.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I./include/
CFLAGS += -W -Wall -Wextra -pedantic -Werror

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME)
	$(CC) $(OBJS) -o mysh

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
