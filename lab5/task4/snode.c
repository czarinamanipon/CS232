#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "snode.h"

struct snode *snode_create(char *s) 
{
 //TODO: implement snode_create, change the prototype to
 //match with header file
 //return node;
   struct snode *new;
   new = malloc(sizeof(struct snode *));
   new->str = s;
   return new;
}
void snode_destroy(struct snode *s) 
{

 //TODO: implement snode_destroy
   free(s);
};
 
