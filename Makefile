##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## compile makefile
##

SRC	= 	src/main.c 					\
		src/render_window.c

OBJ	=	$(SRC:.c=.o)

NAME =	my_hunter

CSFML = -lcsfml-graphics -lcsfml-audio

WARNING = -Wall -Wextra

LIB = -L./lib/ -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my/
	make clean -C lib/my/
	gcc -o $(NAME) $(OBJ) $(LIB) $(WARNING) $(CSFML)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my/

re:	fclean all
