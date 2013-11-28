#include <stdio.h>
#include <stdlib.h>

#define CHAR_RANGE 128 //ascii printable chars are between 0 and 127

char *squeeze(const char *, const char *);

int main(int argc, char *argv[]){
	if (argc < 3){
		printf("Usage: %s <word to squeeze> <squeeze word>\n", argv[0]);
		exit(1);
	}

	printf("\"%s\" squeezed with \"%s\" is \"%s\"\n", argv[1], argv[2], squeeze(argv[1], argv[2]));	

	return 0;
}

//ascii
char *squeeze(const char *s1, const char *s2){
	char *s;
	unsigned char char_array[CHAR_RANGE];
	int i, j;

	for (i = 0; s1[i] != '\0'; i++) // Determine max possible length of 
		;															// squeezed string
	s = (char *)malloc(i); // Allocate space for return string

	for (i = 0; i < CHAR_RANGE; i++)
		char_array[i] = 0;

	for (i = 0; s2[i] != '\0'; i++)
		char_array[s2[i]]++;
	
	j = 0;
	for (i = 0; s1[i] != '\0'; i++){
		if (char_array[s1[i]] == 0)
			s[j++] = s1[i];
	}
	s[j] = '\0'; //  Terminate string.

	// Naive Version:
	/*
	for (i = 0; s1[i] != '\0'; i++){
		for (j = 0; s2[j] != '\0'; j++){
			if (s1[i] == s2[j])
				match = 1;
		}
		if (match == 0)
			s[k++] = s1[i];
		match = 0;
	}
	s[k] = '\0'; //Terminate string.
	*/
	return s;
}
