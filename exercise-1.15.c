/* K&R C exercise1.15 P27 */

#include<stdio.h>

int convert(int fahr);

int main(void) {
    int fahr, cels;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    
    fahr = lower;
    while ( fahr <= upper ) {
        cels = convert(fahr);
        printf("%d\t%d\n", fahr, cels);
        fahr += step;
    }
    return 0;
}

/* Function convert begins. */
int convert(int fahr) {
    int cels;
    cels = 5 * ( fahr - 32 ) / 9;
    return cels;
}
