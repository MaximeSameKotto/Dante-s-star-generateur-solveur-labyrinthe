##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## h
##

SRC		=

NAME	=	dante

.SILENT:

all:	$(NAME)

$(NAME):
	make --no-print-directory -C ./solver
	make --no-print-directory -C ./generator

solver:
	make --no-print-directory -C ./solver

generator:
	make --no-print-directory -C ./generator

clean:
	make clean --no-print-directory -C ./generator
	make clean --no-print-directory -C ./solver

fclean:
	make fclean --no-print-directory -C ./generator
	make fclean --no-print-directory -C ./solver

re:	fclean all
