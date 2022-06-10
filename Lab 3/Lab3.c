#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Initalizing Stack and count variables
int stack[256];
int count = 0; 

//Creating push function to add values to stack
void push(int x) {
    stack[count] = x;
    count++;
}

//Creating pop function to remove values from stack
int pop() {
    int result = stack[count-1];
    count--;
    return result;
}

int main() {
    //Creating char array to save () to
    char parentheses[256] = {'(','(',')',')'};

    //Creating for loop that runs for as many ( there are
    for(int i = 0; i < strlen(parentheses); i++) {
        //Adds to stack if (
        if(parentheses[i] == '(') {
            push(parentheses[i]);
        }
        //Removes from stack if )
        else {
            pop(parentheses[i-1]);
        }
    }

    //prints out results once string has been exhausted
    if(count == 0) {
        printf("Balanced");
        
    }
    else {
        printf("Un-Balanced");
    }
}
