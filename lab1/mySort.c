# include <stdio.h>
# include <stdlib.h>


void mySort(int d[], unsigned int n)
{
	int i, key, j;
    
    // First loop runs from the second element to n the length of the array
    // Element at index 0 is assumed to sorted by default
    for (i = 1; i < n; i++) {

        // Current element at indice i is stored
        key = d[i];

        // Create a variable that stores the indice 1 left to the current element 
        j = i - 1;

        // Second loop runs while the j indice is greater than or equal to 0 and the value at the j indice equals the temp variable
        // This loop runs and shifts until the condition is met to terminate
        while (j >= 0 && d[j] > key) {

            // Shift elements greater than key to the right by 1
            d[j + 1] = d[j];

            // Reduces j by 1 for next loop
            j = j - 1;
        }

        // Insert the key into its correct position in the array
        d[j + 1] = key;
    }

}
