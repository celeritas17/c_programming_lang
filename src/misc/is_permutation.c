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

/* is_permutation: returns 1 if s is a permutation of t, 0 otherwise; s, t ascii strings. */
int is_permutation(char *s, char *t){
	int i;
	char *c, s_chars[256]; // ascii assumption.
	
	for (i = 0; i < 256; i++)
		s_chars[i] = 0;
	
	for (c = s; *c; c++)
		s_chars[*c]++;
	for (c = t; *c; c++){
		if (--s_chars[*c] < 0)
			return 0;
	}
	return 1;	
}
