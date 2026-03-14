#include <stdlib.h>
#include <stdio.h>

/*  The goal of this exercise is to create a bidirectional circular 
 *  linked list. Bidirectional means that each linked list element
 *  should have previous and next pointers.
 *  Circular means that the topology of the linked list should be a
 *  cycle, meaning, it wraps around, i.e., by following the next
 *  or previous pointers should eventually get back to where we 
 *  started.
*/

// Rename int as the type of value we store at the linked list
// In case we want to change it later.
typedef int ll_int;

// If the linked list has 1 element, removal should return an error
#define CARCH_LL_DEL_ERR 1

typedef struct ll_item ll_item;
// Define an element of the linked list.
struct ll_item {
    ll_item *prev;
    ll_item *next;
    ll_int value;
};


/*********************************************
** NOW COMES THE INCOMPLETE METHODS!!       **     
** YOU NEED TO FINISH THE IMPLEMENTATION!   **    
*********************************************/

// Given "value", create a bidirectional circular linked 
// list containing a single item; prev and next pointers should point
// to itself. Return a pointer to the linked list.
ll_item *ll_createLinkedList(ll_int value){
     // Initialize the item in memory
     ll_item *item = (struct ll_item *) malloc(sizeof(ll_item));
     // Set the prev and next item to point to itself and the value to the value given
     item->prev = item;
     item->next = item;
     item->value = value;
     // Return the pointer 
     return item;
}

// Create an linked list item containing "value" and 
// then insert it after ll.
// Return a pointer to the inserted item
ll_item *ll_insertAfter(ll_int value, ll_item *ll){
     // Initi the item in memory
     ll_item *item = (struct ll_item *) malloc(sizeof(ll_item));
     // Set the new items previous to be the item passed in the function argument
     // We want the new item to point to what the given item pointed at, as we effectively want to put
     // it between the given item and the item that the given item.next was.
     item->prev = ll;
     item->next = ll->next;
     item->value = value;
     // We make sure to update the given item so that it now points to the new item
     ll->next = item;
     // Lastly we make sure the next points its prev to the new item
     ll->next->prev = item;
     return item;
}


// Remove the ll_item after "item" from the linked list and free 
// the used memory. Should return error if the linked list has only one element.
int ll_removeNextItem(ll_item *item){
     // We first check if the list only has one item, by seeing if it points to itself
     if (item->next == item){
          return CARCH_LL_DEL_ERR;
     }
     // Init the item we want removed, we store in a variable so we can free it later
     ll_item *item_rm = item->next;
     // We set the given item to point two forward, by pointing to next.next essentially
     item->next = item_rm->next;
     // Then we must make sure we also change that items previous to be the given item
     item_rm->next->prev = item;
     //lastly we free the memory allocated to item_rm
     free(item_rm);
     return 0; // Success
}

// I wrote these just for testing!
void ll_printLinkedList(ll_item *item){
    ll_item *i=item;
    do {
        printf("->(%d)",i->value);
        i=i->next;
    } while (i!=item);
    printf("\n");
}

int main(){
    ll_item *first = ll_createLinkedList(0);
    ll_item *last = first;
    for (int i=1; i<10 ; i++) {
        last = ll_insertAfter((ll_int)i,last);
    }
    // Let us print!
    ll_printLinkedList(first);
    // Must get the output:
    //  ->(0)->(1)->(2)->(3)->(4)->(5)->(6)->(7)->(8)->(9)
    // Remove the even ones!
    last = first;
    do { 
        if (ll_removeNextItem(last)) break; 
        last = last->next;
    } while (last != first);
    ll_printLinkedList(first);
    // Must get the output:
    //  ->(0)->(2)->(4)->(6)->(8)
    //  We now remove everthing and make sure no memory leaks happen:
    for (;;) {
        if (ll_removeNextItem(first)) break;
    }
    free(first);
}
