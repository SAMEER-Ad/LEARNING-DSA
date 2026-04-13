#include<stdio.h>
#include<stdlib.h>

// CORRECTED: Changed return type from int to void (function doesn't return anything)
void swap(int *a, int *b){
    int temp;  // CORRECTED: Renamed 'c' to 'temp' for clarity
    temp = *a;
    *a = *b;
    *b = temp;
}

// CORRECTED: Renamed function from 'bulle' to 'bubble_sort' for clarity
void bubble_sort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                // CORRECTED: Pass addresses (&arr[j]) instead of values
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// CORRECTED: Added print_array function to display the array
void print_array(int arr[], int n){
    printf("Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// CORRECTED: Complete main function with comprehensive testing
int main(){
    // CORRECTED: Added error checking for array size
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    if(n <= 0){
        printf("Invalid array size\n");
        return 1;
    }
    
    // CORRECTED: Dynamically allocate array based on user input
    int *arr = (int *)malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }
    
    // CORRECTED: Take input from user
    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++){
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    // CORRECTED: Display unsorted array
    printf("\n=== Before Sorting ===\n");
    print_array(arr, n);
    
    // CORRECTED: Call bubble_sort with correct function name
    printf("\n=== Sorting in progress ===\n");
    bubble_sort(arr, n);
    
    // CORRECTED: Display sorted array
    printf("\n=== After Sorting ===\n");
    print_array(arr, n);
    
    // CORRECTED: Free allocated memory
    free(arr);
    printf("\nMemory freed successfully\n");
    
    return 0;
}