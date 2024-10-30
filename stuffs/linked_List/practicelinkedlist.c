#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
void create_node(struct node *head, int data)
{
    struct node *ptr, *temp;

    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

void print_nodes(struct node *head)
{
    struct node *temp = head;
    int count=0;
    while (temp!= NULL)
    {
        printf("%d", temp->data);
        printf("->");
        count++;
        temp = temp->link;
    }
    printf("NULL\n");
    printf("there are %d nodes",count);
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;
    create_node(head, 20);
    create_node(head, 30);
    create_node(head, 40);
    create_node(head, 50);
    create_node(head, 60);
    create_node(head, 70);
    create_node(head, 80);

    print_nodes(head);
}