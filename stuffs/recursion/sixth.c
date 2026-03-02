#include<stdio.h>

int print(int index,int * arr,int size){
    if(index==size){
        return 0;
    }
    printf("%d ",arr[index]);
    print(index+1,arr,size);

}

int main(){
    int arr[5]={1,2,3,4,5};
    print(0,arr,5);

}