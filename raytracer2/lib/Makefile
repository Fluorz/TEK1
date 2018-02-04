##
## Makefile for lib in /home/byliarus/work/CPE/CPE_2016_matchstick/lib/
##
## Made by John Doe
## Login   <login_x@epitech.eu>
##
## Started on  Mon Feb 20 15:37:13 2017 John Doe
## Last update Fri Mar 10 19:30:34 2017 John Doe
##

AR	=	ar rc

RM	=	rm -f

SRCS	=	./src/get_next_line.c					\
				./src/disp.c                  \
        ./src/my_put_nbr.c            \
        ./src/my_put_nbrbase.c        \
        ./src/my_putchar.c            \
        ./src/my_putstr.c             \
        ./src/disp2.c                 \
				./src/my_atoi.c								\
        ./src/my_printf.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-I./include/ -g3

all:		$(NAME)

$(NAME):	$(OBJS)
		$(AR) $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
