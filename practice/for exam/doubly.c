#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

void add_atend(struct node* head, int data){
    struct node* temp= head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    struct node* newnode= malloc(sizeof(struct node));
    newnode->prev=temp;
    newnode->data=data;
    temp->next=newnode;
    newnode->next=NULL;
}

int main(){
    struct node* head= malloc(sizeof(struct node));
    head->next=NULL;
    head->prev=NULL;
    head->data=5;
    add_atend(head,10);
    add_atend(head,20);
    add_atend(head,30);
        
        struct node* temp = head;
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        
        return 0;
}
