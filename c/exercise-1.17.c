/* K&R C Book exercise 1.16 */
#define __STRICT_ANSI__
#include<stdio.h>
#define MAXLINE 1000

int Mgetline(char line[], int maxline);

/* print longest input line. */
int main(void) {
    int len;        /* current line length */
    char line[MAXLINE]; /* current input line */
    char c;

    while ((len = Mgetline(line,MAXLINE)) > 0) {
        if (line[len-1] != '\n') {
            while ((c = getchar()) != EOF && c != '\n')
                len++;
        }
        if (len > 80) {
            printf("%s",line);
        }
    }
    return 0;
}

/* getline: read a line into s, return length */
int Mgetline(char s[], int lim){
    int c, i;
    
    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
