#include <stdio.h>
#include <stdlib.h>

unsigned int getbits(const unsigned int, const int p, const int n);
unsigned int setbits(const unsigned int, const int, const int, const unsigned int);

int main(int argc, char *argv[]){
	if (argc < 5){
		printf("Usage %s <int to setbits on> <start pos> <number of bits> <int to get bits from>\n", argv[0]);
		exit(1);
	}
	printf("%d\n", setbits(atoi(argv[1]),atoi(argv[2]), atoi(argv[3]), atoi(argv[4])));
	return 0;
}

/* getbits: get n bits from position p (moving to the right) 
  (low-order bit is position 0) */
unsigned int getbits(const unsigned int x, const int p, const int n){
	return (x >> (p - n + 1)) & ~(~0 << n);
}

/* setbits: returns x with the n bits that begin at p set to the 
   rightmost n bits of y, leaving the other bits unchanged */
unsigned int setbits(const unsigned int x, const int p, const int n, const unsigned int y){
	unsigned int i, new_bits, kill_mask = ~0; 
	new_bits = getbits(y, n - 1, n); // get bits to set from y.
	
	for (i = 0; i < p - n + 1; i++)
		new_bits = new_bits << 1; // shift new bits into correct position.
														
	for (i = 0; i < n; i++)
		kill_mask = (kill_mask << 1); // add 0s for n the bits to kill in x.
	
	for (i = 0; i < p - n + 1; i++)
		kill_mask = (kill_mask << 1) | 1; // kill_mask will have 0s for the bits 
	  																	// to kill in x, 1s everywhere else.
	
	return (x & kill_mask) | new_bits; // & kills the bits to replace in x;
	                                   // | sets bits from new_bits
}