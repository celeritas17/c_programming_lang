#include <stdio.h>

void __strcat(char *, char *);

int main(){
	return 0;
}

/* copies the string t to the end of s */
void __strcat(char *s, char *t){
	while (*s)
		s++;  /* move the pointer to the null terminator */
	while ((*s++ = *t++)) 
		;	
}
