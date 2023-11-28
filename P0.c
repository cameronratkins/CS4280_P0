/*
Cameron Atkins
CompSci 4280
Project 0
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"
#include "node.h"

int main(int argc, char *argv[]){    
	FILE *ifptr = NULL;
    	char *fname = NULL;
	int c;

	
	//Append f.23 to the file 
    	if (argc == 2){
		const char file_extension[] = ".f23";
        	fname = (char *) malloc(sizeof(argv[1]));
        	strcpy(fname, argv[1]);
        	char iFile[strlen(fname) + strlen(file_extension)];
        	strcpy(iFile, fname);
        	strcat(iFile, file_extension);
        	ifptr = fopen(iFile, "r");
        
       		 //Print error if unable to open file
        	if(ifptr == NULL){
            	printf("Unable to open file %s.\n", iFile);
            	return(1);
        	}

	}
	
	else {
                const char outputfname[] = "out";
                fname = (char *) malloc(sizeof(outputfname));
                strcpy(fname, outputfname);
                ifptr = stdin;
        }

    	node_t *root = buildTree(ifptr);
    	traverseInOrder(root, fname);
    	traversePreOrder(root, fname);
    	traversePostOrder(root, fname);

    	fclose(ifptr);
    	free(fname);

    return 0;
}
 
