#include<stdio.h>

int print(int index,int* arr){
    if(index==-1){
        return 0;

    }

    print(index-1,arr);
    printf("%d ",arr[index]);
    
}
int main(){
    int arr[5]={1,2,3,4,5};
    print(sizeof(arr)/sizeof(arr[0])-1,arr);//PASSES SIMPLY 4 AND ARRAY

}