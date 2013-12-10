#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strrindex(char s[], char t[]);

int main(int argc, char *argv[]){
	if (argc < 3){
		printf("Usage: %s <string to search> <pattern>\n", argv[0]);
		exit(1);
	}		
	
	printf("Rightmost occurrence of %s in %s: %d\n", argv[2], argv[1], strrindex(argv[1], argv[2]));
	return 0;
}

int strrindex(char s[], char t[]){
	int i, j, k;
	
	for (i = strlen(s) - 1; i >= 0; i--){
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;	
	}
	return -1;
}
