#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int size = 0;
int heap[10];

/**
 *  The functions in this module implement a Heapdata
 */

int heapDelete()
{
    //Assigns the root to a temporary variable
    int temp = heap[0];//root
    // Decreases the size of the heap by 1
    size--;
    // Places the temporary variable at the end of the heap as the lowest child
    heap[0] = heap[size];//lowest child
    // Places the root at the end of the heap
    heap[size] = temp;
    // Calls heapify on the root to sort the children
    heapify(0);
    //  Returns the deleted element
    printf("%d\n",heap[size]);
    return heap[size];  //returns root
}

/** 
addHeap(thing2add) adds the "thing2add" to the Heap.**/
void addHeap(int thing2add)
{
    // Adds the element to the end of the heap
    heap[size] = thing2add;
    //printf("added'%d'", heap[size]);
    size++;
}

/* heapSize() returns the number of items in the Heap.**/
int heapSize()
{
  // Returns the size of the heap
  return size;  //A dummy return statement
}

void heapify(int node){
    int temp;
    // gets index for left and right children
    int left = (2 * node) + 1;
    int right = (2 * node) + 2;
    // sets the parent to the node
    int parent = node;

    // if the left child is greater than the parent, set the parent to the left child
    // Swaps parent and child
    if((left < size) && (heap[left] > heap[parent]))
        parent = left;

    // if the right child is greater than the parent, set the parent to the right child
    // Swaps parent and child
    if((right < size) && (heap[right] > heap[parent]))
        parent = right;

    // if the parent is not the node, swap the parent and the node
    if(parent != node) {
        // Stores the parent as a temp variable
        temp = heap[parent];
        // Swaps the parent and the node
        heap[parent] = heap[node];
        // Overwrites and stores the node as a tmep variable
        heap[node] = temp;
        // Recursively calls heapify on the parent to sort the children
        heapify(parent);
        // Recursively call heapify on the root
        heapify(0);
    }

}

void printXML(int node){
    //gets index for left and right children
    int left = (2 * node) + 1;
    int right = (2 * node) + 2;

    printf("<node id='%d'>\n", heap[node]);
    if(left<size)
        printXML(left);//recursively print left children

    if(right<size)
        printXML(right);//recursively print right children

    printf("</node>\n");//print closing tag
}