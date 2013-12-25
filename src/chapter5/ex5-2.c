#include <stdio.h>
#include <ctype.h>
#include "ch4.h"

float getfloat(float *);

int main(){
	float *pn;
	while(1){  /* Keep getting numbers from standard input forever */
		getint(pn);
		printf("%d\n", *pn);
	}
	return 0;
}

/*getfloat: get next floating point number from input into *pn */
float getfloat(float *pn){
	int c, sign;

	while (isspace(c = getch()))  /* skip white space */
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
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
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}
