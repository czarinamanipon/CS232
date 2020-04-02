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
   node_t * tempNext;
   tempNext = head->next;
   do{
      free(head);
      head = tempNext;
      tempNext = head->next;
   } while(tempNext != NULL);
   free(tempNext);
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
void delete_node_at(node_t ** head, int idx) {
    //TODO: implement delete a node based on index
	//deletes a node at index idx, which ranges from zero to the length of the list - 1.
   node_t *curr, *nextNode;
   int i;
   curr = *head;
   for(i = 0; i < idx; i++){
      curr = curr->next;
   }
   nextNode = curr->next;
   curr->length = nextNode->length;
   strcpy(curr->str, nextNode->str);
   curr->next = nextNode->next;
   free(nextNode);
} 
void delete_node_key(node_t **head, char * key) {
    //TODO: implement delete a node based on key
	//given a certain key, find and delete. 
   node_t *curr, *prev;
   curr = *head;
   int matchFound = 0;
   do{
      if(strcmp(curr->str, key) == 0){
         matchFound = 1;
      }else{
         prev = curr;
         curr = curr->next;
      }
   }while ((curr != NULL) && !(matchFound));
  
   if(matchFound){
      if(curr->next != NULL){
         prev->next = curr->next;
      }else if(curr->next == NULL){
         prev->next = NULL;
      }
      free(curr);
   }
}
//You can ignore the following code for testing
void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    delete_node_key(&head, "prof");
    delete_node_at(&head, 0);
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
