#include <stdio.h>
#include <ctype.h>
#include "ch4.h"

int getfloat(float *);

int main(){
	float *pn;
	while(1){  /* Keep getting numbers from standard input forever */
		getfloat(pn);
		printf("%f\n", *pn);
	}
	return 0;
}

/*getfloat: get next floating point number from input into *pn */
int getfloat(float *pn){
	int c, sign;
	float power;
	power = 1.0;

	while (isspace(c = getch()))  /* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'){
		ungetch(c);   /* it's not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-'){
		if (!isdigit(c = getch())){
			ungetch((sign > 0) ? '+' : '-');
			return 0;
		}
	}
	for (*pn = 0.0; isdigit(c); c = getch()) /* get integer part */
		*pn = 10.0 * *pn + (c - '0');
	if (c == '.'){ /* get fraction part (if any) */
		for (power = 1.0; isdigit(c = getch()); power *= 10.0){
			*pn = 10 * *pn + (c - '0'); 	
		}	
	}
	*pn *= sign/power;
	if (c != EOF)
		ungetch(c);
	return c;
}
