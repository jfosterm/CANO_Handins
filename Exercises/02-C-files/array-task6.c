#include<stdlib.h>
#include<stdio.h>
// Task 5 - method 1: Compile-time allocation
int main(){
    printf("Method 1: Compile-Time allocation: \n");	
    // Initialized array	
    int a[10];
    for(int i=0; i < 10; i++){
        a[i] = i*i;
        printf("a[%d] = %d\n",i,a[i]);
    }
    printf("The size of a[] = %zu bytes\n", sizeof(a));
  
// Task 6 - method 2: Run-time allocation    
    printf("\n\nMethod 2: Run-time allocation: \n");	
    // Initialized array	
    int *b = malloc(sizeof(int)*10);
    for(int i=0; i < 10; i++){
        b[i] = i*i;
        printf("b[%d] = %d\n",i,b[i]);
    }
    printf("The size of b[] = %zu bytes\n", sizeof(b));
    free(b); // Frees the memory allocated to the array (Usually used when we are done using the array
	     // and no longer need to access it) Good Practice
}   
