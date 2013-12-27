#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strend(char *, char *);

int main(int argc, char *argv[]){
	if (argc < 3){
		printf("Usage: %s <string to search in> <search to search for>\n", argv[0]);
		exit(1);
	}
	printf("String %s\n", (strend(argv[1], argv[2])) ? "Found" : "Not Found");
	return 0;
}

int strend(char *s, char *t){
	int i, t_len, s_len;
		
	s += (s_len = strlen(s));  /* Move to the end of s */
	t += (t_len = strlen(t));  /* Move to the end of t */

	i = 0;
	while (*s == *t && i < s_len && i < t_len){
		s--, t--, i++;
	}
	if (i == t_len)
		return 1;
	return 0;
}
