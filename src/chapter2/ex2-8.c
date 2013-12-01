#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int getbits(const unsigned int, const int, const int);
unsigned int rightrot(const unsigned int, const int);

int main(int argc, char *argv[]){
	if (argc < 3){
		printf("Usage %s <int to rotate> <number of bits to rotate>\n", argv[0]);
		exit(1);
	}
	printf("%u\n", rightrot(atoi(argv[1]), atoi(argv[2])));
	return 0;
}

/* getbits: get n bits from position p (moving to the right)
   (low-order bit is position 0) */
unsigned int getbits(const unsigned int x, const int p, const int n){
	return (x >> (p - n + 1)) & ~(~0 << n);
}

/* rightrot: returns the value of integer x with bits "rotated"
   to the right by n places. */
unsigned int rightrot(const unsigned int x, const int n){
	unsigned int new_horder_bits;
	new_horder_bits = (getbits(x, n - 1, n) << (sizeof(int)*8 - n));	
	return (x >> n) | new_horder_bits;		
}
