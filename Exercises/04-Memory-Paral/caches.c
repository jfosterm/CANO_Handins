#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "comparch_time.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("%s: Need one parameter: log of the size of the array.\n", argv[0]);
        return -1;
    }
    int lsize = atol(argv[1]);  
    size_t size = (size_t)1L << lsize;  // size is 2^{lsize}
    size_t mask = size-1;
    // Sometimes if compilers can figure out that our program is not doing anything useful,
    // they can just make it do nothing. We are using argc and dummyResult variables to pretent
    // that our programm is computing something useful to fool the comiplers.
    int dummyResult=argc; 
    // Allocate and initialize the array. 
    int *A = (int *)malloc(size*sizeof(int));
    for (size_t i=0; i<size; i++) {
        A[i] = i+dummyResult;
    }

    // You can reduce 28 to 27 or lower if your code runs every slow.
    // Increase it if it runs way too fast.
    long accesses = 1L << 27;
    long index=0;
    startTimer();
    for (long j = 0; j<accesses ; j++) {
        dummyResult += A[ (j*32) & mask ]; 
    }
    double elapsed = stopTimer();

    // print the elapsed time
    if (size*sizeof(int) < (1 << 10)) {
        printf("Size: %zu B. \tElapsed: \t%f milli.\n",sizeof(int)*size,elapsed);
    } else if (size * sizeof(int) < (1 << 20)) {
        printf("Size: %zu KB. \tElapsed: \t%f milliseconds.\n",(sizeof(int)*size)>>10, elapsed);
    } else if (size * sizeof(int) < (1 << 30)) {
        printf("Size: %zu MB. \tElapsed: \t%f milliseconds.\n",(sizeof(int)*size)>>20, elapsed);
    } else {
        printf("Size: %zu GB. \tElapsed: \t%f milliseconds.\n",(sizeof(int)*size)>>30, elapsed);
    }
    return dummyResult;
}
