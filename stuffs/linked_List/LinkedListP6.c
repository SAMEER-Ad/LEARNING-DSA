#include<stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

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

struct node* Add_at_end(struct node* ptr,int data){
     
    struct node *temp= malloc(sizeof(struct node));
    temp->data = data;
    temp->link= NULL;

    ptr->link = temp;
    return temp;


}

int main(){
    
    struct node *head = malloc(sizeof(struct node));
    head->data=10;
    head->link =NULL;


    struct node *ptr= head;
    ptr = Add_at_end(ptr,20);
    ptr = Add_at_end(ptr,30);
    ptr = Add_at_end(ptr,40);
    print_nodes(head);
         
}