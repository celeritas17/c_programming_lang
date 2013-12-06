#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void expand(char *, char *);

int main(int argc, char *argv[]){
	if (argc < 2){
		printf("Usage: %s <string to expand>\n", argv[0]);
		exit(1);
	}
	char s2[500];
	memset(s2, 500, 'a');
	expand(argv[1], s2);
	printf("%s\n", s2);
	return 0;
}

/* expand: expands shorthand notation (like 'a-z0-9', essentially 
   the notation	in character classes is regular expressions) while 
   copying string s1 into string s2 */
void expand(char s1[], char s2[]){
	unsigned char c;
	int i, j, s1len;
	s1len = strlen(s1);
	for (i = 0, j = 0; s1[i] != '\0' && s2[j] != '\0'; i++){
		if (s1[i] == '-' && i > 0 && i < s1len - 1){
			for (c = s1[i - 1] + 1; c  < s1[i + 1];  c++){
				s2[j++] = c;
			} 
		}
		else 
			s2[j++] = s1[i];
	}
	s2[j] = '\0';
}
