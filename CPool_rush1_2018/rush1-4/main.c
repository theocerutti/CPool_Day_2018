#include <unistd.h>
#include "rush.c"
#include <stdio.h>
#include <stdlib.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char const *argv[])
{
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);

	rush(x, y);
	return (0);
}
