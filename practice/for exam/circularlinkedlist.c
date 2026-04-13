#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* ptr;
};

void add_atbeg(struct node** head,int x){
    struct node *newNode= malloc(sizeof(struct node));
    newNode->ptr=*head;
    newNode->data=x;
    *head=newNode;
    struct node* temp = *head;
    while(temp->ptr!=*head){
        temp=temp->ptr;
    }
    temp->ptr=head;

}
int main(){
    struct node* head= malloc(sizeof(struct node));
    
}