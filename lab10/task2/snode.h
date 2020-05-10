#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "frame.h"

#ifndef _snode_H_
#define _snode_H_

struct snode {
   frame_t * frame;
   struct snode * next;
};


struct snode *snode_create(frame_t*f) ;
void snode_destroy(struct snode * s) ;


#endif
