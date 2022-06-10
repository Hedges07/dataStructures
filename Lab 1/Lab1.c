//Tyler Hedges Johnston
//105213585
//2021-05-17
//GCD Algorithm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int m, int n);
int minValue(int m,int n);

int main() {
    int n,m;
    for(int i = 0; i < 50; i++) {
        n = rand() %100;
        m = rand() % 100; 
        gcd(m+1,n+1);
    }
}

int gcd(int m,int n){
    int temp1,temp2,r = 0;
    int u1 = 1;
    int v1 = 0;
    int u0 = 0;
    int v0 = 1;
    int m1 = m;
    int n1 = n;
    int count = 1; 

    while (m1%n1 != 0){
        count++;
        temp1 =u0;
        temp2 = v0;
        u0 = u1-(m1%n1)*u0;
        v0 = v1-(m1%n1)*v0;
        u1 = temp1;
        v1 = temp2;

        r = m1%n1;
        m1 = n1;
        n1 = r;
    }

    int theo = 2*(ceil(log(minValue(m,n))/log(2))+1) + 1; // 2 ( ceil(lg n)) + 1
    //printf(" m = %d n = %d r = %d count = %d minValue = %d theoValue = %d\n", m,n,r, count, minValue(m,n), theo);  
    printf("%d*%d + %d*%d = %d, Count = %d, Theoretical Count = %d\n", u0,m,v0,n,n1,count,theo);
    

    return 0;
}

int minValue(int m,int n){
    if(m > n){
        return n;
    }
    else {
        return m; 
    }
}
