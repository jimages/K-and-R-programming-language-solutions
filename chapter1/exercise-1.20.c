/*
 * Author: 	Zachary Wang(jimges123@gmail.com)
 * Data:	Nov.11 2016
 * Description:
 *	The solution of Write a program detab that replaces tabs
 *	in the input with the proper number of blanks to space to the next tab stop.
 *	Assume a fixed set of tab stops, say every n columns.
 *	Should n be a variable or a symbolic parameter?
 */

#include<stdio.h>
#define TAB 8
int main(void)
{
	char c;
	int num = 0;

	while ((c = getchar()) != EOF)
	{
		if(c == '\t')
		{
			while(num++ < TAB)
				putchar(' ');
			num = 0;
		} else {
			putchar(c);
		}
	}
	return 0;
}
