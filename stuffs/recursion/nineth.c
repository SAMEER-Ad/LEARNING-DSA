#include<stdio.h>

int summ;
int sum(int* arr,int size){
    if(size==-1){
        return 0;
    }
    summ+=sum(arr,size-1);
    return arr[size];

}

int main(){
    int arr[5]={3,4,5,8,2};
    sum(arr,5);
    printf("%d ",summ);

}