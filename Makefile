##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for the bssokoban project
##

CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror

SRC			=	my_sokoban.c				\
				lib_functions/my_putchar.c	\
				lib_functions/my_putstr.c	\
				lib_functions/my_put_nbr.c	\
				lib_functions/my_strlen.c	\
				lib_functions/mini_printf.c	\
				lib_functions/my_strcmp.c	\
				load_map.c					\
				get_size_of_map.c			\
				load_map_in_mem.c			\
				check_map.c					\
				print_map.c					\
				move_player.c				\
				is_finished.c				\
				read_utils.c				\
				manage_imputs.c				\
				end_game.c

OBJ			=	$(SRC:.c=.o)

NAME		=	my_sokoban

all:		$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -I./include/ $(CFLAGS) -lncurses

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:			fclean	all
