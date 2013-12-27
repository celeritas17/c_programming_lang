#include <stdio.h>
#include <stdlib.h>

void __strncpy(char *, char *, int);
void __strncat(char *, char *, int);
int __strncmp(char *, char *, int);

int main(int argc, char *argv[]){
	return 0;
}

/* __strncpy: copy the first n characters of the string t to s */
void __strncpy(char *s, char *t, int n){
	int i;
	for (i = 0; *t && i < n; s++, t++, i++)
		*s = *t;
	*s = '\0';
}
