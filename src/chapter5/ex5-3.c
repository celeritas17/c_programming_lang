#include <stdio.h>
#include <stdlib.h>

void __strcat(char *, char *);

int main(int argc, char *argv[]){
	if (argc < 3){
		printf("Usage: %s <orig string> <string to cat>\n", argv[0]);
		exit(1);
	}
	__strcat(argv[1], argv[2]);
	printf("%s\n", argv[1]);
	return 0;
}

/* __strcat: copies the string t to the end of string s */
void __strcat(char *s, char *t){
	while (*s)
		s++;  /* move the pointer to the null terminator */
	while ((*s++ = *t++)) /* catenate */
		;	
}
