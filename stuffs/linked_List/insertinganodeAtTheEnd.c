#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
int countnodes(struct node *head)
{
    int count = 0;
    if (head == NULL)
    {
        printf("the list is empty");
        return 0;
    }

    struct node *ptrr = NULL;
    ptrr = head;
    while (ptrr != NULL)
    {
        printf("%d", ptrr->data);
        printf("->");
        count++;
        ptrr = ptrr->link;
    }
    printf("NULL\n");
    printf("there are %d nodes", count);
}
void to_end(struct node *head,int data){
    struct node *ptr,*temp;
    ptr=head;
    temp=(struct node *)malloc(sizeof(struct node));

    temp->data=data;
    temp->link=NULL;

    while(ptr->link!=NULL){
        ptr=ptr->link;
    }
    ptr->link =temp;
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 20;
    temp->link = NULL;
    head->link = temp;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 30;
    temp->link = NULL;
    head->link->link = temp;
    to_end(head,40);
    to_end(head,50);
    to_end(head,60);
    to_end(head,70);

    countnodes(head);
}