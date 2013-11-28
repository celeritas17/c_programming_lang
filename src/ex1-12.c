#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char *argv[]){
	char c, state;
	
	state = OUT;
	while ((c = getchar()) != EOF){
		if ((c == ' ' || c == '\t') && state == IN){
			state = OUT;
			putchar('\n');
		}
		else if (c == ' ' || c == '\t'){
			state = OUT;
		}
		else {
			state = IN;
			putchar(c);
		}
	}

	return 0;
}
