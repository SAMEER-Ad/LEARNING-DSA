#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node
{
    int data; // Data part of the node
    struct node *link; // Pointer to the next node in the list
};

// Function to add a node at the beginning of the linked list
struct node *add_beg(struct node *head, int d)
{
    // Allocate memory for the new node
    struct node *ptr = malloc(sizeof(struct node));
    ptr->link = head; // Initialize the link part to NULL
    ptr->data = d; // Set the data part of the new node

    // Make the new node's link point to the current head
   

    // Return the new node, which becomes the new head
    return ptr;
}

// Function to print all the nodes in the linked list
void print_nodes(struct node *head)
{
    struct node *temp = head; // Use a temporary pointer to traverse the list
    int count = 0; // Variable to count the number of nodes

    // Loop through the list until we reach the end (NULL)
    while (temp != NULL)
    {
        printf("%d", temp->data); // Print the data of the current node
        printf("->"); // Print the arrow to indicate a link to the next node
        count++; // Increment the node count
        temp = temp->link; // Move to the next node
    }

    // Print NULL to signify the end of the list
    printf("NULL\n");
    
    // Print the total number of nodes
    printf("There are %d nodes\n", count);
}

int main()
{
    // Creating the first node (head) of the list with data 10
    struct node *head = malloc(sizeof(struct node));
    head->link = NULL; // Initially, the link part is NULL (no next node)
    head->data = 10; // Set data of the first node to 10

    // Creating the second node with data 11
    struct node *ptr = malloc(sizeof(struct node));
    ptr->link = NULL; // No next node for now
    ptr->data = 11; // Set data to 11

    // Linking the first node (head) to the second node
    head->link = ptr;

    // Adding new nodes at the beginning of the list
    head = add_beg(head, 9); // Add a node with data 9
    head = add_beg(head, 8); // Add a node with data 8
    head = add_beg(head, 7); // Add a node with data 7

    // Print the entire linked list and the total number of nodes
    print_nodes(head);

    return 0;
}
