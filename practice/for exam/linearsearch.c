#include<stdio.h>
#include<stdlib.h>

// CORRECTED: Return -1 if not found, else return position
int search(int arr[], int index, int size, int n){
    if(index == size){
        return -1;  // CORRECTED: Not found
    }
    if(arr[index] == n){
        return index;  // CORRECTED: Return position
    }
    return search(arr, index + 1, size, n);
}

int main(){
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    
    int *arr = (int *)malloc(size * sizeof(int));
    
    printf("Enter elements:\n");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    
    int n;
    printf("Search element: ");
    scanf("%d", &n);
    
    int result = search(arr, 0, size, n);
    
    if(result != -1){
        printf("Found at position: %d\n", result + 1);
    }
    else{
        printf("Not found\n");
    }
    
    free(arr);
    return 0;
}