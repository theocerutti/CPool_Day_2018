##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile -- Bistromatic
##

SRC = 	main.c								\
		src/evalexpr/eval_expr.c			\
		src/evalexpr/error.c				\
		src/evalexpr/error2.c  				\
		src/evalexpr/new_tab.c				\
		src/evalexpr/operator.c				\
		src/evalexpr/sign.c					\
		src/evalexpr/tab_creator.c			\
		src/infindivide/divide.c			\
		src/infindivide/set_str.c			\
		src/infindivide/division.c			\
		src/infindivide/divide_normfile.c               \
		src/infinmodulo/modulo.c			\
		src/infinmodulo/set_str_mod.c		\
		src/infinmodulo/modulation.c		\
		src/infinmult/function_infin_add.c	\
		src/infinmult/function_infin_multi.c\
		src/infinmult/infin_add.c		    \
		src/infinmult/infin_multi.c	        \
		src/infinmult/my_strdelete.c        \
		src/infinmult/my_strappend_first.c  \
		src/infinmult/my_strappend.c		\
		src/infinadd/add_less.c   			\
		src/infinadd/add_less2.c 			\

OBJ		=	$(SRC:.c=.o)

NAME 	=	calc

RM 		=	rm -rf

RM_TRASH=	*.o *~ *.gcno *.gcda libmy.a

CFLAGS	= 	-pedantic -Wall -Wextra -W

all:	$(NAME)

$(NAME):	$(OBJ)
	make re -C src/lib/my && gcc $(SRC) -o $(NAME) -L src/lib/my -lmy

clean:
	$(RM) $(RM_TRASH)
	cd src/evalexpr/ && $(RM) $(RM_TRASH)
	cd src/infinadd/ && $(RM) $(RM_TRASH)
	cd src/infindivide/ && $(RM) $(RM_TRASH)
	cd src/infinmodulo/ && $(RM) $(RM_TRASH)
	cd src/infinmult/ && $(RM) $(RM_TRASH)
	cd src/lib/my/ && $(RM) $(RM_TRASH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

