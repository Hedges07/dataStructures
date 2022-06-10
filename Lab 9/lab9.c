//includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototypes
void buildHeap(int a[], int);
void heapSort(int a[], int);
void heapify (int a[], int, int);
void print(int a[], int);
void quickSort(int list[], int, int);
int partition(int list[], int, int);

int main(void){
    int listSize;
    // read in the size of list to be created and allocate store
    printf("Enter the size of the list: \n");
    scanf("%d", &listSize);
    int *list = (int *)calloc(listSize, sizeof(int));
    int *listB = (int *)calloc(listSize, sizeof(int));
    // populate array with random integer values
    srand(time(NULL));
    for (int i = 0; i < listSize; i++) { 
        list[i] = rand() % 100;
        listB[i] = list[i];
    }
    if(listSize <= 100) {
        printf("preSort: ");
        print(list,listSize);
    }
    
    clock_t begin1 = clock(); //starts the first clock
    heapSort(list,listSize); // build a heap
    clock_t end1 = clock(); //ends first clock
    double timeHeap = (double)((end1 - begin1) * 1000.0 / CLOCKS_PER_SEC); //calculates time for sorting
    clock_t begin2 = clock(); //begins second clock
    quickSort(listB,0,listSize-1); //runs quicksort
    clock_t end2 = clock(); //ends second clock
    double timeQuick = (double)((end2 - begin2) * 1000.0 / CLOCKS_PER_SEC); //calculates time for sorting
    if(listSize <= 100) {
        printf("postSort: ");
        print(list,listSize);
    }
    if(listSize > 100) {
        printf("Time of heapSort = %f\n", timeHeap);
        printf("Time of quickSort = %f\n", timeQuick);
    }
    
} // end of main

void buildHeap(int a[], int n){ // heapsort
    int i = n;
    while (i >= 1) {
        heapify(a,i,n);
        i--;
    }
} //end buildHeap

void heapSort(int a[], int n){
    int i = n;
    int temp;
    buildHeap(a,n);
    while (i > 0) {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a,0,i-1);
        i--;
    }
} //end heapSort

void heapify (int a[], int i, int j){ // heapify the elements in the index range i to j
    int k,temp;
    if (j < 2*i) {  
        return;
    }
    if (j == 2*i) {
        k = 2*i;
    }
    else if (j > 2*i) {
        if (a[2*i] >= a[2*i + 1]) {
            k = 2*i;
        }
        else {
            k = 2*i + 1;
        }
    }
    if (a[k] > a[i]) {
        temp = a[i];
        a[i] = a[k];
        a[k] = temp;
        heapify(a,k,j);
    }
} //end heapify

void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
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