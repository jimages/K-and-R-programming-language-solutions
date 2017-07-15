/*
 * Copyright(c) all rights reserve under MIT Licnese.
 * Author:	Jimages(jimages123@gmail.com)
 * Desc:
 * 	a solution to the question 1-21 in the K and C programming language.
 */
#include<stdio.h>

#define TAB_WIDTH 4

int main(void) {
	short bn_count = 0;
	char c;

	c = getchar();
	while (c != EOF) {
		while (c == ' ') {
			bn_count++;
			if (bn_count == TAB_WIDTH) {
				putchar('\\');
				bn_count = 0;
			}
			c = getchar();
		}
		if (bn_count > 0 || bn_count < TAB_WIDTH) {
			for (int n = 0;n < bn_count;n++)
				putchar(' ');
			bn_count = 0;
		}
		putchar(c);
		c = getchar();
	}
}
