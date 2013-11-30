#include <stdio.h>

#define MAXLINE 1000
#define ONE_LINE "//"
#define MULTI_OPEN "/*"
#define MULTI_CLOSE "*/"
#define COMMENT_CHARS_LEN 2

int __getline(char s[], int lim);
int find_string(char s[], char seq[], int seq_len, int start_pos);

int main(int argc, char *argv[]){
    int len, match_count, match_one, in_comment;
    char c;
    match_count = 0;
    match_one = 0;
    while ((c = getchar()) != EOF){
        if (c == MULTI_OPEN[match_count]){
            match_count++;
            match_one++; 
            if (match_count == COMMENT_CHARS_LEN){
                in_comment = 1;
                match_count = 0;
                while ((c = getchar()) != EOF && in_comment){
                    if (c == MULTI_CLOSE[match_count]){
                        match_count++;
                        if (match_count == COMMENT_CHARS_LEN){
                            in_comment = 0;
                        }
                    }
                }
            }
        }
        else if (c == '\"'){
            putchar(c);
            while ((c = getchar()) != EOF && c != '\"'){
                putchar(c);
            }
            putchar(c);
        }
        else if (c == ONE_LINE[match_one]){
            match_one++;
            if (match_one == COMMENT_CHARS_LEN){
                while ((c = getchar()) != EOF && c != '\n')
                    ;
                if (c == '\n'){
                    putchar(c);
                }
            }
        }
        else{
            putchar(c);
            match_count = 0;
            match_one = 0;
        }
    }

    return 0;
}

/* getline: read chars from input until you find a newline
   or EOF */
int __getline(char s[], int lim){
    int i;
    char c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c !='\n'; i++){
        s[i] = c;
    }
    if (c == '\n'){
        s[i++] = c;
    }
    s[i] = '\0'; // Terminate string
    return i;
}

/* find_string: return index of start of seq in s if seq is
   a substring of s, -1 otherwise */
int find_string(char s[], char seq[], int seq_len, int start_pos){
    int i, match_count;
    match_count = 0;
    for (i = start_pos; s[i] != '\0'; i++){
        if (s[i] == seq[match_count]){
            match_count++;
            if (match_count == seq_len){
                return i - seq_len + 1;
            }
        }
        else{
            match_count = 0;
        }
    }
    return -1;
}
