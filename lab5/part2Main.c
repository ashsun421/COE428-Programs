#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();

extern void addHeap(int);
extern int heapSize();
extern int heapDelete();
extern void heapify(int);
extern void printXML(int node);

int main(int argc, char * argv[])
{
    int value;
    char input;
    //runs until user inputs 'E'
    while (1) {
      //  gets input from user and checks if it is 'E' or not
        input = getchar();
        //if input is 'e' break the loop else continue to next statement
        if (input == 'e') {
            break;
        }
        //if input is not 'e' and input is not nothing check if it is a number or not
        else if (input != '\n') {
            // if input is not a number, empty or the exit condition, put the input back into the input stream
            ungetc(input, stdin);
            //if the value entered is not a number print invalid and exit
            if (scanf("%d", &value) != 1) {
                fprintf(stderr, "Invalid.\n");
                exit(1);
            }
            // Adds the user input value to the heap
            addHeap(value);
        }
    }

  // Gets the size of the heap
  int size = heapSize();
  for(int i = 0; i < size; i++){
    //heapify is called on the heap for every element entered and is sorted 
    heapify(i);
  }

  // Prints the tree once the heap is sorted
  printf("\nXML Tree:\n");
  printXML(0);

  // Deletes the highest node from the heap and pushes it onto the stack until it is empty
  printf("\nDeleted nodes highest to lowest:\n");
  for(int i = 0; i < size; i++){
    push(heapDelete(i));
  }
  // Pops the stack in sorted order printing each deleted node, stack is now sorted
  printf("\nPopped from stack in sorted order:\n");
  for(int i = 0; i < size; i++){
    printf("%d\n", pop());
  }
  exit(0);
}