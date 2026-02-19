//to find  sum of square of n numbers
//sqr(n)+sqrsum(n-1);

#include<stdio.h>
int sqr(int n,int a){
    if(a==0){
        return 1;
    }
    return n*sqr(n,a-1);
}

int sqrsum(int n){
    if(n==1){
        return 1;
    }
    return sqr(n,2)+sqrsum(n-1);
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Sum of squares of %d numbers: %d\n", n, sqrsum(n));
    return 0;


}