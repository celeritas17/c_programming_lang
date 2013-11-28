#include <stdio.h>
#include <stdlib.h>

#define CHAR_RANGE 128 //ascii printable chars are between 0 and 127

int any(const char *, const char *);

int main(int argc, char *argv[]){
	int spot;
	
	if (argc < 3){
		printf("Usage: %s <s1> <s2>\n", argv[0]);
		exit(1);
	}

	((spot = any(argv[1], argv[2])) != -1) ? printf("The first char from \"%s\" that occurs in \"%s\" is \'%c\' at position %d\n", 
		argv[1], argv[2], argv[1][spot], spot) 
		: printf("No char from \"%s\" occurs in \"%s\"\n",
			argv[2], argv[1]);
	return 0;
}

/* any: returns the first location in the string s1 where
	any character from the string s2 occurs or -1 if 
	s1 contains no characters from s2.  
*/
int any(const char *s1, const char *s2){
	int i, spot;
	unsigned char char_array[CHAR_RANGE]; // array to count occurrences 
					      // of ascii chars.

	for (i = 0; i < CHAR_RANGE; i++) // Place zeroes in
		char_array[i] = 0;	 // char_array
					 
	for (i = 0; s2[i] != '\0'; i++)  // flag occurrences of s2[i]
		char_array[s2[i]]++;     
	
	for (i = 0; s1[i] != '\0'; i++){
		if (char_array[s1[i]])   // if s1[i] was found in s2
			return i;        // return the location in s1
	}

	return -1; // nothing found
}
