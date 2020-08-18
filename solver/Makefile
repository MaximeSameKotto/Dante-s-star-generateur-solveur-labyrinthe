##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=		sources/solver.c				\
			sources/error_handling.c		\
			sources/get_map.c				\
			sources/main.c					\
			sources/create_node.c			\
			sources/change_and_display.c	\
			sources/manage_open_list.c		\

OBJ	=	$(SRC:.c=.o)

NAME = solver

CFLAGS	=	-Wall -Wextra -I ./includes -g

TEST_OBJ =	$(TEST:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $(OBJ)
clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f vg.co*

fclean: clean
	rm -f $(NAME)

re: fclean all
