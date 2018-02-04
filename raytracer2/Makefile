##
## Makefile for bs in /home/byliarus/work/Graph/bsraytracer1/
##
## Made by John Doe
## Login   <login_x@epitech.eu>
##
## Started on  Mon Feb 13 15:30:44 2017 John Doe
## Last update Tue Jun  6 13:00:45 2017 Pierre Narcisi
##

CFLAGS	=	-lc_graph_prog -lm

SRC	=	create_window.c			\
		my_change_buffer.c		\
		my_put_pixel.c				\
		intersect/intersect_sphere.c		\
		intersect/intersect_plane.c			\
		intersect/intersect_cone.c			\
		intersect/intersect_cylinder.c	\
		pars.c								\
		pivot.c								\
		my_transformation.c		\
		light.c								\
		normal.c							\
		op.c									\
		op2.c									\
		calc_dir_vector.c

OBJS	=	$(SRC:.c=.o)

LDFLAGS	=	-L./lib/ -lmy

NAME	=	raytracer2

MAKE_LIB	=	make -C ./lib

all:		$(NAME)

$(NAME):	$(OBJS)
		$(MAKE_LIB)
		gcc $(OBJS) $(LDFLAGS) -o $(NAME) $(CFLAGS)

clean:
		$(MAKE_LIB) clean
		rm -f $(OBJS)

fclean:		clean
		$(MAKE_LIB) fclean
		rm -f $(NAME)

re:		fclean $(NAME)
		$(MAKE_LIB) re
