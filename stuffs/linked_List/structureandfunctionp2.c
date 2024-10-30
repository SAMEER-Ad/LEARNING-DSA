#include <stdio.h>
#include <stdlib.h>

// Define a structure named 'point'
struct point {
    int x;
    int y;
};

// Function to create a point and return a pointer to it
struct point *fun(int a, int b) {
    struct point *ptr = (struct point *)malloc(sizeof(struct point)); // Allocate memory
    ptr->x = a;       // Set the x value
    ptr->y = b + 5;   // Set the y value (add 5)
    return ptr;      // Return the pointer to the structure
}

// Function to print the values of a point
void print(struct point *ptr) {
    printf("%d %d\n", ptr->x, ptr->y); // Print x and y
}

int main() {
    struct point *ptr1, *ptr2; // Declare two pointers to point structures

    // Call 'fun' to create points and assign them to ptr1 and ptr2
    ptr1 = fun(2, 3); // ptr1 points to a struct with x = 2, y = 8
    ptr2 = fun(6, 9); // ptr2 points to a struct with x = 6, y = 14

    // Print the points
    print(ptr1); // Output: 2 8
    print(ptr2); // Output: 6 14

    // Free the allocated memory
    free(ptr1); // Free memory for ptr1
    free(ptr2); // Free memory for ptr2

    return 0; // End of the program
}
