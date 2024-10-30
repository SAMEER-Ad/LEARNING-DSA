# include <stdio.h>

int main(){
    int arr[100]={1,3,5,9,11,13};
    int position =4;
    int data = 7;
    int size = 6;
    
    for (int i = size; i > position-1; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[position-1]= data;


    for (int  i = 0; i < size+1; i++)
    {
        printf("%d ",arr[i]);
    }
    
}