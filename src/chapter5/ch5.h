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

/*getint: get next integer from input into *pn */
int getint(int *pn){
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
