#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

// void At_End(struct node *head, int data)
// {
//     struct node *ptr = head;
//     for (ptr; ptr->link != NULL; ptr++)
//     {
//         ptr = ptr->link;
//     }
//     struct node *new = malloc(sizeof(struct node));
//     new->data = data;
//     new->link = NULL;
//     ptr->link = new;
// }
void At_End(struct node *head, int data)
{
    struct node *ptr = head;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }

    struct node *second = malloc(sizeof(struct node));
    second->data = data;
    second->link = NULL;

    ptr->link = second;
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
struct node* Delete_Last(struct node *head)
{

    if (head->link == NULL)
    { // check if there are only one node
        free(head);
        head = NULL;
    }
    else
    {
        struct node *ptr1=head;
        struct node *ptr2;
        while(ptr1->link!=NULL){
            ptr2= ptr1;
            ptr1= ptr1->link;
        }
        ptr2->link=NULL;
        free(ptr1);
        
    }

    //     struct node *ptr= head;

    // while(ptr->link!=NULL){
    //     ptr=ptr->link;
    // }
    // free(ptr);
    return head;
}
int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 0;
    head->link = NULL;
    At_End(head, 1);
    At_End(head, 2);
    At_End(head, 3);
    At_End(head, 4);
    
    head=Delete_Last(head);
    PrintNodes(head);
}