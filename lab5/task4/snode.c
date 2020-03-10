#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>

struct snode *snode_create(char *s) 
{
 //TODO: implement snode_create, change the prototype to
 //match with header file
 //return node;
   struct snode * node;
   int length;
   node = malloc(sizeof(struct snode));
   length = strlen(s) + 1;
   node->str = malloc(sizeof(length));
   strcpy(node->str, (char *)s);
   node->next = NULL;
   return node;
}
void snode_destroy(struct snode * s) 
{

 //TODO: implement snode_destroy
 free(s);
};
 
