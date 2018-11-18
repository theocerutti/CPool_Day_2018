##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## task02 -- Day10
##

EXEC = match

SRC = match.c

OBJ = match.o

RM = rm -f

CFLAGS = -W -Wall -Wextra -pedantic

all: rush2

rush2: match.c test_files/match_main.c
	gcc $(SRC) -o $(EXEC) -L. lib/my/libmy.a

clean:
	$(RM) *.o
	$(RM) *~
	$(RM) *#

fclean: clean
	$(RM) $(EXEC)

re: fclean all
