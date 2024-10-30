#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
int countnodes(struct node* head){
    int count =0;
    if(head==NULL){
        printf("the list is empty");
        return 0;
    }
    
    struct node* ptr =NULL;
    ptr=head;
    while(ptr!=NULL){
        printf("%d",ptr->data);
        printf("->");
        count++;  
        ptr=ptr->link;
        
    }
    printf("NULL\n");
    printf("there are %d nodes",count);

}

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

        temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 40;
    head->link->link->link = temp;
    temp->link = NULL;

      countnodes(head);
    

    // printf("%d %d\n", head->data, temp->data); // same as
    // printf("%d %d %d", head->data, head->link->data,head->link->link->data);
    free(head);
    free(temp);
}