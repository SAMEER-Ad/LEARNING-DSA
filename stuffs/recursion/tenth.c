#include<stdio.h>

int sum(int* arr, int size){
    if(size == -1){
        return 0;
    }
    return arr[size] + sum(arr, size-1);
}

int main(){
    int arr[5]={3,4,5,8,2};
    int summ = sum(arr,5-1);
    printf("%d ",summ);

}