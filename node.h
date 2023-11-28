#ifndef NODE_H
#define NODE_H

typedef struct node_t{
    int key;
    char words[128];
    struct node_t *left_child; //Pointer to the left node
    struct node_t *right_child; //Pointer to the right node

} node_t;

#endif
