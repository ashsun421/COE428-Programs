#include "mySort.h"
#include <stdio.h> 
#include <stdlib.h>

void mySort(int array[], unsigned int first, unsigned int last)
{
	int i, key, j;

	for (i = first; i <= last;i++){ 
		key = array[i];
    	j = i - 1;
		// Compares the value on the left with the current key value for the length of the array to the left
	    while (j >= 0 && myCompare(array[j], key)>0) {

			// Swaps the values if they are not in order
	        mySwap(&array[j+1], &array[j]);
	        j = j - 1;
	    }

	// Copies the new array into the original array and returns
	myCopy(&key, &array[j+1]);
	}
	

}
