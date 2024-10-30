#include <stdio.h>

struct node {
    int data;
    struct node *link;
};

int main() {
    // Create two nodes on the stack
    struct node node1, node2;

    // Initialize the first node
    node1.data = 10;
    node1.link = &node2;  // Link the first node to the second node

    // Initialize the second node
    node2.data = 20;
    node2.link = NULL;    // End of the list

    // Traverse and print the linked list
    struct node *ptr = &node1;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");

    // Since memory is on the stack, there's no need to free it
    return 0;
}