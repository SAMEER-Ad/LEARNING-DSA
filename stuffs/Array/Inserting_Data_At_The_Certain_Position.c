# include <stdio.h>

int main(){
    int arr[9]={1,3,5,7,9,11,13,15,17};
    int position = 5;//between 7 and 9
    int data = 10;
    //since array is full so we have to create new array;
    int arr2[10];
    for (int i = 0; i < position-1; i++)
    {
        arr2[i]=arr[i];
    }
    arr2[position-1]=data;

    //to find no od data
    int size_of_array=sizeof(arr2)/sizeof(arr2[0]);
    for (int i = position; i < size_of_array+1; i++)
    {
        arr2[i]=arr[i-1];
    }
    for (int i = 0; i < size_of_array; i++)
    {
        printf("%d ",arr2[i]);
    }
    
    
    

}