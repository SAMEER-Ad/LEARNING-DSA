#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
void at_last(struct node *head, int data)
{
    struct node *ptr = head;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link = NULL;
    ptr->link = newnode;
}
void PrintNodes(struct node *head)
{
    int count = 0;
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->link;
        count++;
    }
    printf("\n");
    printf("there are %d nodes", count);
}
void Delete_All(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        struct node* ptr1=ptr;
        ptr = ptr->link;
        free(ptr1);
        ptr1 = NULL;
    }
}

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 0;
    head->link = NULL;

    at_last(head, 1);
    at_last(head, 2);
    at_last(head, 3);
    PrintNodes(head);
    Delete_All(head);
    PrintNodes(head);
}