#include <stdio.h>

void escape(char *, char *);
void toescape(char *, char *);

int main(int argc, char *argv[]){
	char s[] = "Test String";
	char t[] = "a\tb\nc";	

	escape(s, t);
	printf("\'Escaped\' %s\n\nWhich resulted in %s\n", t, s);
	
	printf("\nAnd now back to escape characters:\n\n");
	toescape(s, t);
	printf("%s\n", s);
	return 0;
}

/* escape: copies t into s while converting escape characters in t
   into visible escape sequences, like \n and \t */
void escape(char *s, char *t){
	int i, j;
	for (i = 0, j = 0; s[i] != '\0' && t[j] != '\0'; i++, j++){
		switch (t[j]){
			case '\t': s[i++] = '\\', s[i] = 't'; break;
			case '\n': s[i++] = '\\', s[i] = 'n'; break;
			case '\r': s[i++] = '\\', s[i] = 'r'; break;
			default: s[i] = t[j]; break; // the 'break' here is unnecessary, but good defensive programming.
		}
	}
	s[i] = '\0'; // terminate string
}

/* toescape: copies t into s while converting escape sequences, like 
   \n and \t, into escape characters. */
void toescape(char *s, char *t){
	int i, j;
	for (i = 0, j = 0; s[i] != '\0' && t[j] != '\0'; i++, j++){
		switch (t[j]){
			case '\\': {	
					switch (t[j + 1]){
						case 'n': s[i] = '\n', j++; break;
						case 't': s[i] = '\t', j++; break;
						case 'r': s[i] = '\r', j++; break;
						default: s[i] = t[j]; break; 
					}
					
				   }			
			default: s[i] = t[j]; break; // the break here is unnecessary, but good defensive programming.
		}
	}
	s[i] = '\0'; // terminate string
}
