#include <stdio.h>
#include <stdlib.h>

int main() {
    //Initializing all array variables
    int random[15];
    int start[10];
    int end[10]; 
    int maxSum[10];

    //Starting for-loop used for 10 Randomly generated sequences
    for(int c = 0; c < 10; c++) {
        //Creates 15 random integers and saves them into random[]
        for(int i = 0; i < 15; i++) {
            random[i] = rand()% 100-50;
        }

        //Initialize all variables to proper starting values
        start[c] = -1; 
        end[c] = -1;
        maxSum[c] = 0;
        int i = 0;
        int j = 0;
        int sum = 0;

        int n = 15; // Number of element in the sequence

        while(j <= n && i <= j) {
            sum = sum + random[j]; 
            if(sum > maxSum[c]) {
                maxSum[c] = sum;
                start[c] = i;   //Reset I and J 
                end[c] = j; 
            }
            if(sum < 0) {
                i = j + 1;  //Increase the value of I 
                sum = 0;
            }
            j++;
        }
    }
    //Prints out maxSum values for all 10 Sequences 
    for(int i = 0; i < 10; i++) {
        printf("Start = %d, End = %d, maxSum = %d\n", start[i],end[i],maxSum[i]);
    }
}