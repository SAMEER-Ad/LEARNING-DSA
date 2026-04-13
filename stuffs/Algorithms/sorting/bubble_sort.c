#include<stdio.h>

void swap(int* a1, int* a2){
    int temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}
void Bubble_sort(int* arr,int n){
    for(int i =0;i<n-1;i++){
        for (int j = 0; j < n-1-i; j++)
        {
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
        
    }
}

int main(){
    int arr[5]={1,2,5,2,6};
    Bubble_sort(arr, 5);
    for(int i = 0; i < 5; i++)
        printf("%d ", arr[i]);

}