/* K&R C Book exercise 1.16 */
#include<stdio.h>
#define MAXLINE 10

int Mgetline(char line[], int maxline);
void copy(char to[], char form[]);

/* print longest input line. */
int main(void) {
    int len;        /* current line length */
    int max;        /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE];   /* longest lin saved here */
    char c;

    max = 0;
    while ((len = Mgetline(line,MAXLINE)) > 0) {
        if (line[len-1] != '\n') {
            while ((c = getchar()) != EOF && c != '\n')
                len++;
        }
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) /* there was a line */
        printf("the count of characters is %d, and content is %s", max, longest);
    return 0;
}

/* getline: read a line into s, return length */
int Mgetline(char s [], int lim){
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

/* copy: */
void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
