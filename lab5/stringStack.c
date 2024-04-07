#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static int top = 0;
static char *stack[100];

char *  pop()
{
    if(top == -1 || top == 0){
      // If the top of the stack is -1 or 0, meaning stack is empty, return 1
      fprintf(stderr, "Error: Underflow\n");
      return NULL;
    }
    else{
      // Character that is popped
      char *popped = stack[top];;
      top = top - 1;
      return popped;  //A dummy return statement
    }
}

void push(char * thing2push)
{
    if(top == 99){
      fprintf(stderr, "Overflow ");
    } 
    else {
        top++;
        stack[top] = thing2push;
    }
}

int isEmpty()
{
    if(top == -1 || top == 0){
      return 1;
    }
    else{
      return 0;
    }
}