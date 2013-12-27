#include <stdio.h>
#include <stdlib.h>

void __strncpy(char *, char *, int);
void __strncat(char *, char *, int);
int __strncmp(char *, char *, int);

int main(int argc, char *argv[]){
	//__strncat(argv[1], argv[2], atoi(argv[3]));
	//printf("%s\n", argv[1]);
	return 0;
}

/* __strncpy: copy the first n characters of the string t to s */
void __strncpy(char *s, char *t, int n){
	int i;
	for (i = 0; *t && i < n; s++, t++, i++)
		*s = *t;
	*s = '\0';
}

/* __strncat: catenate the string s with the first n characters of t */
void __strncat(char *s, char *t, int n){
	int i;
	while (*s)
		s++;  /* Move to the end of s */
	for (i = 0; *t && i < n; s++, t++, i++)
		*s = *t;
	*s = '\0';
}
