#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int msb(int x);
void print_binary(int n);

//Please do not modify main().
//All your changes should be made within msb()
int main(int argc, char **argv) {
	if (argc<2) {
		printf("Invoke as %s <n> \n\twhere <n> is an integer\n",argv[0]);
		return 1;
	}
	int x=atoi(argv[1]);
	printf("X= "); 
	print_binary(x); 
	printf("\n");
	printf("The most significant bit of %d is at position %d\n",x,msb(x));
	return 0;
}

int msb(int x) {
	if (x==0) return -1;
	//we are looking for a *range* that may contain most significant 1
	//the range is defined by width (w) and end_point (ep)
	//if we say range=6, ep=3, then it describes the following scenario:
	//                 |<--w->|
	//         0000 000* **** ****
	//                        ^
	//                        |
	//                        ep
	// in which * is a wild card which could be 0 or 1                   
	int w, ep, hw, mask, i, j, n;
	w=32; // Number of bits that might contain most significant 1
	ep=0; // Rightmost bit that might contain most significant 1
        mask = 0;
	while(w>1) { //Narrow down to a single bit
		//TODO: Look at half the range of bits
                hw = (w / 2);
		//TODO: create a mask.
                mask = 1;
                for(i = w - 1; i > hw; i--){
                   n = 1;
                   for(j = i; j > hw; j--){
                      n = n * 2;
                   }
                   mask = mask + n;
                }
                mask = (mask << (hw + ep));
		// This mask is all one-bits in the left half of the range
		printf("M= "); print_binary(mask); printf(" hw=%d ep=%d\n",hw,ep);
		//TODO: use mask to figure out if the left half of the range has at least one bit   
		//If the left half of the range has a one bit, focus on only the left half
		//else focus on only the right half
                if(((x >> hw) & (mask >> hw)) != 0){ //left
                   if(w > 2){
                     ep = hw + ep;
                   }
                }
                   
		//TODO: You have ruled out either the left half of the range or the right half of the range
		//set up ep and w accordingly
                   w = w / 2;
	}
	return ep;
}
//Do not modify print_binary
void print_binary(int n) {
	int i;
	for(i=31;i>=0;i--) {
		printf("%c",(n&1<<i)?'1':'0');
		if (0==i%4) printf(" ");
	}
}
