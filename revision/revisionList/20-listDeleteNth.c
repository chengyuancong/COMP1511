// week11/listDeleteNth
// delete Nth item from a linked list

#include <assert.h>
#include <stdlib.h>
#include "list.h"

// assuming n is always valid
void listDeleteNth (List l, int n) {
    assert (l != NULL);

    if (l->head != NULL) {
        if (n==0) {
             listDeleteHead(l);
        } else {
        	Node prev = l->head;
        	Node curr = l->head->next;
        	int i = 1;
        	while (curr != NULL && i < n) {
        		i++;
        		prev = curr;
            	curr = curr -> next;
        	}
            if ( i == n && curr != NULL) {
        			prev->next = curr->next;
        			free(curr);
            }
       }
   }     
}
