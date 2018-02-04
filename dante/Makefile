## Makefile for Makefile in /home/hugo/cours/Code/Semestre 2/Initiation IA/dante/
##
## Made by Hugo Bleuzen
## Login   <hugo.bleuzen@epitech.eu>
##
## Started on  Thu Apr 20 15:16:48 2017 Hugo Bleuzen
## Last update Wed May 10 16:21:29 2017 Leo Lecherbonnier
##


all	:
		make -C astar/
		make -C breadth/
		make -C generator/
		make -C tournament/
		make -C depth/

clean	:
		make clean -C breadth/
		make clean -C astar/
		make clean -C generator/
		make clean -C tournament/
		make clean -C depth/

fclean	:	clean
		make fclean -C breadth/
		make fclean -C astar/
		make fclean -C generator/
		make fclean -C tournament/
		make fclean -C depth/

re	:	fclean all

.PHONY	: all clean fclean re
