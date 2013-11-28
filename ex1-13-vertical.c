#include <stdio.h>

#define MAX_LENGTH 15
#define IN 1
#define OUT 0

int main(int argc, char *argv[]){
	int c, i, j, next_length, state, most_frequent, so_far;
	char lengths[MAX_LENGTH]; // Holds counts of words of length i + 1,
				  // e.g., lengths[4] holds the number of
				  // words of length 5 found so far.	

	for (i = 0; i < MAX_LENGTH; i++){
		lengths[i] = 0;
	}
	
	state = OUT;
	most_frequent = 0;
	next_length = 0;
	while ((c = getchar()) != EOF){
		if ((c == ' ' || c == '\t' || c == '\n') && state == IN ){
			state = OUT;
			lengths[next_length - 1]++;
			next_length = 0;
		}
		else if (c == ' ' || c == '\t' || c == '\n'){
			state = OUT;
		}
		else{
			state = IN;
			next_length++;
		}
	}

	for (i = 0; i < MAX_LENGTH; i++){
		if (lengths[i] > most_frequent)
			most_frequent = lengths[i];
	}
	
	so_far = 0;
	printf("\n\n*************Word Length Frequencies*************\n\n");
	for (i = 0; i < most_frequent; i++, so_far++){
		for (j = 0; j < MAX_LENGTH; j++){
			printf(" ");
			if (lengths[j] >= most_frequent - so_far){
				printf("+");
			}
			else {
				printf(" ");
			}
			printf(" ");
		}
		printf("\n");
	}	
	
	for (i = 0; i < MAX_LENGTH; i++){
		printf("%2d ", i + 1);
	}
	printf("\n\n**************************************************\n\n");
	return 0;
}
