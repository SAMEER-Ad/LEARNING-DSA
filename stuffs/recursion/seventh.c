#include<stdio.h>

int print(int index,int* arr,int size){
    if(index==size){
        return 0;

    }
    print(index+1,arr,size);
    printf("%d ",arr[index]);
}
int main(){
    int arr[5]={1,2,3,4,5};
    print(0,arr,5);

}