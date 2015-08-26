/*
 * Author:  JImages
 * Email:   jimages123@gmail.com
 * Date:     Aug. 25,2015
 * Describtion:
 *     K&C C Programming Language C exercise 1-18
 */
#define __STRICT_ANSI__
#define MAXLINE 1000 

#include<stdio.h>
#include<stdlib.h>

int getline(char line[], size_t lim);
int manipulate(char line[], size_t len);

int main() {
    size_t len;
    char line[MAXLINE];
    
    /* Now we get line. */
    while (len = getline(line,MAXLINE)) {
        manipulate(line, len);
        printf("%s", line);
    }
    
    return 0;
}

int getline(char line[], size_t lim) {
    size_t len = 1;
    char c;
    
    while ((c = getchar()) != EOF && len <= lim && c != '\n') {
        line[len - 1] = c;  /* Because the first char should be char[0] */
        len++;
    }
    
    if (c == '\n')
        line[len++ - 1] = c;
    
    if (len == 1 + lim) {  
        /* when the last char is '\n' and the string is full,
         * it needs special manipulation.*/
        printf("The string you input is too full.\n");
        exit(EXIT_FAILURE);
    }
    line[len - 1] = '\0';
    return len;
}

int manipulate(char line[], size_t len) {
    char c;
    int newline = 0;

    if (--len - 1 < 0)
        return 0;   /* When the string only have a '\0'. */
    
    if (line[len - 1] == '\n') {
        newline = 1;
        len--;
    }

    while (len - 1 >= 0 && (line[len - 1] == ' ' || line[len - 1] == '\t'))
        len--;

    if (len -1 < 0) /* when the line is blank line.*/
        len = 0;

    if (newline && len != 0) { 
        line[len] = '\n';
        len++;
        }
    line[len] = '\0';
    return 0;
}
