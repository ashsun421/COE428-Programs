#include <stdlib.h>
#include <stdio.h>
#include "towers.h"

int main(int argc, char **argv)
{
    int n;
    int from;
    int dest;

    // For 1 argument
    if (argc == 2) {
        n = atoi(argv[1]);
        from = 1;
        dest = 2;
        
    }

    // For 3 arguments
    else if(argc == 4){
        n = atoi(argv[1]);
        from = atoi(argv[2]);
        dest = atoi(argv[3]);
    }

    // for no arguments
    else if (argc == 1){
        n = 3;
        from = 1;
        dest = 2;
        
    }

    
    if(from < 1 || from > 3 || dest < 1 || dest > 3){
        fprintf(stderr, "Invalid Command, There are only 3 towers");
        exit(1);
    } 

    if(from == dest){
        fprintf(stderr, "Invalid Command, Origin and Destination cannot be the same");
        exit(1);
    }

    towers(n, from, dest);
    exit(0);
    
}

