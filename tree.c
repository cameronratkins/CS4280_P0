#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"
#include "node.h"

static const int WORD_LENGTH = 16;

//Create node from file contents
void createNode(tree_t *BST, FILE *inputFile){
    char word[WORD_LENGTH];
    fscanf(inputFile, "%s", word);
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->left_child = NULL;
    newNode->right_child = NULL;
    newNode->key = strlen(word);
    strcpy(newNode->words, word);
    insert0(newNode, BST);
}

//Constructs the BST until EOF
node_t *buildTree(FILE *inputFile) {
    tree_t BST = {.root = NULL};
    while (!feof(inputFile)) {
        createNode(&BST, inputFile);
    }
    return BST.root;
}

//Insert node into tree
void insert0(node_t *newNode, tree_t *BST){
    if (BST->root == NULL){
        BST->root = newNode;
    }
    else{
        insert1(newNode, BST->root);
    }
}

//function to insert subsequent nodes
void insert1(node_t *newNode, node_t *currentNode){
    if(newNode->key > currentNode->key){
        if (currentNode->right_child == NULL){
            currentNode->right_child = newNode;
        }
        else{
            insert1(newNode, currentNode->right_child);
        }
    }
     else if (newNode->key == currentNode->key) {
        if (strstr(currentNode->words, newNode->words) == NULL) {
            strcat(currentNode->words, " ");
            strcat(currentNode->words, newNode->words);
        }
    }
    else {
        if (currentNode->left_child == NULL) {
            currentNode->left_child = newNode;
        }
        else {
            insert1(newNode, currentNode->left_child);
        }
    }
}

// PreOrder Traversal of the BST
void traversePreOrder(node_t *n, const char file[]) {
    const char file_extension[] = ".preorder";
    char outFile[strlen(file) + strlen(file_extension)];
    strcpy(outFile, file);
    strcat(outFile, file_extension);
    FILE *outfptr = fopen(outFile, "w");
    if (!outfptr) {
        printf("Error: File %s could not be opened", outFile);
        exit(1);
    }
    printPreOrder(n, 0, outfptr);
    fclose(outfptr);
}

// Write Preorder to File
void printPreOrder(node_t *n, int depth, FILE *outfptr) {
    if (n != NULL) {
        visitNode(n, depth, outfptr);
        printPreOrder(n->left_child, depth+1, outfptr);
        printPreOrder(n->right_child, depth+1, outfptr);
    }
}

// InOrder Traversal of the BST
void traverseInOrder(node_t *n, const char file[]) {
	const char file_extension[] = ".inorder";
        char outFile[strlen(file) + strlen(file_extension)];
        strcpy(outFile, file);
        strcat(outFile, file_extension);
        FILE *outfptr = fopen(outFile, "w");
        if (!outfptr) {
            printf("error: File %s could not be opened", outFile);
            exit(1);
        }
    	printInOrder(n, 0, outfptr);
    	fclose(outfptr);
}

// Write InOrder to File
void printInOrder(node_t *n, int depth, FILE *outfptr) {
	if (n != NULL) {
        	printInOrder(n->left_child, depth + 1, outfptr);
            	visitNode(n, depth, outfptr);
		printInOrder(n->right_child, depth + 1, outfptr);
        }
}

// PostOrder Traversal of the BST
void traversePostOrder(node_t *n, const char file[]) {
        const char file_extension[] = ".postorder";
        char outFile[strlen(file) + strlen(file_extension)];
        strcpy(outFile, file);
        strcat(outFile, file_extension);
        FILE *outfptr = fopen(outFile, "w");
        if (!outfptr) {
            printf("Error: File %s could not be opened", outFile);
            exit(1);
        }
	printPostOrder(n, 0, outfptr);
    	fclose(outfptr);
}

// Write PostOrder to File
void printPostOrder(node_t *n, int depth, FILE *outfptr) {
        if (n != NULL) {
            printPostOrder(n->left_child, depth + 1, outfptr);
            printPostOrder(n->right_child, depth + 1, outfptr);
            visitNode(n, depth, outfptr);
        }
}

void visitNode(node_t *n, int depth, FILE *outfptr) {
    fprintf(outfptr, "%*s%d: %s\n", depth * 2, "", n->key, n->words);
}

