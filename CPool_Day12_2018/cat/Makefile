##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## task01 -- Day12
##

EXEC 	= cat

SRC 	= main.c

OBJ	= main.o

TEST 	= unit_tests

RM 	= rm -f

CFLAGS  = -W -Wall -Wextra -pedantic

all: cat tests_run

cat: cat.o
	gcc $(SRC) -o cat

tests_run:
	gcc -o $(TEST) ../tests/tests_run.c cat.c --coverage -lcriterion
	./$(TEST)

$(OBJ):
	gcc $(CFLAGS) -o $(OBJ) -c $(SRC)

clean:
	$(RM) *.o
	$(RM) *~
	$(RM) *.gcno
	$(RM) *.gcda
	$(RM) $(TEST)

fclean: clean
	$(RM) $(EXEC)

re: fclean all
