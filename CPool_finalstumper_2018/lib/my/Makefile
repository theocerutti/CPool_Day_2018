##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## lib -- makefile
##

SRC		= 	my_putchar.c \
			my_putstr.c  \
			my_strlen.c  \
			my_strdelete.c\
			my_put_nbr.c

OBJ		=	$(SRC:.c=.o)

NAME 		=	libmy.a

RM 		=	@rm -rf

CFLAGS		= -pedantic -Wall -Wextra -W

all:		$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	$(RM) *.o
	$(RM) *#
	$(RM) *.~

fclean: clean
	$(RM) $(NAME)

re: fclean all
