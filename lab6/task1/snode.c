#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "snode.h"

struct snode *snode_create(char *s) 
{
 //TODO: implement snode_create, change the prototype to
 //match with header file
 //return node;
   struct snode *node;
   int length;
   node = malloc(sizeof(struct snode));
   length = strlen(s) + 1;
   node->str = malloc(length);
   strcpy(node->str, s);
   node->next = NULL;
   return node;
}
void snode_destroy(struct snode *s) 
{

 //TODO: implement snode_destroy
   free(s->str);
   free(s);
};
 
