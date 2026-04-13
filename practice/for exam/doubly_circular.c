#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

// CORRECTED: Fixed add_atend to properly handle doubly circular structure
void add_atend(struct node* head, int data){
    struct node* temp= head;
    while(temp->next!=head){  // CORRECTED: Changed condition to loop until we reach the end (last->next == head)
        temp=temp->next;
    }
    struct node* newnode= malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newnode->prev=temp;
    newnode->data=data;
    temp->next=newnode;
    newnode->next=head;
    head->prev=newnode;  // CORRECTED: Update head->prev to complete the circular doubly structure
}

// CORRECTED: Added forward traversal function
void traverse_forward(struct node* head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    printf("Forward traversal: ");
    do{  // CORRECTED: Use do-while to include head node
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("\n");
}

// CORRECTED: Added backward traversal function to demonstrate doubly circular
void traverse_backward(struct node* head){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    struct node* temp = head->prev;  // Start from last node
    printf("Backward traversal: ");
    do{
        printf("%d ", temp->data);
        temp = temp->prev;
    }while(temp != head->prev);
    printf("\n");
}

// CORRECTED: Added insert at beginning function
struct node* insert_at_beginning(struct node* head, int data){
    struct node* newnode= malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("Memory allocation failed\n");
        return head;
    }
    newnode->data = data;
    newnode->next = head;
    newnode->prev = head->prev;
    head->prev->next = newnode;
    head->prev = newnode;
    return newnode;  // Return new head
}

// CORRECTED: Added delete function
void delete_node(struct node** head, int data){
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    
    struct node* temp = *head;
    do{
        if(temp->data == data){
            if(temp == *head){
                // Deleting head node
                if(temp->next == *head){
                    // Only one node
                    free(temp);
                    *head = NULL;
                    printf("Deleted node with data %d (was the only node)\n", data);
                    return;
                }
                *head = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            printf("Deleted node with data %d\n", data);
            free(temp);
            return;
        }
        temp = temp->next;
    }while(temp != *head);
    printf("Node with data %d not found\n", data);
}

// CORRECTED: Added free_list function to prevent memory leak
void free_list(struct node** head){
    if(*head == NULL) return;
    
    struct node* temp = *head;
    struct node* first = *head;
    while(temp->next != first){
        struct node* next_node = temp->next;
        free(temp);
        temp = next_node;
    }
    free(temp);  // Free the last node
    *head = NULL;
    printf("All nodes freed successfully\n");
}

int main(){
    // CORRECTED: Added malloc NULL check
    struct node* head= malloc(sizeof(struct node));
    if(head == NULL){
        printf("Memory allocation failed\n");
        return 1;
    }
    
    head->next=head;  // CORRECTED: Initialize to point to itself for circular structure
    head->prev=head;  // CORRECTED: Initialize to point to itself for circular structure
    head->data=5;
    
    add_atend(head,10);
    add_atend(head,20);
    add_atend(head,30);
    
    printf("\n=== Original List ===\n");
    traverse_forward(head);
    traverse_backward(head);
    
    // CORRECTED: Test insert at beginning
    printf("\n=== After inserting 1 at beginning ===\n");
    head = insert_at_beginning(head, 1);
    traverse_forward(head);
    traverse_backward(head);
    
    // CORRECTED: Test delete
    printf("\n=== After deleting node with data 20 ===\n");
    delete_node(&head, 20);
    traverse_forward(head);
    traverse_backward(head);
    
    // CORRECTED: Free all memory before exit
    printf("\n=== Cleanup ===\n");
    free_list(&head);
    
    return 0;
}
