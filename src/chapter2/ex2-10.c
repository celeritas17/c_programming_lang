#include <stdio.h>
#include <stdlib.h>

char lower(char);

int main(int argc, char *argv[]){
	if (argc < 2){
		printf("Usage: %s <char to lower>\n", argv[0]);
		exit(1);
	}

	printf("%c\n", lower(argv[1][0]));
	return 0;
}

/* lower: convert ascii char to lower case.
   If input is not a capital letter, return the input char.
*/
char lower(char c){
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
