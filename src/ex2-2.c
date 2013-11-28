#include <stdio.h>

int main(int argc, char *argv[]){
	int lim, i;
	char c;
	i = 0;
	lim = 10;
	while ((i < lim - 1) + ((c = getchar()) != '\n') + (c != EOF ) == 3 )
		putchar(c), ++i;
	return 0;
}
