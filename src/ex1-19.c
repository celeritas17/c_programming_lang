#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length*/

int __getline(char line[], int maxline);
void reverse(char s[]);
/* print the longest input line */
int main(int argc, char *argv[]){
	int len;	/* current line length */
	char line[MAXLINE];	/* current input line */

	while ((len = __getline(line, MAXLINE)) > 0){
		reverse(line);
		printf("%s", line);
	}
	return 0;
}

/* __getline: read a line into s, return length */
int __getline(char s[], int lim){
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++){
		s[i] = c;
	}
	if (c == '\n'){
		s[i++] = c;
	}
	s[i] = '\0'; // terminate string
	return i;
}

/* reverse: reverse the characters in an input string */
void reverse(char s[]){
	int i, j, k;
	char temp;
	for (i = 0; s[i] != '\n' && s[i] != '\0'; i++)
		;
	
	i--; // Want to reverse the non-newline and non-null character string,
	     // so we step back to before the newline and/or null termiator.
	for (j = 0; j < i; j++, i--){
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
	}
}
