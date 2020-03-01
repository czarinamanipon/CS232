#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    char * value; //must use dynamic allocation
    struct node* next;
} node_t;

node_t * construct_3_strs() {
    //return NULL;//just to pass compiler, please edit as needed.
    node_t *x, *node1, *node2, *node3;
    
    node1 = malloc(sizeof(char));
    node2 = malloc(sizeof(char));
    node3 = malloc(sizeof(char));
    
    node1->value = "CS23";
    node2->value = "is";
    node3->value = "awesome";
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;
    
    x = node1;
}

//You can ignore the following code for testing
int dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * x = construct_3_strs();
    return dump_all(x);

}

int dump_all(node_t * x) {
    printf("x -> %s", x->value);
    node_t * y = x->next;
    printf(" %s", y->value);
    node_t * z = y->next;
    printf(" %s\n", z->value);
    if(z->next != x) {
        printf("failed");
        return -1;
    } else {
        return 0;
    }
}
