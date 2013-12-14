#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "c_test.h"

int main(int argc, char *argv[]){
	// print_top
	push(4.2);
	push(1);
	push(3.14159);
	print_top();

	// pop
	assert(pop() == 3.14159);

	// swap_top_two
	swap_top_two();
	assert(pop() == 4.2);

	// duplicate_top
	push(2.718281828);
	duplicate_top();
	assert(pop() == 2.718281828);

	// clear_stack
	clear_stack();
	pop(); // "error: stack empty" 

	return 0;
}