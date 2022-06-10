//includes
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//hashtable size. you might want to redefine this
#define SIZE 10000
//function prototypes
int isPrime(int);
int nextPrime(int);
int insertLinearProbe (int hashTable[], int, int key);
int insertQuadtraticProbe (int hashTable[], int, int key);
double numberOfProbes = 0; //counts the number of probes

int main(void){
    srand(time(NULL));
    printf("Please enter the load factor, a number between 0.1 - 0.9: ");
    // get load factor from user
    double loadFactor;
    scanf("%lf", &loadFactor);
    //printf("loadFactor = %lf\n", loadFactor);
    double theoretical = ((1+(1/(1-loadFactor)))/2);
    int listSize = (int) (SIZE/loadFactor);
    //printf("listSize = %d\n", listSize);
    // redefine size of hashtable
    int listSizePrime = nextPrime(listSize);
    printf("listSizePrime = %d\n", listSizePrime);
    // allocate storage for hashtable abd initialize all entries -1
    int *hashTable = (int*)calloc(listSizePrime, sizeof(int));
    //inilizes variables to -1
    for(int i = 0; i < listSizePrime; i++) {
                hashTable[i] = -1;
    }
    printf("Please select an option\n");
    printf("Press 1) Linear Probing\n");
    printf("Press 2) Quadratc Probing\n");
    int user;
    scanf("%d", &user);
    switch (user) { //select between either linear or quadratic probing
        case 1: {
            // generate random numbers and insert into hash table SIZE times,
            for(int i = 0; i < SIZE; i++) {
                int key = rand();
                numberOfProbes += insertLinearProbe(hashTable,listSizePrime, key); //Counts the number of probes
            }
            
            break;
        }
        case 2: {
            // generate random numbers and insert into hash table SIZE times,
            for(int i = 0; i < SIZE; i++) {
                int key = rand();
                numberOfProbes += insertQuadtraticProbe(hashTable,listSizePrime, key); //Counts the number of probes 
            }
        }
    }
    //print statistics
    printf("Theoretical = %lf\n", theoretical);
    printf("AVG Probes = %lf\n", numberOfProbes/SIZE);
    
}

// this function counts the number of probes made to insert key intio hashtable
int insertLinearProbe (int hashTable[], int listSizePrime, int key){
    int collisions = 0; //Counts the number of collisions
    int currentPostion = key % listSizePrime; //sets the current position
        while(hashTable[currentPostion] != -1) {
            collisions++;
            currentPostion++;
            if(currentPostion >= listSizePrime) {
                currentPostion -= listSizePrime;
            }
        }
        hashTable[currentPostion] = key;
        return collisions + 1; //returns the number collisions 
}

//quadratic probing and counts number of probes
int insertQuadtraticProbe (int hashTable[], int listSizePrime, int key){
    int collisions = 0; //Counts the number of collisions
    int increment = 0; //Counter for quadratic probing
    int currentPostion = key % listSizePrime; //sets the current position
        while(hashTable[currentPostion] != -1) {
            collisions++;
            currentPostion += 2*increment+1;
            increment++;
            if(currentPostion >= listSizePrime) {
                currentPostion -= listSizePrime;
            }
        }
        hashTable[currentPostion] = key;
        return collisions + 1; //returns the number collisions 
}

//this function checks if a given positive integer is a prime
int isPrime(int n) {
    if( n == 2 || n == 3 )
    return 1;

    if( n == 1 || n % 2 == 0 )
    return 0;

    for( int i = 3; i * i <= n; i += 2 )
    if( n % i == 0 )
    return 0;

    return 1;
}

// this function return the next prime after n
int nextPrime(int n){
    if(n%2 == 0) n++;
    for( ; !isPrime(n); n += 2 );
    return n;
}