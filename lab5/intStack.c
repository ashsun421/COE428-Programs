#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


static int top = -1;
static char stack[100];

char pop()
{ 
    // If the top of the stack is -1, meaning stack is empty, return 1
    if (top == -1) {
        fprintf(stderr, "Error: Underflow\n");
        // Return null character to indicate failure
        return '\0'; 
    }
    else {
      // Get the character that is being popped, update the top of the stack and return  the popped character
        char popped = stack[top];
        top--;
        return popped;
    }
}

void push(char thing2push)
{   
  // If the top of the stack is 99, meaning stack is full, return 1
    if (top == 99) {
        fprintf(stderr, "Error: Overflow\n");
    }
    else {
      // Update the top of the stack and add the character to the stack
        top++;
        stack[top] = thing2push;
    }
}

int isEmpty()
{   
  // If the top of the stack is -1, meaning stack is empty, return 1
    if(top == -1){
      return 1;
    }
    return 0;
}

