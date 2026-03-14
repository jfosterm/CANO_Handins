#include <stdlib.h>
#include <stdio.h>
/*
* The goal of this program is to act as a stack and can adapt to hold an arbitrary number of elements. 
* The program will do this by allocating memory from time to time, and freeing previously used memory.
* Implementation inspiration from linked-list exercise.
*/

// Rename int as the type of value we store on the stack
// In case we want to change it later.
typedef int stack_int;
// We type def stack and st_item for ease
typedef struct stack stack;
typedef struct st_item st_item;

// Define the stack
struct stack {
     int capacity;
     int top;
     st_item *top_item;
};
// Define an element of the stack
struct st_item {
     stack_int value;
     // Used for printing
     st_item *prev;
};

// Create an empty stack with capacity of 2
stack *stack_alloc(void){
     // Init the stack in memory
     stack *new_s = (struct stack *) malloc(sizeof(stack));
     // We check the malloc was successful.
     // If unsuccessful, we will return null without trying to alter properties 
     // If successful, we set capacity to 2, and the top pos to -1 (since no items are on the stack ie. 0 indexing)
     if (new_s != NULL){
          new_s->capacity = 2;
          new_s->top = -1;
          // Furthermore, we initialize the top variable to be NULL, as the stack points to nothing (no elements)
          new_s->top_item = NULL;
     }  
     return new_s;
}

// Return the current height (number of elements) on the given stack
// We take a pointer to a stack as input
int stack_height(stack *s){
     return s->top; 
}

// Return the capacity of a stack
// We take a pointer to a stack as input
int stack_capacity(stack *s){
     return s->capacity; 
}

// Print stack with spaces
// Inspiration taken from implementation of ll_printLinkedList function from exercise
void stack_print(stack *s){
     st_item *i=s->top_item;
     do {
          printf(" %d ", i->value);
          // We then go one down in the stack
          i=i->prev; 
     } while(i->value != -1);
}

int main(){
    //  We now remove everthing and make sure no memory leaks happen:
    //for (;;) {
    //    if (ll_removeNextItem(first)) break;
    //}
    //free(first);
}

