##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## h
##

SRC	=	main.c	\
		error_handling.c	\
		print_map.c	\
		maze_generator.c	\
		create_loop.c	\
		check_pos.c	\
		random_merge_algo.c	\
		convert_map.c	\
		find_biggest_nbr.c	\
		big_map_generator.c	\

DIR_SRC	=	$(addprefix source/, $(SRC))

OBJ	=	$(DIR_SRC:.c=.o)

NAME	=	generator

CFLAGS	=	-g3 -I ./include -Wall -Wextra

RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

.SILENT:

all:	$(NAME)

$(NAME):	compiling $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)
	printf "\n$(GREEN)[✓]$(NC)\x1B[32mExecutable ready !\x1B[37m\n"

compiling:
	printf "$(GREEN)[+]Compiling $(NAME)\n"

%.o: %.c
	printf "$(GREEN)▒\e[0m"
	gcc -o $@ -c $(CFLAGS) $^

clean:
	printf "$(RED)[-]Object files have been cleared"
	rm -rf obj_folder
	rm -f *~ vg*
	rm -f $(OBJ)
	rm -f ./lib/my/*.o

fclean:	clean
	rm -f $(NAME)
	printf "\n$(RED)[-]Executive file has been cleared\n"
	rm -f ./lib/libmy.a

re:	fclean all
