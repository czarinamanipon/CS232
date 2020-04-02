#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct snode {
  //TODO: change str to dynamic allcoation
   char str[101];
   int length;
   struct snode * next; 
};
