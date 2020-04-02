#include "slist.h"
#include "snode.h"


struct slist * slist_create(){

/**
 * Allocates new slist dynamically.
 * 
 * @return pointer to the list
 */

   struct slist *newlist;
   newlist = malloc(sizeof(struct slist));
   newlist->front = snode_create("");
   newlist->back = snode_create("");
   newlist->front->next = newlist->back;
   return newlist;

}


struct snode* slist_add_back(struct slist *l, char *str){
/*
 * Inserts new node in slist after the last node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
   
   struct snode *newback;
   newback = snode_create(str);
   l->back->next = newback;
   l->back = newback;
   return newback;
}

/*
 * Inserts new node in slist before the first node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_front(struct slist *l, char *str){
   struct snode *newfirst;
   newfirst = snode_create(str);
   newfirst->next = l->front;
   return newfirst;
}

/*
 * Returns the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 */
struct snode* slist_find(struct slist *l, char *str){
   struct snode *curr;
   curr = l->front;
   do{
      if(strcmp(curr->str, str)){
          return curr;
      }
   }while(curr->next != NULL);
   return NULL;
}

/*
 * Deallocate a list and all snodes
 *
 * @param l pointer to the list
 */
void slist_destroy(struct slist *l){
   struct snode *curr, *currNext;
   curr = l->front;
   currNext = curr->next;
   do{
      snode_destroy(curr);
      curr = currNext;
      currNext = currNext->next;
   }while (currNext != NULL);
   snode_destroy(curr);
   snode_destroy(currNext);
   free(l);
}

/*
 * Traverse the list and print the content of each node.
 *
 * @param l pointer to the list (non-NULL)
 */
void slist_traverse(struct slist *l){
   struct snode *curr;
   curr = l->front;
   do{
      printf("%s\n", curr->str);
   }while(curr->next != NULL);
}


/* Returns the number of elements in the list (nodes).
 *
 * @param l pointer to the list (non-NULL)
 */
uint32_t slist_length(struct slist *l){
   uint32_t x = 0;
   struct snode *curr;
   curr = l->front;
   do{
      x++;
      curr = curr->next;
   }while(curr != NULL);
   return x;
}


 /* Deletes the first snode with the given string.
 *  
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 */
void slist_delete(struct slist *l, char *str){
   struct snode *curr, *prev;
   curr = l->front;
   do{
      prev = curr;
      if(strcmp(curr->str, str)){
          prev->next = curr->next;
          snode_destroy(curr);
          break;
      }
      curr = curr->next;
   }while(curr != NULL);
}

struct snode * slist_get_front(struct slist *l){
   return l->front;
}
struct snode * slist_get_back(struct slist *l){
   return l->back;
}

struct snode *slist_find_at(struct slist *l, int index){
   struct snode *curr;
   int i;   
   if(index >= 0){
      curr = l->front;
      for(i = 0; i <= index; i++){
         curr = curr->next;
      }
   }else if(index < 0){
      curr = l->back;
      for(i = 0; i >= index; i--){
         curr = curr->next;
      }
   }
   return curr;
}

void slist_delete_at(struct slist *l, int index){
   struct snode *curr;
   int i;   
   if(index >= 0){
      curr = l->front;
      for(i = 0; i <= index; i++){
         curr = curr->next;
      }
   }else if(index < 0){
      curr = l->back;
      for(i = 0; i >= index; i--){
         curr = curr->next;
      }
   }
   snode_destroy(curr);
}
