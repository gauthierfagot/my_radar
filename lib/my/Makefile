##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC     =	my_compute_power_rec.c	\
			my_putchar.c	\
			my_putstr.c	\
			my_strlen.c	\
			str_to_int.c	\
			int_to_str.c

OBJ     =	$(SRC:.c=.o)

NAME    =	libmy

CPPFLAGS	=	-I./include

all:    $(NAME)

$(NAME):	$(OBJ)
	ar rc -o $(NAME).a $(OBJ)
	mv $(NAME).a ..

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME).a

re: clean fclean all
