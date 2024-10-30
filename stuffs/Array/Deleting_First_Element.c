# include<stdio.h>

int main(){
    int arr[]={1,2,3,4,5};
    for (int i = 0; i < 5; i++)
    {
        arr[i]=arr[i+1];
    }
    for (int i = 0; i < 4; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("hellow world!");
    
    
}