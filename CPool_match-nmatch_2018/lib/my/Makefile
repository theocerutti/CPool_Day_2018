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

all: match

lib_compil:
	gcc -c *.c
	ar rc libmy.a *.o
	rm *.o

match: lib_compil
	gcc -o match ../../match.c ../../test_files/match_main.c -L./lib/my

clean:
	$(RM) *.o
	$(RM) *~
	$(RM) .vscode
	$(RM) *.gcno
	$(RM) test
	$(RM) a.out

fclean: clean
	$(RM) $(EXEC)

re: fclean all
