#include<stdlib.h>
#include<stdio.h>
int main(){
// Task 10 - Overlapping two arrays
     // decl pointers a and b
     int *a, *b;

     // Allocate memory for a[100]
     a = malloc(sizeof(int)*100);

     // Set the address of b to be the 51st element of a
     // b = malloc(sizeof(int)*50); is not used, as it would cause a memory leak since we assign it to
     // a[50] right after, making us unable to free the space later
     b = &a[50];
     
     // Init a
     for (int i =0; i < 100; i++){
          a[i]=i;
     }

     //Next we see how this affects the b array, even though we only initialized a,
     //we iterate the first 5 values of b
     for (int i =0; i < 5; i++){
     printf("The element b[%d] = %d \n",i, b[i]);
     }
     // Freeing the memory allocated to a
     free(a);
     // Task 11 - if we run the function free(b), we will get an error pertaining to segmantation fault,
     // Since b is not the head of the heap of memory.
     

}
