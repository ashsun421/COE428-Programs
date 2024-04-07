#include <stdio.h>
 
#include <stdlib.h>
 
#include "mySort.h"
 
 
 
int main(int argc, char * argv[])
 
{
 
    int data[100000]; /* Array of ints to sort */
 
    int nDataItems;   /* number of actual items in the array */
 
    int i;

	
    
    // Modified the code given in cmdlineArgsDemo.c in order to work with the sorting algorithm
	if(argc > 1){
        
        fprintf(stderr, "I was invoked with the command: %s\n", argv[0]);

        // For loop that runs for each of the command line arguments
		for(i = 1; i < argc; i++) {
            // Converts the arguments to int
            data[i] = atoi(argv[i]);
        }

        // Uses teh sorting algorithm on the converted data
        mySort(data, argc);

        // Checks if then command line arguments data are all sorted
        for(i = 0; i < argc-1; i++) {
 
            if (data[i] > data[i+1]) {
    
                fprintf(stderr, "Sort error: data[%d] (= %d)"
    
                " should be <= data[%d] (= %d)- -aborting\n",
    
                i, data[i], i+1, data[i+1]);
    
                exit(1);
    
            }
 
        }

        /* Print sorted array in length of the command line arguments to stdout */
        for(i = 1; i < argc; i++) {
    
            printf("%d\n", data[i]);
    
        }
    
        exit(0);
                
		
	}

	else{

        // Hard coded data to be sorted if no command line arguments are given
        nDataItems = 4;
        data[0] = -6;
        data[1] = 20;
        data[2] = 30;
        data[3] = 10;
        
		mySort(data, nDataItems);

        /* Check that the data array is sorted. */
    
        for(i = 0; i < nDataItems-1; i++) {
    
            if (data[i] > data[i+1]) {
    
                fprintf(stderr, "Sort error: data[%d] (= %d)"
    
                " should be <= data[%d] (= %d)- -aborting\n",
    
                i, data[i], i+1, data[i+1]);
    
                exit(1);
    
            }
    
        }
 
        /* Print sorted array to stdout */
    
        for(i = 0; i < nDataItems; i++) {
    
            printf("%d\n", data[i]);
    
        }
    
        exit(0);
    }
	

	
 
}
