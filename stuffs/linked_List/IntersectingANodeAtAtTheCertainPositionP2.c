#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct node
{
    int data;
    struct node *link;
};

// Function to insert a node at a specific position in the linked list
struct node *at_certain(int n, int data, struct node *head)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;

    // Edge case: if position n is 1, insert at the beginning
    if (n == 1)
    {
        newNode->link = head; // New node points to current head
        return newNode;       // Return new node as the new head
    }

    struct node *ptr = head;

    // Traverse to the (n-1)th node
    for (int i = 1; i < n - 1; i++)
    {
        // If the position is out of bounds (larger than the list size)
        if (ptr == NULL)
        {
            printf("Position out of bounds\n");
            free(newNode); // Free the allocated memory for the new node
            return head;   // Return unchanged head
        }
        ptr = ptr->link;
    }

    // Insert new node at the specified position
    newNode->link = ptr->link; // Link new node to the next node
    ptr->link = newNode;       // Link previous node to the new node

    return head; // Return the head (unchanged)
}









// Function to print the linked list and count the nodes
void print_list(struct node *head)
{
    struct node *ptr = head;
    int count = 0;

    while (ptr != NULL)
    {
        count++;
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\nThere are %d number of nodes\n", count);
}

int main()
{
    // Creating the initial linked list: 1 -> 2 -> 3
    struct node *head = malloc(sizeof(struct node));
    head->data = 1;
    head->link = NULL;

    struct node *ptr1 = malloc(sizeof(struct node));
    ptr1->data = 2;
    ptr1->link = NULL;
    head->link = ptr1;

    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2->data = 3;
    ptr2->link = NULL;
    ptr1->link = ptr2;

    int n, data;

    printf("Enter a position where you want to insert a new node : ");
    scanf("%d", &n);

    printf("Enter the data you want to insert: ");
    scanf("%d", &data);

    // Call the function to insert the new node and update head
    head = at_certain(n, data, head);
    print_list(head); 

    
}
