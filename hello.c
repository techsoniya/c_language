#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Enumeration to represent different states of the DFA
enum State {
    START, STATE1, STATE2, STATE3, STATE4, INVALID
};

// Function prototypes
void transition(enum State* currentState, char input);
bool isAccepted(char str[]);

// Function to transition to the next state based on input character
void transition(enum State* currentState, char input) {
    switch (*currentState) {
        case START:
            *currentState = (input == 'a') ? STATE1 : INVALID;
            break;
        case STATE1:
            *currentState = (input == 'a') ? STATE2 : INVALID;
            break;
        case STATE2:
            *currentState = (input == 'b') ? STATE3 : INVALID;
            break;
        case STATE3:
            *currentState = (input == 'a') ? STATE4 : ((input == 'b') ? STATE3 : INVALID);
            break;
        case STATE4:
            *currentState = INVALID;
            break;
        default:
            *currentState = INVALID;
    }
}

// Function to check if the given string is accepted by the DFA
bool isAccepted(char str[]) {
    enum State currentState = START;
    int i = 0;
    while (str[i] != '\0' && currentState != INVALID) {
        transition(&currentState, str[i]);
        i++;
    }
    return (currentState == STATE3);
}

// Main function
int main() {
    char str[100];
    bool continueFlag = true;
    
    while (continueFlag) {
        printf("Enter the string to be checked by the DFA (or enter 'q' to quit): ");
        scanf("%s", str);
        if (strcmp(str, "q") == 0) {
            continueFlag = false;
        } else {
            if (isAccepted(str))
                printf("ACCEPTED\n");
            else
                printf("NOT ACCEPTED\n");
        }
    }
    
    return 0;
}
