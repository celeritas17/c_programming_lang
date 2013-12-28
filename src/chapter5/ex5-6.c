#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int __atoi(char *);

int main(int argc, char *argv[]){
	printf("%d\n", __atoi(argv[1]));
	return 0;
}

/* __atoi: convert string to integer; return the integer represented 
   by string s, or 0 if s does not represent an int. */
int __atoi(char *s){
	int sign, number, power;
	
	while (isspace(*s))
		s++;   /* skip whitespace */
	if (!isdigit(*s) && *s != '+' && *s != '-')
		return 0;  /* Not an integer. */
	sign = (*s == '-') ? -1 : 1;
	if (!isdigit(*s)) 
		s++;
	for (number = 0, power = 1; isdigit(*s); power *= 10, s++) 
		number = power*number + (*s - '0');

	return sign*number;
}
