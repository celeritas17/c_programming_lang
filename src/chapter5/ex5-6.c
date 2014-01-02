#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int __atoi(char *);
char *__itoa(int);
void reverse(char *);

int main(int argc, char *argv[]){
	//reverse(argv[1]);
	//printf("%s\n", argv[1]);
	return 0;
}

/* __atoi: convert string to integer; return the integer represented 
   by string s, or 0 if s does not represent an int. */
int __atoi(char *s){
	int sign, number;
	
	while (isspace(*s))
		s++;   /* skip whitespace */
	if (!isdigit(*s) && *s != '+' && *s != '-')
		return 0;  /* Not an integer. */
	sign = (*s == '-') ? -1 : 1;
	if (!isdigit(*s)) 
		s++;
	for (number = 0; isdigit(*s); s++) 
		number = 10*number + (*s - '0');

	return sign*number;
}



/* __itoa: Returns the string representation of integer n. */
char *__itoa(int n){
	char *number;
	number = (char *)malloc(10);
	
	return number;
}

void reverse(char *s){
	int i, j, temp;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--){
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}


