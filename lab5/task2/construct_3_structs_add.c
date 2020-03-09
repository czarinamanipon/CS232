#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    //TODO:copy setup func from task1
    node_t *head, *node1, *node2, *node3;
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

void teardown(node_t * head) {
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
   int i;
   node_t * tempNext;
   for(i = 0; i < 3; i++){
      tempNext = head->next;
      free(head);
      head = tempNext;
   }
   free(head);  
}

void add(node_t ** head, char * str, int length){
    //TODO: implement add to add a new node to front, pointed by head
    node_t *newNode;
    newNode = malloc(sizeof(node_t));
    newNode->length = length;
    strcpy(newNode->str, str);
    newNode->next = *head;
    *head = newNode;
}

//You can ignore the following code for testing
void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    dump_all(head);
    teardown(head);
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
