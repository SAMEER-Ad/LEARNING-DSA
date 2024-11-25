#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
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
int count_nodes(struct node *head)
{
    int count = 0;
    while (head != NULL)
    {
        head = head->link;
        count++;
    }
    return count;
}

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
struct node *delete_at_certain(struct node *head, int data, int count)
{

    if (data == 1)
    {
        struct node *temp = head;
        head = head->link;
        free(temp);
        temp = NULL;
        return head;
    }
    else if (data > count)
    {
        printf("sorry its not possible ");
        return head;
    }
    else if (data == count)
    {
        struct node *ptr1 = head;
        while (ptr1->link->link != NULL)
        {
            ptr1 = ptr1->link;
        }
        free(ptr1->link); // free function just needs memory address of a node to delete
        ptr1->link = NULL;
        return head;
    }
    else
    {
        struct node *previous = head;//can make better
        struct node *current = head;
        for (int i = 0; i < data - 1; i++)//can make better
        {
            previous = current;
            current = current->link;
        }
         previous->link = current->link;
        free(current);
        return head;
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
    at_last(head, 4);
    printf("enter a no of node to be deleted ");
    int data;
    scanf("%d", &data);
    int count;
      count = count_nodes(head);

    head = delete_at_certain(head, data, count);
    PrintNodes(head);
}