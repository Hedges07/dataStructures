#include <stdio.h>
#include <time.h>
#define maxN 10

int KnownF[maxN];

int recursive(int n) {
    if(n <=1) {
        return n;
    }
    return recursive(n-1) + recursive(n-2);
}
int iterative(int n) {
    int previous = 0, prePrevious = 0, current = 1;
    printf("%d ", previous);
    printf("%d ", current);
    for (int i = 0; i <= n-2; i++) {
        prePrevious = previous;
        previous = current;
        current = prePrevious + previous;
        printf("%d ", current);
    }
    return 0; 
}

int algorithm(int n) { 
    if (KnownF[n] != 0) 
        return KnownF[n];
    int t = n ;
    if (n < 0) 
        return 0;
    if (n > 1) t = recursive(n-1) + recursive(n-2);
        return KnownF[n] = t;
    return 0; 
}

int main() {
    //Sets the value of n
    printf("please enter n value: ");
    int n = 0;
    a:
    scanf("%d", &n);
    if(n < 0) {
        printf("The value of n cannot be negative ");
        goto a;
    }
    if(n > 46) {
        printf("Please pick a smaller n value to avoid overflow ");
        goto a; 
    }

    //begins the first clock and calls the recursive method
    clock_t start  = clock();
    printf("\n The recursive approach ");
    for(int i = 0; i <= n; i ++) {
        printf("%d ", recursive(i));
    }
    clock_t stop = clock();
    printf("Time = %f", (double)(stop-start)/100000);

    //begins the second clock and calls the iterative method
    clock_t start1  = clock();
    printf("\n The iterative approach ");
    iterative(n);
    clock_t stop1 = clock();
    printf("Time = %f", (double)(stop1-start1)/100000);

    //begins the third clock and calls the algorithm method
    clock_t start2  = clock();
    printf("\n The algorithm approach ");
    for(int i = 0; i <= n; i ++) {
        printf("%d ", algorithm(i));
    }
    clock_t stop2 = clock();
    printf("Time = %f", (double)(stop2-start2)/100000);
}
