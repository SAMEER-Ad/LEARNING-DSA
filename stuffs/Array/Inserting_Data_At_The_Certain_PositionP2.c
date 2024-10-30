
#include <stdio.h>
#include <stdlib.h>

// Function to insert data at a certain position in the array
int* at_certain(int size, int arr[], int data, int position);

// Function to print elements of the array
void Print_Elements(int* arr2, int size);

int main()
{
    int size;
    
    // Input number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    
    // Original array of size entered by the user
    int arr[size];
    
    // Input the array elements
    printf("Enter array elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int data, position;
    
    // Input the data to insert and its position
    printf("Enter data to insert: ");
    scanf("%d", &data);
    printf("Enter position to insert the data: ");
    scanf("%d", &position);

    // Call function to insert the data and get the new array
    int *arr2 = at_certain(size, arr, data, position);
    
    // Print the updated array
    Print_Elements(arr2, size);
    
    // Free dynamically allocated memory
    free(arr2);

    return 0;
}






// Function to insert an element at a specific position in the array
int* at_certain(int size, int arr[], int data, int position)
{
    
    // Dynamically allocate memory for the new array with one extra element
    int *arr2 = (int*)malloc((size + 1) * sizeof(int));

    // Copy elements before the insertion position
    for (int i = 0; i < position - 1; i++) {
        arr2[i] = arr[i];
    }

    // Insert the new data at the specified position
    arr2[position - 1] = data;

    // Copy the remaining elements after the insertion position
    for (int i = position; i < size + 1; i++) {
        arr2[i] = arr[i - 1];
    }

    // Return the new array with the inserted data
    return arr2;
}

// Function to print elements of the array
void Print_Elements(int* arr2, int size)
{
    printf("Array after insertion: ");
    
    // Print each element of the new array
    for (int i = 0; i < size + 1; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
}




