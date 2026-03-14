#include <stdio.h>
#include <stdlib.h>


// The function returns the number of times HOTPO operations need to be applied
// to n to bring it down to one. E.g., collatz(1) should return 0 and collatz(2)
// should return 1.
extern int collatz(unsigned long n);

// The main function. Main expects one parameter n.
// Then, it computes collatz(1), colllatz(2), ..., collataz(n) and finds the
// a number m, 1 <= m <= n with the maximum stopping time.
int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Parameter \"n\" is missing. \n");
        return -1;
    } 
    int max = 0;
    unsigned long maxn = 0;
    int tmp = 0;
    unsigned long n = atoll(argv[1]);
    for (unsigned long i = 1; i <= n; i++) {
        tmp = collatz(i);
        if (tmp > max) {
            max = tmp;
            maxn=i;
        }
    }
    printf("The largest stopping time between 1 and %lu was %lu ", n, maxn);
    printf("with the stopping time of %d. \n", max);
}
