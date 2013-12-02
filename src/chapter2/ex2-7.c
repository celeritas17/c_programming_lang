#include <stdio.h>
#include <stdlib.h>

unsigned int invert(const unsigned int, const int, const int);

int main(int argc, char *argv[]){
	if (argc < 4){
		printf("Usage: %s <int to invert bits on> <start pos> <number of bits>\n", argv[0]);
		exit(1);
	}
	printf("%d\n", invert(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])));
	return 0;
}

/* invert: returns x with the n bits that begin at position p
   inverted (i.e., 1 changed to 0 and vice verse), with others
   unchanged.  */
unsigned int invert(const unsigned int x, const int p, const int n){
	unsigned kill_mask; 
	kill_mask = 0 | (2*(n - 1) + 1);
						
	return (x ^ (kill_mask << (p - n + 1)));	                     
}
