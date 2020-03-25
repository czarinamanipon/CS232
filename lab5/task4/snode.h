#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct snode {
  //TODO: change str to dynamic allcoation
   char * str;
   struct node * next; 
};

//TODO: change prototypes of functions to remove
//length
struct snode *snode_create(char *s) ; 
void snode_destroy(struct snode *n) ;
 
