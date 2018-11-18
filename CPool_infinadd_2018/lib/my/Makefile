##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## lib -- makefile
##

SRC		= 	my_putchar.c                \
			my_isneg.c                  \
			my_put_nbr.c                \
			my_swap.c                   \
			my_putstr.c                 \
			my_strlen.c                 \
			my_getnbr.c                 \
			my_sort_int_array.c         \
			my_compute_power_rec.c      \
			my_compute_square_root.c    \
			my_is_prime.c               \
			my_find_prime_sup.c         \
			my_strcpy.c                 \
			my_strncpy.c                \
			my_revstr.c                 \
			my_strstr.c                 \
			my_strcmp.c                 \
			my_strncmp.c                \
			my_strupcase.c              \
			my_strlowcase.c             \
			my_strcapitalize.c          \
			my_str_isalpha.c            \
			my_str_isnum.c              \
			my_str_islower.c            \
			my_str_isupper.c            \
			my_str_isprintable.c        \
			my_showstr.c                \
			my_putnbr_base.c            \
			my_showmem.c                \
			my_strcat.c                 \
			my_strncat.c                \

OBJ		=	$(SRC:.c=.o)

NAME 	=	libmy.a

RM 		=	@rm -rf

CFLAGS	= -pedantic -Wall -Wextra -W

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
