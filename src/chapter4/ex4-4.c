#include <stdio.h>
#include <stdlib.h>  /* for atof */

#define MAXOP 100    /* max size of operand or operator */
#define NUMBER '0'   /* signal that a number was found */

int getop(char []);
void push(double);
double pop(void);

/* reverse Polish calculator */
int main(){
	
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF){
		switch (type){
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push((int)pop() % (int)op2);
			else printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}	
	}
	return 0;
}

#define MAXVAL 100   /* maximum depth of val stack */

int sp = 0;          /* maximum free stack position */
double val[MAXVAL];  /* value stack */

/* push: push f onto value stack */
void push(double f){
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void){
	if (sp > 0)
		return val[--sp];
	else{
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* print_top: print the element on the top of the stack */ 
void print_top(void){
	if (sp > 0)
		printf("%.8g\n", val[sp - 1]);
}

/* duplicate_top: copies the element on the top of the stack
   and places it on top of the stack. */
void duplicate_top(void){
	if (sp > 0){
		val[sp] = val[sp - 1];
		sp++;
	}
}

/* swap_top_two: swap the top two elements on the stack. */
void swap_top_two(void){
	if (sp > 1){
		int temp;
		temp = val[sp - 1]; // top of the stack
		val[sp - 1] = val[sp - 2];
		val[sp - 2] = temp;
	}
}

/* clear_stack: set sp to 0 (to clear the stack). */
void clear_stack(void){
	sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]){
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;  /* not a number */
	i = 0;
	if (isdigit(c))    /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')      /* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch(void){ /* get a (possible pushed back) character */
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){ /*push character back on input */
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
