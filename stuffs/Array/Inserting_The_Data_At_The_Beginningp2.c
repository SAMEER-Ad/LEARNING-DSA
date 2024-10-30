#include <stdio.h>

// Function to add an element at the beginning of the array
void add_beg(int arr[], int* n, int data) {
    // Shift all elements one position to the right to make space at the beginning
    for (int i = *n; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    // Insert the new element at the beginning (index 0)
    arr[0] = data;
    // Increase the number of elements in the array
    (*n)++;
}

int main() {
    int arr[100], n, data;

    // Input: Number of elements in the array
    printf("Enter the number of elements: \n");
    scanf("%d", &n);

    // Input: Array elements from the user
    printf("Enter elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input: The data to be inserted at the beginning
    printf("Enter the data to be inserted: \n");
    scanf("%d", &data);

    // Call the function to add the element at the beginning
    add_beg(arr, &n, data);
    add_beg(arr, &n, data);  // Inserting the same data multiple times
    add_beg(arr, &n, data);

    // Output: Print the updated array after insertion
    printf("Updated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
