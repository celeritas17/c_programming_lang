#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);

int main(int argc, char *argv[]){
	printf("0xf: %10d\n0xF: %10d\n0X41: %10d\n0xff: %10d\nFF: %10d\n0xfaa: %10d\n\"\": %10d\n", 
		htoi("0xf"), htoi("0xF"), htoi("0X41"), htoi("0xff"), htoi("FF"), 
		htoi("0xfaa"), htoi(""));
	return 0;
}

/* htoi: converts a string of ascii chars representing a hex number
   into the equivalent positive integer value, or -1 if input is the empty string or invalid. */
int htoi(char s[]){
	int result, digit, term, last_digit, i;

	result = i = 0;

	for (i; s[i] != '\0'; i++) // Step to the end of the string to determine the length.
		;
	i--; // Step back to the last non-null char.

	if ((s[i] >= '0' && s[i] <= '9') || (s[i] <= 'f' && s[i] >= 'a') || (s[i] >= 'A' && s[i] <= 'F')){
		result = digit = term = (s[i] <= '9' && s[i] >= '0') ? (s[i] - '0') 
			: ((s[i] <= 'f' && s[i] >= 'a') ? (9 + s[i] - 'a' + 1) 
				: (9 + s[i] - 'A' + 1)); 
		i--;
	}
	else
		return -1;

	while (i >= 0 && ((s[i] >= '0' && s[i] <= '9') || (s[i] <= 'f' && s[i] >= 'a') || (s[i] >= 'A' && s[i] <= 'F'))){
		last_digit = digit;
		digit = (s[i] <= '9' && s[i] >= '0') ? (s[i] - '0') 
			: ((s[i] <= 'f' && s[i] >= 'a') ? (9 + s[i] - 'a' + 1) 
				: (9 + s[i] - 'A' + 1)); 
		term = 16*digit*term/last_digit;
		result += term;
		i--;
	}
	return result;
}
