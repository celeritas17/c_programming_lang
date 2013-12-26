#include <stdio.h>
#include <stdlib.h>

int strend(char *, char *);

int main(int argc, char *argv[]){
	if (argc < 3){
		printf("Usage: %s <string to search in> <search to search for>\n", argv[0]);
		exit(1);
	}
	return 0;
}
