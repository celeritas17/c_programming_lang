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

/* __strncat: catenate the string s with the first n characters of t */
void __strncat(char *s, char *t, int n){
	int i;
	while (*s)
		s++;  /* Move to the end of s */
	for (i = 0; *t && i < n; s++, t++, i++)
		*s = *t;
	*s = '\0';
}

/* __strncmp: compares the first n characters of s with the first n
  characters of t; returns 1 if they all match or all of t is found 
  in s, 0 otherwise (the standard library function strncmp returns 
  different values). */
int __strncmp(char *s, char *t, int n){
	int i;
	
	for (i = 0; *t && *s && *s == *t && i < n; i++, s++, t++)
		;
	return ((i && i == n) || !*t); /* all n chars match
					  (n > 0) or all of 
					  t matches 
  				       */
}
