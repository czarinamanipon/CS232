#include "slist.h"
#include "snode.h"

struct slist * slist_create(){

/**
 * Allocates new slist dynamically.
 *
 * @return pointer to the list
 */

   struct slist *newlist;
   frame_t *front, *back;
   front = malloc(sizeof(struct front_t*));
   back = malloc(sizeof(struct front_t*));
   newlist = malloc(sizeof(struct slist));
   newlist->front = snode_create(front);
   newlist->back = snode_create(back);
   newlist->front->next = newlist->back;
   newlist->size = 0;
   return newlist;

}


struct snode* slist_add_back(struct slist *l, frame_t*str){
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
   l->size = l->size + 1;
   return newback;
}

/*
 * Inserts new node in slist before the first node.
 *
 * @param l pointer to the list (non-NULL)
 * @param str pointer to a C string to store in new list node
 * returns a pointer to the newly added node
 */
struct snode* slist_add_front(struct slist *l, frame_t*str){
   struct snode *newfirst;
   newfirst = snode_create(str);
   newfirst->next = l->front;
   l->size = l->size + 1;
   return newfirst;
}

/*
 * Returns the first snode with the given string.
 *
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 *
struct snode* slist_find(struct slist *l, frame_t*str){
   struct snode *curr;
   curr = l->front;
   do{
      if(strcmp(curr->str, str)){
          return curr;
      }
      curr = curr->next;
   }while(curr != NULL);
   return NULL;
} */

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
 *
void slist_traverse(struct slist *l){
   struct snode *curr;
   curr = l->front;
   while(curr != NULL){
      printf("%s\n", curr->str);
      curr = curr->next;
   }
} */


/* Returns the number of elements in the list (nodes).
 *
 * @param l pointer to the list (non-NULL)
 */
uint32_t slist_length(struct slist *l){
   /*uint32_t x = 0;
   struct snode *curr;
   curr = l->front;
   do{
      x++;
      curr = curr->next;
   }while(curr != NULL); */
   return l->size;;
}


 /* Deletes the first snode with the given string.
 *
 * @param l pointer to the list (non-NULL)
 * @parap str pointer to a string
 * @return struct snode* or NULL if no match
 *
void slist_delete(struct slist *l, frame_t *str){
   struct snode *curr, *prev;
   curr = l->front;
   prev = l->front;
   do{
      if(strcmp(curr->str, str)){
          if(curr == l->front){
             l->front = curr->next;
          } else {
             prev->next = curr->next;
             snode_destroy(curr);
          }
          break;
      }
      prev = curr;
      curr = prev->next;
   }while(curr != NULL);
   l->size = l->size - 1;
} */
