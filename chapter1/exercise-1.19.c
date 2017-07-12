/*
 * Author:  Jimages
 * Email:   jimages123@gmail.com
 * Description:
 *      K&R C Exercise 1-19. Write a function reverse(s) that reverses the 
 *      character string s. Use it to write a program that reverses its 
 *      input a line at a time.
 */
#ifndef __STRICT_ANSI__
    #define __STRICT_ANSI__
#endif
#include<stdio.h>
#include<stdlib.h>

#define MAXLINE 10001

int getline(char line[], size_t lim);
int reverse(char line[], size_t len);

int main(void) {
    char line[MAXLINE];
    size_t len;

    /* Now we get the string and reverse.*/
    while ((len = getline(line, MAXLINE))) {
        reverse(line, len);
        printf("%s", line);
    }
    return 0;
}

int reverse(char line[], size_t len) {
    size_t pos = len - 1;
    size_t n = 0;
    char c;

    /*If the last char is '\n' ignore it.*/
    if (line[pos] == '\n')
        pos--;

    while (pos - n > n) {
        c = line[n];
        line[n] = line[pos - n];
        line[pos - n] = c;
        n++;
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
    return len - 1; /* length excludes '\0' */
}
