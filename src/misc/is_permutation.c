#include <stdio.h>
#include <stdlib.h>

int is_permutation(char *, char *);

int main(int argc, char *argv[]){
	if (argc < 3){
		printf("Usage: %s <string> <string>\n", argv[0]);
		exit(1);
	}
	printf("\'%s\' is%s a permutation of \'%s\'\n", argv[1], (is_permutation(argv[1], argv[2])) ? "" : " not", argv[2]);
	return 0;
}


int is_permutation(char *s, char *t){
	return 1;	
}
