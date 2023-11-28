#ifndef TREE_H
#define TREE_H
#include <stdio.h>
#include "node.h"

typedef struct {
	node_t *root;
} tree_t;

node_t* buildTree(FILE *);
void createNode(tree_t *, FILE *);
void insert0(node_t *, tree_t*);
void insert1(node_t*, node_t *);
void traverseInorder(node_t *, const char []);
void traversePreorder(node_t *, const char []);
void traversePostorder(node_t *, const char []);
void printInOrder(node_t *, int, FILE *);
void printPreOrder(node_t *, int, FILE *);
void printPostOrder(node_t *, int, FILE *);
void visitNode(node_t *, int, FILE *);






/*
typedef struct{
    tree_node *root;
} tree_t;

tree_node *buildTree(FILE *);
void createNode(tree_t *, FILE *);
void insert0(tree_node *, tree_t *);
void insert1(tree_node *, tree_node *);
void traversePreOrder(tree_node *, const char []);
void displayPreOrder(tree_node *, int, FILE *);
void traverseInOrder(tree_node *, const char[]);
void displayInOrder(tree_node *, int, FILE *);
void traversePostOrder(tree_node *, const char []);
void displayPostOrder(tree_node *, int, FILE *);
void goToNode(tree_node *, int, FILE *);
*/

#endif
