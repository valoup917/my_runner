##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## .
##

SRC		=		struct_creations.c	\
				death_body.c		\
				death_head.c		\
				obstacles.c 		\
				jump.c		\
				part1.c		\
				part2.c		\
				begining.c	\
				score.c		\
				lib/my_strcpy.c	\
				lib/my_putchar.c 	\
				lib/my_strlen.c 	\
				lib/my_putstr.c 	\

NAME    =       my_runner       \

all:
		gcc -o $(NAME) $(SRC) -lcsfml-graphics -lcsfml-system -lcsfml-audio -Wall -Wextra

clean:
		clear
		rm -f *~
		rm -f \#*\#

fclean: clean
		rm -f $(NAME)

re: fclean all


