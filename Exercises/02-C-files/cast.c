#include<stdlib.h>
#include<stdio.h>
// Task 7    
int main(){    
    printf("\nTask 7\n");	
    // Initialized array (pointer to short) of size containing 10 shorts	
    short *s = malloc(sizeof(short)*10);
    for(int i=0; i < 10; i++){
        s[i] = i+1;
    }
    printf("The size of s[] = %zu bytes\n", sizeof(s));
    //Task 8 - Modify previous program
    int *t;
    t = s; 
    for(int i=0; i < 5; i++){
        printf("t[%d] = %d\n",i,t[i]);
    }
    
    free(s); // Frees the memory allocated to the array (Usually used when we are done using the array
	     // and no longer need to access it) Good Practice
}   
