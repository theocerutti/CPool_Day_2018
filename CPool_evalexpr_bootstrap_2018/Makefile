##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## lib -- makefile
##

SRC		= 	bootstrap_evalexpr.c

OBJ		=	$(SRC:.c=.o)

NAME 		=	bootstrap_evalexpr

RM 		=	@rm -rf

CFLAGS		= -pedantic -Wall -Wextra -W

all:		$(NAME)

$(NAME):	$(OBJ)
	make re -C lib/my && gcc $(SRC) -o $(NAME) -L lib/my -lmy

clean:
	$(RM) *.o
	$(RM) *#
	$(RM) *.~

fclean: clean
	$(RM) $(NAME)

re: fclean all
