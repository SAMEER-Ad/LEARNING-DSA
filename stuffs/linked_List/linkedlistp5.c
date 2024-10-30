#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 20;
    head->link = temp;
    temp->link = NULL;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 30;
    head->link->link = temp;
    temp->link = NULL;


    

    printf("%d %d\n", head->data, temp->data); // same as
    printf("%d %d %d", head->data, head->link->data,head->link->link->data);
    free(head);
    free(temp);
}