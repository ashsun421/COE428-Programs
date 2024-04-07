#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

extern char *pop();
extern void push(char *);
extern int isEmpty();

int main(int argc, char *argv[]) {
    // Check arguments, gives an error if no arguments are given after command is initiated
    if (argc != 2) {
        fprintf(stderr, "Usage: %s '<input>'\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    int i;

    // Loop runs until end of the input string
    for (i = 0; input[i] != '\0'; i++) {
        // If the character is not a letter or a '<' or a '>' or a '/', continue
        if (!(isalpha(input[i]) || input[i] == '>' || input[i] == '<' || input[i] == '/')) {
            continue;
        }

        else if (isEmpty() == 0 || isalpha(input[i]) || input[i] == '>' || input[i] == '<' || input[i] == '/') {
            // Increment by one for next character
            i++;

            // If the character is a letter, store it in a temporary string and push it to the stack
            if (isalpha(input[i])) {
                // Creates a string called temp with memory allocated for it
                char *temp = malloc(2 * sizeof(char));

                // If the string is null return 1
                if (temp == NULL) {
                    return 1;
                }
                int j = 0;
                // While the character is not null or '>' store the characters in a temporary string, then push that temp string onto the stack
                while (input[i] != '\0' && input[i] != '>') {
                    temp[j] = input[i];
                    i++;
                    j++;
                }
                // reset the temp string to null for the next case
                temp[j] = '\0';
                // Push the word to the stack
                push(temp);
            } 
            // If the character at input[i] is a '/', run this
            else if (input[i] == '/') {
                i++;
                char *popped = pop();
                // If the stack is empty or the popped character is not equal to the input character, print invalid error and return 1
                if (popped == NULL || popped[0] != input[i]) {
                    fprintf(stderr, "Invalid, not balanced\n");
                    return 1;
                } 
                else {
                    printf("Valid, balanced\n");
                    return 0;
                }
            }
        }   
        // If the stack is empty, print invalid error and return 1
        else if (isEmpty() == 1) {
            fprintf(stderr, "Invalid, stack is empty\n");
            return 1;
        }
    }

    // If the loop completes and the stack is not empty, it means there are unclosed tags
    if (!isEmpty()) {
        fprintf(stderr, "Invalid, No endtags to balance\n");
        return 1;
    }
}
