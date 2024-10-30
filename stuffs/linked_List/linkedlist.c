#include <stdio.h>
#include <stdlib.h>
 // Define the node structure
    struct node {
        int data;
        struct node* next;
    };

int main() {
   

    // Create the head node
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;

    // Create the second node
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = 2;
    temp->next = NULL;
    head->next = temp;  // Link the head node to the second node

    // Create the third node
    struct node* temp2 = (struct node*)malloc(sizeof(struct node));
    temp2->data = 3;
    temp2->next = NULL;
    temp->next = temp2;  // Link the second node to the third node

    // Print the linked list
     printf("%d %d %d ",head->data,head->next->data,head->next->next->data);

    return 0;
}
