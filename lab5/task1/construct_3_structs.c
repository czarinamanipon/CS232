#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    node_t * head;
    node_t *node1, *node2, *node3;
    //TODO:head declared for you
    //Allocate three more pointers
    //head for the first Node, and temporary pointers node1, node2 and node3
    //Allocate three node pointees and store references to them in the three pointers
    //Dereference each pointer to store the appropriate number and string into the length and str fields in its pointee.
    //Dereference each pointer to access the .next field in its pointee,
    //and use pointer assignment to set the .next field to point to the appropriate Node.
    
    node1 = malloc(sizeof(node_t));
    node2 = malloc(sizeof(node_t));
    node3 = malloc(sizeof(node_t));
    
    node1->length = 6;
    node2->length = 6;
    node3->length = 5;

    strcpy(node1->str, "hello");
    strcpy(node2->str, "there");
    strcpy(node3->str, "prof");

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    
    head = node1;
   return head;
}

<<<<<<< HEAD
void teardown(node_t * head) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
   int i;
   node_t *tempNext;
   for(i = 0; i < 3; i++){
      tempNext = head->next;
      free(head);
      head = tempNext;
   }
   free(head);  
=======
void teardown(/*what parameter?*/) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
>>>>>>> 240f91a838b43d80908230dfd592d2c080325811
}

//You can ignore the following code for testing
void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    dump_all(head);
<<<<<<< HEAD
    teardown(head);
=======
    teardown(/*what argument?*/);
>>>>>>> 240f91a838b43d80908230dfd592d2c080325811
    return 0;
}

void dump_all(node_t * head) {
    printf("head -> ");
    node_t * cur = head;
    while(cur != NULL) {
        printf("%s ", cur->str);
        cur = cur->next;
    }
    printf("\ndone\n ");
}
