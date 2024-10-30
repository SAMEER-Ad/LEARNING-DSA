#include <stdio.h>
#include <stdlib.h>

// Define a structure named 'node'
struct node {
    int data;             // Data part of the node
    struct node* link;    // Pointer to the next node
};

int main() {
    // Create a pointer to a node and dynamically allocate memory for it
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));  // Allocate memory for one node

    // Check if memory allocation was successful
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return 1;  // Exit the program if memory allocation fails
    }

    // Assign data to the node and set the link to NULL
    newnode->data = 10;   // Store the value 10 in the data field
    newnode->link = NULL; // This is the only node for now, so its link is set to NULL

    // Print the data stored in the node
    printf("%d\n", newnode->data);  // Output: 10

    // Free the allocated memory
    free(newnode);

    return 0;
}
