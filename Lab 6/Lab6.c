#include <stdio.h>
#include <stdlib.h>

//function prototypes
void denominationsUsed(int);
void minimumNumberOfCoinsUsed(int *, int *, int);

int main(void){
    int amount; // amount for which change has to be made
    int *minCoinUsed = (int *)calloc(amount, sizeof(int)); // allocate memory the size of amount
    int *lastCoinUsed = (int *)calloc(amount, sizeof(int)); 
    printf("Please enter the amount of change \n");
    scanf("%d", &amount);

    minimumNumberOfCoinsUsed(minCoinUsed, lastCoinUsed, amount);
    denominationsUsed(amount);
    //call the function minimumNumberOfCoinsUsed
    //call the function denominationsUsed
}

void minimumNumberOfCoinsUsed(int *minCoinUsed, int *lastCoinUsed, int amount){ //function to compute the minimum number of coins used
    int numOfDenominations = 3; //Creates variable for holding number of coins 
    int valueOfDenomination[3]= {1,10,25}; //hold coins being used
    int cents = 1; //counter up to amount
    
    while (cents <= amount) {  // runs until cents <= amount 
        int minCoins = cents; 
        int newCoin = valueOfDenomination[0]; //sets new coin to first denomination 
        int j = 1; //initalizes j counter 
        while (j < numOfDenominations) { //cycles through all of the coins
            if (valueOfDenomination[j] <= cents) {  //checks to see if denominatoin is greater than the cents value 
                if ((minCoinUsed[cents-valueOfDenomination[j]]+ 1) < minCoins) {  
                    minCoins = minCoinUsed[cents-valueOfDenomination[j]] + 1;
                    newCoin = valueOfDenomination[j]; //sets coin to the next denomination 
                }
            }
            j++;
        }
        minCoinUsed[cents] = minCoins;
        lastCoinUsed[amount] = newCoin;
        cents++;
    }
    printf("The minimum number of coins is :%d\n", minCoinUsed[amount]); //prints the min number of coins
}

void denominationsUsed(int amount){  // denominational break-up function
    int quarter,dime,nickle,penny; //initilizes variables for each coin
    quarter = amount/25; //divides the amount by quarters 
    amount = amount - (quarter*25); //subtracts the quarters from the amount 
    dime = amount/10; //divides the amount by dimes 
    amount = amount - (dime * 10); //subtracts the dimes from the amount
    nickle = amount/5; // divides the amount by nickles 
    amount = amount - (nickle * 5); //subtracts nickles from the amount
    penny = amount; //sets the remaining amount to penny 

    //prints out all the values of each coin 
    for (int i = 0; i < quarter; i++) {
        printf("%d + ", 25);
    }
    for (int i = 0; i < dime; i++) {
        printf("%d + ", 10);
    }
    for (int i = 0; i < nickle; i++) {
        printf("%d + ", 5);
    }
    if(penny > 0) {
        for (int i = 1; i < penny; i++) {
            printf("%d + ", 1);
        }
        printf("1");
    }
}