#include <stdio.h>
#include <math.h>
#include <stdlib.h>

unsigned max(unsigned, unsigned);

int main(int argc, char *argv[]){
	if (argc < 3){
		printf("Usage: %s <int> <int>\n", argv[0]);
		exit(1);
	}
	printf("Max: %d\n", max(atoi(argv[1]), atoi(argv[2])));
	return 0;
}

/* max: Return the maximum of two positive integers. */
unsigned max(unsigned x, unsigned y){
	unsigned i;
	for (i = sizeof(int)*8 - 1; i > 0 && ((int)pow(2, i) & x) == ((int)pow(2, i) & y); i--)
		;
	while (x & (int)pow(2, i))
		return x;
	return y;
}
