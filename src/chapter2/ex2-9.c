#include <stdio.h>
#include <stdlib.h>

unsigned int bitcount(unsigned int);

int main(int argc, char *argv[]){
	if (argc < 2){
		printf("Usage: %s <int>\n", argv[0]);
		exit(1);
	}
	printf("%s has %u 1-bits\n", argv[1], bitcount(atoi(argv[1])));
	return 0;
}

/* bitcount: counts the number 1 bits in an integer x. */
unsigned int bitcount(unsigned int x){
	unsigned count;
	for (count = 0; x != 0; count++, x &= x - 1)
		;
	return count;
}
