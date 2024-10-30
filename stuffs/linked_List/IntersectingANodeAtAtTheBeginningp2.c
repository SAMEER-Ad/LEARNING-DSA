#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

// No need to return anything now
void add_beg(struct node **head, int d)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->link = NULL;
    ptr->data = d;

    // Link the new node to the old head
    ptr->link = *head;

    // Update the head pointer to the new node
    *head = ptr;
}

void print_nodes(struct node *head)
{
    struct node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        printf("->");
        count++;
        temp = temp->link;
    }
    printf("NULL\n");
    printf("There are %d nodes\n", count);
}

int main()
{
    // Create the first node (head)
    struct node *head = malloc(sizeof(struct node));
    head->link = NULL;
    head->data = 10;

    // Create the second node and link it to the head
    struct node *ptr = malloc(sizeof(struct node));
    ptr->link = NULL;
    ptr->data = 11;
    head->link = ptr;

    // Adding new nodes at the beginning
    add_beg(&head, 30);
    add_beg(&head, 9);
    add_beg(&head, 8);
    add_beg(&head, 7);

    // Print the linked list and count the nodes
    print_nodes(head);

    return 0;
}
