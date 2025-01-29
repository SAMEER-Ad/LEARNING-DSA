#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    int data;
    struct node *link;
};

// Function to insert a node at the end of the linked list
struct node *at_the_end(struct node *ptr, int data) {
    // Allocate memory for the new node
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;  // Set the data of the new node
    temp->link = NULL;  // Set the link of the new node to NULL
    ptr->link = temp;   // Link the last node to the new node
    return temp;        // Return the new node
}
void PrintList(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);  // Print the data of the current node
        current = current->link;       // Move to the next node
    }
    printf("\n");
}

int main() {
    // Create the head node
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    // Pointer to traverse the linked list
    struct node *ptr = head;

    // Insert a new node at the end
    ptr = at_the_end(ptr, 20);
    ptr = at_the_end(ptr, 30);
    ptr = at_the_end(ptr, 40);
    ptr = at_the_end(ptr, 50);
    PrintList(head);

    return 0;
}