#include <stdio.h>

void escape(char *, char *);

int main(int argc, char *argv[]){
	char s[] = "Test String";
	char t[] = "a\tb\nc\r";	

	escape(s, t);
	printf("\'Escaped\' %s\n\nWhich resulted in %s\n", t, s);
	
	return 0;
}

/*
  */
void escape(char *s, char *t){
	int i, j;
	for (i = 0, j = 0; s[i] != '\0' && t[j] != '\0'; i++, j++){
		switch (t[j]){
			case '\t': s[i++] = '\\', s[i] = 't'; break;
			case '\n': s[i++] = '\\', s[i] = 'n'; break;
			case '\r': s[i++] = '\\', s[i] = 'r'; break;
			default: s[i] = t[j]; break;
		}
	}
	s[i] = '\0';
}
