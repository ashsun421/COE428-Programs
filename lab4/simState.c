#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ROW 8
#define COLUMN 3

char states[ROW][COLUMN] = 
    {
    //    0    1    2
        {'A', 'H', 'F'}, // 0
        {'B', 'A', 'D'}, // 1
        {'C', 'D', 'G'}, // 2
        {'D', 'G', 'H'}, // 3
        {'E', 'E', 'C'}, // 4
        {'F', 'B', 'E'}, // 5
        {'G', 'F', 'B'}, // 6
        {'H', 'E', 'A'} // 7
    };

char current = 'B';

void oz(char *input){
    
    // Determines the current index 
    // Subtracts the ascii value of A from the ascii value of the current, if greater than 0 is apart of the matrix
    int index = current - 'A';

    // Update the current state based on the input 0 or 1
    if(*input == '0'){
        current = states[index][1];
        printf("%c\n", current);
    }
    else if(*input == '1'){
        current = states[index][2];
        printf("%c\n", current);
    }

}

void output(){
    for (int i = 0; i < ROW; i++){
        for(int j = 0; j < COLUMN; j++){
            printf("%c ", states[i][j]);
        }
        printf("\n");
    }
}

void garbage() {
	// Array to keep track of whihc states are reachable, assume all are unreachable at first
    bool isReachable[ROW] = {false};

	// The current state is initially the only state reachable
	// Subtracts the ascii value of A from the ascii value of the current, if greater than 0 is apart of the row
    isReachable[current - 'A'] = true; 

    // Loops to iterate through the state and transitions
    for (int i = 0; i < ROW; i++) {
        for (int j = 1; j < COLUMN; j++) {

			// Determines the index of the next state
			// Subtracts the ascii value of A from the ascii value of the current, if greater than 0 is apart of the matrix
            int nextStateIndex = states[i][j] - 'A';

			// Since the state is reachable place in reachable array
            isReachable[nextStateIndex] = true;
        }
    }

	// Initialize that all states are initally reachable
    bool allStatesReachable = true;

    // Check if all states are reachable
    for (int i = 0; i < ROW; i++) {

		// If a state is not reacahble then the allStatesReachable variable is now false because not all states are reachable
        if (!isReachable[i]) {
            allStatesReachable = false;
        }
    }

	// If not all states are reachable start printign garbage
	if(!allStatesReachable) {
        printf("\nGarbage: ");
		 // Loops through all the states
        for (int i = 0; i < ROW; i++) {
			// If the state at i is not reachable print out the unreachable states
            if (!isReachable[i]) {
				// Print the unreachable states
                printf("%c ", 'A' + i);
            }
        }
        printf("\n");
    }

	// If all states are reachable print no garbage
	else{
		printf("No garbage\n");
	}
}


void change(char *num, char *state){
    int index = current - 'A';

    if(*num == '1'){
        states[index][2] = state[0];
    }

    else if(*num == '0'){
        states[index][1] = state[0];
    }
}

void delete_wanted(char stateToDelete) {
    // Check if it's a valid state name
    if (stateToDelete >= 'A' && stateToDelete <= 'H') {
        // Find the index of the state to delete
        int indexToDelete = stateToDelete - 'A';

        // Iterate through the matrix and remove the state
        for (int i = indexToDelete; i < ROW - 1; i++) {
            for (int j = 0; j < COLUMN; j++) {
                // Move the rows up by one to delete the wanted state
                states[i][j] = states[i + 1][j];
            }
        }

        // Clear the last row as it contains nothing since its been moved up
        for (int j = 0; j < COLUMN; j++) {
            states[ROW - 1][j] = '\0'; // Replace the empty state with null character
        }

        // Iterates through the matrix and replaces the deleted state with an empty character
        for (int i = 0; i < ROW; i++) {
            for (int j = 1; j < COLUMN; j++) {
                if (states[i][j] == stateToDelete) {
					// Replace the deleted state with dash
                    states[i][j] = '-'; 
                }
            }
        }
		// Prints out which sate got deleted
        printf("Deleted state: %c\n", stateToDelete); 
    } 
    else {
        printf("Invalid state to delete\n");
    }
}

void delete_garb(){
    // Assumes all states are initially unreachable
	bool isReachable[ROW] = {false};

    // Lets the current state be reachable  if in matrix
    isReachable[current - 'A'] = true; 
    for (int i = 0; i < ROW; i++) {
        for (int j = 1; j < COLUMN; j++) {

            // If the next states are in the matrix , mark them as reachable too
            int nextStateIndex = states[i][j] - 'A';
            isReachable[nextStateIndex] = true;
        }
    }

    // Check if the provided state is garbage or a valid state to delete
	// Deletes the states in garbage
	printf("Deleted: ");
	for (int i = 0; i < ROW; i++) {

        // If a state is not reachable continue
		if (!isReachable[i]) {
            // prints the garbage state using its ascii value
			printf("%c ", 'A' + i);
            // Move the remaining rows up to delete the garbage state
			for (int k = i; k < ROW - 1; k++) {
				for (int l = 0; l < COLUMN; l++) {
                    // Copy the contents of the next row into the current row to make up for the deleted row
					states[k][l] = states[k + 1][l];
				}
			}

            // Delete the last row as it is empty
			for (int l = 0; l < COLUMN; l++) {
				states[ROW - 1][l] = '\0';
			}
		}
	}
	printf("\n");
	
}


// one/zero, print, garbage only require one argument`
// Delete command can take one or two arguments
// Change command takes 3 arguments
int main(){

	char input[10];

    printf("The starting state is %c\n", states[1][0]);

	while(1){
		printf("Enter command: ");
		scanf("%s", input);

		// When an argument is entered use string compare to determine what it is
		if(strcmp(input,"e") == 0){
			printf("Exiting machine");
			break;
		}
		// Zero command
		else if(strcmp(input, "0") == 0){
			oz(input);
		}
		// One command
		else if(strcmp(input, "1") == 0){
			oz(input);
		}
		// To print state machine
		else if(strcmp(input, "p") == 0){
			output();

		}
		// To change the transition of the current state
		else if(strcmp(input, "c") == 0){
			char num[2], state[2];
			scanf("%s %s", num, state);
			change(num, state);

		}   
		// To garbage 
		else if(strcmp(input, "g") == 0){
			garbage();
		} 

        // to delete
		else if (strcmp(input, "d") == 0) {
            char stateToDelete;
            scanf(" %c", &stateToDelete);

            // Check if the provided state is a valid state to delete
            if (stateToDelete >= 'A' && stateToDelete <= 'H') {
                delete_wanted(stateToDelete);
            } 
			// If the provided state is not apart of the matrix delete whatever is in garbage
			else{
                delete_garb();
            }
        }
		
					
	}

}