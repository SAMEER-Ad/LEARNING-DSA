#include<stdio.h>

// Function declaration
int* add(int a, int b);

int main(){
    int* c;               // Pointer to hold the return value from 'add'
    c = add(10, 10);      // Call 'add' function
    printf("%d", *c);     // Dereference the pointer to print the result (Output: 20)
}

int* add(int a, int b) {
    static int c;         // 'static' ensures 'c' persists after the function returns
    c = a + b;            // Calculate the sum
    return &c;            // Return the address of 'c'
}

// Instead of using static, you can use malloc to allocate 
//memory dynamically on the heap, and this memory will 
//persist even after the function has returned.
//example:
#include<stdio.h>
#include<stdlib.h>  // For malloc and free

int* add(int a, int b);

int main() {
    int* c;
    c = add(10, 10);          // Call add function and store the returned pointer
    printf("%d\n", *c);       // Output the result (Output: 20)
    
    free(c);                  // Free the dynamically allocated memory
}

int* add(int a, int b) {
    int* c = (int*) malloc(sizeof(int));  // Allocate memory for an int on the heap
    if (c == NULL) {                      // Check if memory allocation was successful
        printf("Memory allocation failed\n");
        exit(1);                          // Exit if malloc fails
    }
    *c = a + b;   // c is a pointer that holds the memory address of the allocated memory  // Store the sum in the allocated memory                  
                                                
    return c;                             // Return the pointer to the allocated memory
}