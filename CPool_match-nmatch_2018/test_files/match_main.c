#include <stdio.h>

int main(int argc, char *argv[])
{
    int match_or_no = match("bonjourjesuis", "*s");
    if (match_or_no == 1)
    	printf("match\n");
    else
    	printf("don't match\n");

    return (0);
}
