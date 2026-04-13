#include<stdio.h>

static int count =0 ;
int search(int* arr,int data,int size){
   
    if(arr[size]==data){
        return size;
    }

    if(size==-1){
        return -1;
    }
    return search(arr,data,size-1);

}

int main(){
    int arr[5]={3,5,7,8,6};
    int el = search(arr,3,5-1);
    if(el != -1){
        printf("Element found at index: %d", el);
    } else {
        printf("Element not found");
    }

}