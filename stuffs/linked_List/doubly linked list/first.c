#include<stdio.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;

};

int main(){
    struct node* head = malloc(sizeof(struct node));
    head->next=NULL;
    head->prev=NULL;
    head->data = 10;
    
}