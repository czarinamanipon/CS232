#include <stdio.h>

int tag[2][4];
int mru[4] = {1,1,1,1};

int main( )
{
    int addr;
    int hits, accesses;
    FILE *fp;

    fp = fopen("trace.txt", "r");
    hits = 0;
    accesses = 0;

    int i, t;
    int j; //indexing
    while (fscanf(fp, "%x", &addr) > 0) {
        /********* YOUR CODE HERE ************/
        accesses += 1;
        printf("%3d: 0x%08x ", accesses, addr);
        i = (addr >> 2) & 7;
        t = addr | 0x1f;

        if((tag[0][t] == addr) || (tag[1][t + 4] == addr)){
          hits += 1;
          printf("Hit%d ", i);
        } else {
            /* allocate entry */
            printf("Miss ");
            tag[i][t] = t;
        }
        for(j = 4; j > 0; j--){
            mru[j] = mru[j - 1];
        }
        mru[0] = i;
    }
    printf("Hits = %d, Accesses = %d, Hit ratio = %f\n", hits, accesses, ((float)hits)/accesses);
    fclose(fp);
}
