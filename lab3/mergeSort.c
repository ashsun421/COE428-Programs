#include "mySort.h"
void myMerge(int arr[], unsigned int first, unsigned int mid, unsigned int last) {

  // Two array sizes for each half
  int n1 = (mid + 1) - first; 
  int n2 = last - mid;        

  // Two subarrays are created
  int L[n1], R[n2]; 

  // Copies values from the original array into each of the two sub arrays
  for (int i = 0; i < n1; i++) {
    myCopy(&arr[i + first], &L[i]);
  } 

  for (int i = 0; i < n2; i++) {
    myCopy(&arr[i + 1 + mid], &R[i]);
  }

  int i = 0;
  int j = 0;
  int k = first;

  // Compares values in the arrays and then copies them back into the original array in order for each sub array
  while (j < n2 && i < n1) {
    if (myCompare(R[j], L[i]) <= 0) { 
      myCopy(&R[j], &arr[k]);
      j++;

    } else {
      myCopy(&L[i], &arr[k]);
      i++;
    }
    k++;
  }

  // Copies the rest of teh subarray into the original array for each subarray
  while(i < n1){
    if (i < n1) {
      myCopy(&L[i], &arr[k]);
      // array[a] = left[i1];
      i++;
      k++;
    }
  }

  while (j < n2) {
    if (j < n2) {
      myCopy(&R[j], &arr[k]);
      // array[a] = right[i2];
      j++;
      k++;
    }
  }
}

void mySort(int arr[], unsigned int first, unsigned int last) {

  if (first < last) {
    int mid = (first + (last - 1)) / 2;

    // Recursively calls itself to sort the array then merges the subarrays into one
    mySort(arr, first, mid);
    mySort(arr, mid + 1, last);
    myMerge(arr, first, mid, last);
  }
}