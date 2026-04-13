#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* ptr;
};
void insert_at_end(struct node * head,int data){
    // CORRECTED: Added NULL check for head pointer
    if(head == NULL){
        printf("Error: head is NULL\n");
        return;
    }
    struct node* temp=head;
    while(temp->ptr!=NULL){
        temp = temp->ptr;

    }
    struct node* last= malloc(sizeof(struct node));
    last->ptr =NULL;
    last->data= data;
    temp->ptr=last;


}
struct node* insert_at_beginning(struct node* head,int data){
    struct node* temp = head;
    struct node* first= malloc(sizeof(struct node));
    first->data=data;
    first->ptr=temp;
    return first;

}
void traverse(struct node * head){
    struct node *temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->ptr;
        if(temp!=NULL){
            printf("->");
        }
    }
}
void delete_first(struct node** head){
    struct node *temp=*head;
    *head=temp->ptr;
    free(temp);
}
void delete_last(struct node* head){
    // CORRECTED: Added NULL check for head pointer
    if(head == NULL){
        printf("Error: head is NULL\n");
        return;
    }
    if(head->ptr == NULL){  // Only one node
        free(head);
        return;
    }
    struct node* temp =head;
    while(temp->ptr->ptr!=NULL){
        temp=temp->ptr;
    }
    free(temp->ptr);
    temp->ptr=NULL;

}
void delete_particular(struct node** head,int pos){
    // CORRECTED: Added NULL check for head and improved error handling
    if(pos < 1 || head == NULL || *head == NULL){
        printf("Error: Invalid position or empty list\n");
        return;
    }
    
    if(pos==1){
        // CORRECTED: Simply delete first node
        struct node* temp = *head;
        *head = temp->ptr;
        free(temp);
    }
    else{
        // CORRECTED: Removed variable shadowing - reuse temp from above
        struct node* temp = *head;
        // CORRECTED: Changed loop condition from <= to < (off-by-one error)
        for(int i=1; i < pos-1; i++){
            if(temp->ptr == NULL){
                printf("Error: Position out of range\n");
                return;
            }
            temp=temp->ptr;
        }
        // CORRECTED: Added bounds check before accessing temp->ptr
        if(temp->ptr == NULL){
            printf("Error: Position out of range\n");
            return;
        }
        struct node* todel = temp->ptr;
        temp->ptr=temp->ptr->ptr;
        free(todel);
    }

}

int main(){
    // CORRECTED: Initialize head with proper memory allocation check
    struct node *head = malloc(sizeof(struct node));
    if(head == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }
    head->data=10;
    head->ptr=NULL;
    
    // Insert elements at the end
    insert_at_end(head,20);
    insert_at_end(head,30);
    insert_at_end(head,40);
    insert_at_end(head,50);
    
    // Insert element at the beginning
    head = insert_at_beginning(head,5);
    printf("Original list: ");
    traverse(head);
    printf("\n\n");
    
    // Test delete_first
    printf("=== Testing delete_first() ===\n");
    delete_first(&head);
    printf("After delete_first (deleted 5): ");
    traverse(head);
    printf("\n\n");
    
    // Test delete_last
    printf("=== Testing delete_last() ===\n");
    delete_last(head);
    printf("After delete_last (deleted 50): ");
    traverse(head);
    printf("\n\n");
    
    // Test delete_particular at position 2
    printf("=== Testing delete_particular(pos=2) ===\n");
    delete_particular(&head, 2);
    printf("After delete_particular(2) (deleted 20): ");
    traverse(head);
    printf("\n\n");
    
    // Test delete_particular at position 1
    printf("=== Testing delete_particular(pos=1) ===\n");
    delete_particular(&head, 1);
    printf("After delete_particular(1) (deleted 10): ");
    traverse(head);
    printf("\n\n");
    
    // CORRECTED: Free remaining nodes before exit
    printf("=== Freeing remaining memory ===\n");
    while(head != NULL){
        struct node* temp = head;
        head = head->ptr;
        free(temp);
    }
    printf("Memory freed successfully\n");

    return 0;
}