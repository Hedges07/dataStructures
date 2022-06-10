#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//function prototypes
void quickSort(int list[], int, int);
void insertionSort(int list[], int);
int partition(int list[], int, int);

//Creates variables for sort times
double timeInsertion = 0.0;
double timeQuick = 0.0;

int main(void){
    srand(time(NULL)); //creates random number varaible
    printf("Please enter the number of random integers: \n");
    int listSize; //gets size of list from user
    scanf("%d", &listSize);
    int a[listSize]; //creates two identical lists to be sorted
    int b[listSize];
    for(int i = 0; i < listSize; i++) { //creates listSize of random numbers
        a[i] = rand() % 100 - 50;
        b[i] = a[i];
    }
    clock_t begin1 = clock(); //starts the first clock
    insertionSort(a,listSize); //runs insertion sort on array a[]
    clock_t end1 = clock(); //ends first clock
    timeInsertion += (double)((end1 - begin1) / CLOCKS_PER_SEC); //calculates time for sorting
    clock_t begin2 = clock(); //begins second clock
    quickSort(b,0, listSize-1); //runs quicksort 
    clock_t end2 = clock(); //ends second clock
    timeQuick += (double)((end2 - begin2) / CLOCKS_PER_SEC); //calculates time for sorting
    if(listSize < 30) { //for lists less than 30, show the list being sorted, if bigger only show the run time
        printf("Insertion Sort: ");
        for(int i = 0; i < listSize; i++) { //prints out array a[]
            printf("%d ", a[i]);
        }
        printf("\n");
        printf("Quick Sort: ");
        for(int i = 0; i < listSize; i++) { //prints out array b[]
            printf("%d ", b[i]);
        }
    }
    else {
        printf("Insertion Sort Time: %f\n", timeInsertion); //prints out both run times 
        printf("Quick Sort Time: %f\n", timeQuick);
    }
}


void insertionSort(int a[], int listSize) {
    int j,temp; 
    for(int i = 1; i <listSize; i++) { 
        temp = a[i]; //save value of a[i]
        j = i - 1;
        while (j >= 0 && a[j] > temp) {  //search for location of a[i]
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

void quickSort(int a[], int p, int q) {
    if(p < q) {
        int r = partition(a,p,q); //calls the partition()
        quickSort(a,p,r); //recursively calls quicksort
        quickSort(a,r+1,q);
    }
}

int partition(int a[], int p, int q){
    int i = p-1;
    int j = q+1;
    int x = a[p];
    int flag = 1;
    int temp;

    while(flag){
        // move left pointer
        do i = i+1;
        while (a[i]<x);
        //move right pointer
        do j = j-1;
        while (a[j]>x);
        if (i<j){
            //exchange a[1] and a[j]
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else flag = 0;
    }
    return j;
}