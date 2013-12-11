#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double __atof(char s[]);

int main(int argc, char *argv[]){
	if (argc < 2){
		printf("Usage: %s <string to convert to double>\n", argv[0]);
		exit(1);
	}
	printf("%f\n", __atof(argv[1]));
	return 0;
}

/* atof: convert string s to double */
double __atof(char s[]){
	double val, power, e_power;
	int i, j, exponent, sign, e_sign;

	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0*val + (s[i] - '0');
	if (s[i] =='.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++){
		val = 10.0*val + (s[i] - '0');
		power *= 10.0;
	}
	
	
	if (s[i] == 'e' || s[i] == 'E')
		i++;
	e_sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (exponent = 0; isdigit(s[i]); i++)
		exponent = exponent*10 + (s[i] - '0');
	for (j = 0, e_power = 1.0; j < exponent; j++)
		e_power *= (e_sign == 1) ? 10 : .1;

	return sign*val*e_power/power;
}
