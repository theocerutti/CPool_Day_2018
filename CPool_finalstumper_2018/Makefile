##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

SRC		= 	main.c \
			function.c

OBJ		=	$(SRC:.c=.o)

NAME 		=	rush3

RM 		=	@rm -rf

CFLAGS		= 	-pedantic -Wall -Wextra -W

all:		$(NAME)

$(NAME):	$(OBJ)
	make re -C lib/my/
	gcc $(SRC) -o $(NAME) -L lib/my/ -lmy

clean:
	$(RM) *.o
	$(RM) *#
	$(RM) *.~

fclean: clean
	$(RM) $(NAME)

re: fclean all
