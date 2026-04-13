#include<stdio.h>
#include<stdlib.h>

// CORRECTED: Removed global mid, fixed logic
int binary_search(int arr[], int start, int end, int key){
    if(start > end){  // CORRECTED: Changed from start>mid (was wrong)
        return -1;
    }
    int mid = (start + end) / 2;  // CORRECTED: Calculate mid here
    
    if(arr[mid] == key){
        return mid;
    }
    else if(arr[mid] > key){
        return binary_search(arr, start, mid - 1, key);
    }
    else{
        return binary_search(arr, mid + 1, end, key);
    }
}

int main(){
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    
    int *arr = (int *)malloc(size * sizeof(int));
    
    printf("Enter elements (sorted):\n");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    
    int key;
    printf("Search element: ");
    scanf("%d", &key);
    
    int result = binary_search(arr, 0, size - 1, key);
    
    if(result != -1){
        printf("Found at position: %d\n", result + 1);
    }
    else{
        printf("Not found\n");
    }
    
    free(arr);
    return 0;
}