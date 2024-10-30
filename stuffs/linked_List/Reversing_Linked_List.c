#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};


struct node* Reverse(struct node *head)
{
    struct node *temp = NULL;
    struct node *temp2 = NULL;
    while (head != NULL)
    {
        temp2 = head->link;
        head->link = temp;
        temp = head;
        head = temp;
    }
    head= temp;
    return head;

}

int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 0;
    head->link = NULL;
    
    
    struct node *second = malloc(sizeof(struct node));
    second->data = 1;
    second->link = NULL;
    head->link=second;
    
    struct node *third = malloc(sizeof(struct node));
    third->data = 2;
    third->link = NULL;

    second->link=third;
    
        struct node *fourth = malloc(sizeof(struct node));
    fourth->data = 3;
    fourth->link = NULL;

    third->link= fourth;

    head=Reverse(head);
    while (head!=NULL)
    {
        printf("%d ",head->data);
        head= head->link;
    }
    
}
