#ifndef CTEST_H
#define CTEST_H

/* Ryan Koven, 2012. All code from Ryan Koven unless otherwise noted. */


#include<stdio.h>
#include <string.h>

#define TABSTOP 5 /* The number of columns in a tab stop */



void detab(void){
	int i, c;

	while ((c = getchar()) != EOF){
		if (c == '\t'){
			for (i = 0; i<TABSTOP; i++)
				putchar(' ');
		}
		else putchar(c);

	}

}

void entab(void){
	
	int i, c, j, counter;
	i = 0;
	while ((c = getchar()) != EOF){
		if (c == ' ')
			i++;
		
		
		else if (c == '\t')
			i += TABSTOP;
			
		
		else if (i > 0){
			
			for (j = 0; j < i/TABSTOP; j++)
				putchar('\t');
			
			for (counter = 0; counter < i%TABSTOP; counter++)
				putchar(' ');
			
			 i = 0;
			 putchar(c);
		}
		
		else putchar(c);

	}
}

/* htoi: converts hexadecimal numbers entered as a c-style string into integers */
int htoi(char s[]){
	int i, n;
	n = 0;

	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')){
		for (i = 2; (s[i] >= '0' && s[i] <='9') || (s[i]>='a' && s[i]<='f') || (s[i]>='A' && s[i]<='F'); i++ ){
			if (s[i] >= '0' && s[i] <='9')
				n = 16*n + (s[i] - '0');
			else if (s[i] >= 'A' && s[i] <= 'F') 
				n = 16*n + 10 + (s[i] - 'A');
			else 
				n = 16*n + 10 + (s[i] - 'a');
}

	}

	else{
		for (i = 0; (s[i] >= '0' && s[i] <='9') || (s[i]>='a' && s[i]<='f') || (s[i]>='A' && s[i]<='F'); i++ ){
			if (s[i] >= '0' && s[i] <='9')
				n = 16*n + (s[i] - '0');
			else if (s[i] >= 'A' && s[i] <= 'F') 
				n = 16*n + 10 + (s[i] - 'A');
			else 
				n = 16*n + 10 + (s[i] - 'a');
}
	    }

	return n;
}

void squeeze(char s1[], char s2[]){
	
	int i, j, k, match;
	match = 0;

	for (i = k = 0; s1[i] != '\0'; i++){
		for (j = 0; s2[j] != '\0'; j++){
			if (s1[i] == s2[j])
				match = 1;               
			                           }
		if (match != 1)
			s1[k++] = s1[i];
		match = 0;
		               
}
	s1[k] = '\0';
}

/* lower: convert c to lower case; ASCII only. Exercise 2-10 */
int lower(int c){

	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A': c; 
}

/* binsearch1: from chapter 3 in "C Programming Language"; two tests inside while loop. */
int binsearch1(int x, int* v, int length){
	
	int low, mid, high;

	low = 0;
	high = length - 1;
	while (low <= high){
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else    /* found match */
			return mid;
						}
	return -1;   /* no match */
}

/* Binary search for an element of a sorted array. Exercise 3-1 in "C Programming Language." */
int binsearch(long x, int* v, int length){
	
	int low, mid, high;

	low = 0;
	high = length - 1;
	while (low <  high){
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid;
		else 
			low = mid + 1;
						}

	if (x == mid)    /* found match */
		return mid;
	else if (x == mid - 1)     /* found match */
		return mid - 1; 
	else if (x == mid + 1)     /* found match */
		return mid + 1;
	else 
		return -1;   /* no match */


}

/* escape: converts characters like newline and tab into visible escape sequences like \n and \t as it copies to to s (s, t strings) */
/* Exercise 3-2 in C Prog. Lang. */
void escape(char s[], char t[]){
	
	int i, j;
	
	i = j = 0;
	while (s[i] != '\0' && j < strlen(t)){ 
	switch (s[i++]){
	case '\b':
		t[j++] = '\\';
		t[j++] = 'b';
		break;
	case '\t':
		t[j++] = '\\';
		t[j++] = 't';
		break;
	case '\v':
		t[j++] = '\\';
		t[j++] = 'v';
		break;
	case '\n':
		t[j++] = '\\';
		t[j++] = 'n';
		break;
	case '\\':
		t[j++] = '\\';
		t[j++] = '\\';
		break;
	case '\?':
		t[j++] = '\\';
		t[j++] = '\?';
		break;
	case '\'':
		t[j++] = '\\';
		t[j++] = '\'';
		break;
	case '\"':
		t[j++] = '\\';
		t[j++] = '\"';
		break;
	default:
		t[j++] = s[i - 1];
		break;
	}
	
}
}

/* escape2: converts escape sequences to the real characters as it copies to to s (s, t strings) */
/* Exercise 3-2 in C Prog. Lang. */
void escape2(char s[], char t[]){

	int i, j;
	
	i = j = 0;
	while (s[i] != '\0' && j < strlen(t)){ 
	switch (s[i++]){
	case '\\':
		switch (s[i++]){
		case 't':
			t[j++] = '\t';
			break;
		case 'n':
			t[j++] = '\n';
			break;
		case 'b':
			t[j++] = '\b';
			break;
		case 'v':
			t[j++] = '\v';
			break;
		case '\\':
			t[j++] = '\\';
			break;
		case '\?':
			t[j++] = '\?';
			break;
		case '\'':
			t[j++] = '\'';
			break;
		case '\"':
			t[j++] = '\"';
			break;
		default: 
			t[j++] = '\\';
			t[j++] = s[i - 1];
			break;
		}
		break;
	default: 
		t[j++] = s[i - 1];
		break;
	}
	
}
}

/* reverse: reverse string s in place . From Section 3.5 in "C programming Language"; used in itob. */
void reverse(char s[]){

	int c, i, j;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}

/* itob: converts an integer n into into a base b character representation in the string s. Exercise 3-5 in C Prog. Lang. */
/* Supports binary up to base 10 */
void itob(int n, char s[], int b){

	if (b >=2 && b<=10){

	int i, sign;
	
	if ((sign = n) < 0)   /* record sign */
		n = -n; /* make n positive */
	i = 0;
	do{                     /* generate digits in reverse order */
		s[i++] = n % b + '0'; /* get next digit */
	} while ((n /= b) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
	}

	else 
		printf("itob currently supports binary and up to base 10");
}

/* getline: get line into s, return length. From Section 4.1 in "C programming Language"; used in strrindex. */
int getline(char s[], int lim){

	int c, i;

	i = 0;
	while(--lim> 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
/* strrindex: return index of the rightmost occurrence of t in s, or -1 if there is none. Exercise 4-1 in "C Prog. Lang." */
int strrindex(char s[], char t[]){

	int i, j, k, position;

	position = -1;

	for (i = 0; s[i] != '\0'; i++){
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			position = i;
                                    }
	return position;
} 

/* shellsort: sort v[0]...v[n - 1] into increasing order */
void shellsort(int v[], int n){
	int gap, i, j, temp;

	for (gap = n/2; gap > 0; gap /= 2){
		for (i = gap; i < n; i++){
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap){
				temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
		}
	}
}

/* atof: convert string s to double; accepts strings
   representing digits in scientific notation. */
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

#endif
