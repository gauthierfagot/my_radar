##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC     =	src/main.c	\
			src/create_buffer.c	\
			src/create_array.c	\
			src/create_array_entity.c	\
			src/free_variable.c	\
			src/init_variable.c	\
			src/error_handling.c	\
			src/set_entities.c	\
			src/events.c	\
			src/move_entities.c	\
			src/draw_entities.c	\
			src/entities_collision.c	\
			src/planes_collision.c	\
			src/towers_collision.c	\
			src/set_window.c


OBJ     =	$(SRC:.c=.o)

NAME    =	my_radar

CFLAGS	= 	-Wall -Wextra -g3

CPPFLAGS	=	-I./include

LDFLAGS	=	-lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio -lmy\
-lm

LDLIBS	=	-L./lib

all:    $(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my libmy
	make -C ./lib/my clean
	$(CC) -o $(NAME) $(OBJ) $(LDLIBS) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re
